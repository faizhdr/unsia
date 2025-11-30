<?php
// config.php
return [
    'db' => [
        'host' => '127.0.0.1',
        'dbname' => 'crud_xor',
        'user' => 'root',
        'pass' => '',
        'charset' => 'utf8mb4',
    ],
    // Kunci simetris (harus disimpan aman; untuk demo di sini hardcode)
    // Gunakan minimal 32 byte secret (base64 atau raw). Jangan commit kunci asli di repo publik.
    'secret_key' => 'replace_this_with_a_very_secret_key_of_32_bytes!!'
];
