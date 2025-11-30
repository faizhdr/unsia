<?php
// crypto.php
// Implements a keystream generator using HMAC-SHA256(key, nonce||counter)
// then XORs plaintext bytes with keystream bytes.
function hkdf_stream_xor(string $key, string $nonce, string $data): string {
    $keystream = generate_keystream($key, $nonce, strlen($data));
    return $data ^ $keystream; // PHP supports ^ on strings (XOR bytes)
}

function generate_keystream(string $key, string $nonce, int $length): string {
    $output = '';
    $counter = 0;
    while (strlen($output) < $length) {
        // pack counter as 4-byte big-endian
        $ctr = pack('N', $counter);
        // HMAC-SHA256 (binary)
        $output .= hash_hmac('sha256', $nonce . $ctr, $key, true);
        $counter++;
    }
    return substr($output, 0, $length);
}

// Helper: generate random nonce (binary)
function rand_nonce(int $len = 16): string {
    return random_bytes($len);
}

// Helper: base64 encode for storage/transfer
function b64(string $s): string { return base64_encode($s); }
function ub64(string $s): string { return base64_decode($s); }
