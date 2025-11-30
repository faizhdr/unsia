<?php
// read.php
require __DIR__.'/db.php';
require __DIR__.'/crypto.php';
$config = require __DIR__.'/config.php';
$key = $config['secret_key'];

$id = isset($_GET['id']) ? (int)$_GET['id'] : null;
if ($id) {
    $stmt = $pdo->prepare("SELECT * FROM items WHERE id = :id");
    $stmt->execute([':id' => $id]);
    $row = $stmt->fetch();
    if (!$row) { http_response_code(404); echo json_encode(['error'=>'Not found']); exit; }

    $nonce = ub64($row['nonce']);
    $name = hkdf_stream_xor($key, $nonce, ub64($row['name_enc']));
    $desc = hkdf_stream_xor($key, $nonce, ub64($row['description_enc']));

    echo json_encode([
        'id'=>$row['id'],
        'name'=>$name,
        'description'=>$desc,
        'price'=>$row['price'],
        'created_at'=>$row['created_at']
    ]);
    exit;
}

// list all
$stmt = $pdo->query("SELECT id, nonce, name_enc, description_enc, price, created_at FROM items ORDER BY id DESC");
$rows = [];
while ($r = $stmt->fetch()) {
    $nonce = ub64($r['nonce']);
    $rows[] = [
        'id' => $r['id'],
        'name' => hkdf_stream_xor($key, $nonce, ub64($r['name_enc'])),
        'description' => hkdf_stream_xor($key, $nonce, ub64($r['description_enc'])),
        'price' => $r['price'],
        'created_at' => $r['created_at'],
    ];
}
echo json_encode($rows);
