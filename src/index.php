<?php
// index.php
$path = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$script = basename(__DIR__) . '/' . basename($path);
switch ($path) {
    case '/create': require __DIR__ . '/create.php'; break;
    case '/read': require __DIR__ . '/read.php'; break;
    case '/update': require __DIR__ . '/update.php'; break;
    case '/delete': require __DIR__ . '/delete.php'; break;
    default:
        echo "Simple CRUD XOR API\n";
        echo "POST /create (json: name, description, price)\n";
        echo "GET /read or /read?id={id}\n";
        echo "PUT /update (json: id, name?, description?, price?)\n";
        echo "GET /delete?id={id}\n";
}
