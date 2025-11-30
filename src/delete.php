<?php
// delete.php
require __DIR__.'/db.php';

$id = isset($_GET['id']) ? (int)$_GET['id'] : 0;
if (!$id) { http_response_code(400); echo json_encode(['error'=>'no id']); exit; }
$pdo->prepare("DELETE FROM items WHERE id = :id")->execute([':id'=>$id]);
echo json_encode(['success'=>true]);
