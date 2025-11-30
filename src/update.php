<?php
// update.php
require __DIR__.'/db.php';
require __DIR__.'/crypto.php';
$config = require __DIR__.'/config.php';
$key = $config['secret_key'];

$input = json_decode(file_get_contents('php://input'), true);
$id = (int)($input['id'] ?? 0);
if (!$id) { http_response_code(400); echo json_encode(['error'=>'no id']); exit; }

$stmt = $pdo->prepare("SELECT nonce FROM items WHERE id = :id");
$stmt->execute([':id'=>$id]);
$row = $stmt->fetch();
if (!$row) { http_response_code(404); echo json_encode(['error'=>'not found']); exit; }

$nonce = ub64($row['nonce']);
$name = $input['name'] ?? null;
$description = $input['description'] ?? null;
$price = $input['price'] ?? null;

$updates = [];
$params = [':id'=>$id];
if ($name !== null) {
    $updates[] = "name_enc = :name";
    $params[':name'] = b64(hkdf_stream_xor($key, $nonce, $name));
}
if ($description !== null) {
    $updates[] = "description_enc = :desc";
    $params[':desc'] = b64(hkdf_stream_xor($key, $nonce, $description));
}
if ($price !== null) {
    $updates[] = "price = :price";
    $params[':price'] = $price;
}
if (empty($updates)) { echo json_encode(['success'=>false,'msg'=>'nothing to update']); exit; }

$sql = "UPDATE items SET " . implode(', ', $updates) . " WHERE id = :id";
$pdo->prepare($sql)->execute($params);
echo json_encode(['success'=>true]);
