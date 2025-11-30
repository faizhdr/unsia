<?php
// create.php
require __DIR__.'/db.php';
require __DIR__.'/crypto.php';
$config = require __DIR__.'/config.php';
$key = $config['secret_key'];

// Expect JSON input
$input = json_decode(file_get_contents('php://input'), true);
$name = $input['name'] ?? '';
$description = $input['description'] ?? '';
$price = $input['price'] ?? 0.0;

$nonce = rand_nonce(16); // 16 bytes
$name_enc = hkdf_stream_xor($key, $nonce, $name); // binary
$desc_enc = hkdf_stream_xor($key, $nonce, $description);

$stmt = $pdo->prepare("INSERT INTO items (nonce, name_enc, description_enc, price) VALUES (:nonce, :name, :desc, :price)");
$stmt->execute([
    ':nonce' => b64($nonce),
    ':name' => b64($name_enc),
    ':desc' => b64($desc_enc),
    ':price' => $price,
]);

echo json_encode(['success' => true, 'id' => $pdo->lastInsertId()]);
