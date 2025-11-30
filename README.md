# TUGAS 1 Kriptografi dan Steganografi

Project ini adalah contoh implementasi **CRUD API sederhana menggunakan PHP Native + MySQL**, dengan fitur tambahan berupa **enkripsi XOR Stream Cipher** berbasis **HMAC-SHA256 + Nonce**.

Setiap field teks (name & description) disimpan dalam bentuk **ciphertext (Base64)** di database, dan akan otomatis didekripsi saat membaca data.

---

## 🚀 Fitur Utama
- ✔ CRUD: Create, Read, Update, Delete  
- ✔ Enkripsi XOR Stream Cipher (HMAC-SHA256 keystream)  
- ✔ Nonce unik per record  
- ✔ MySQL + PDO  
- ✔ API REST sederhana  
- ✔ Dapat diakses menggunakan curl / Postman  

---

## 📂 Struktur Folder

project/
├─ db_dump.sql
└─ src/
├─ config.php
├─ db.php
├─ crypto.php
├─ index.php
├─ create.php
├─ read.php
├─ update.php
└─ delete.php

---

## ⚙️ Persyaratan Sistem

- PHP 7.4 / 8.x
- MySQL / MariaDB
- Terminal (CMD, PowerShell, Linux Terminal)

---

# 🛠️ INSTALASI & CARA MENJALANKAN PROJECT

## 1️⃣ Clone atau Download Project

```bash
    git clone -b tugas-curl-project --single-branch https://github.com/faizhdr/unsia.git
    cd unsia/
```
## 2️⃣ Import Database

```bash
    mysql -u root -p < db_dump.sql
```
Pastikan database `crud_xor` sudah muncul:
```bash
    mysql -u root -p
    SHOW DATABASES;
    USE crud_xor;
    SHOW TABLES;
```

---

## 3️⃣ Konfigurasi Koneksi Database

**note: jika mysql tidak menggunakan password skip step ini**

Edit file:
src/config.php

Isi sesuai kebutuhan:

```php
return [
    'db' => [
        'host' => '127.0.0.1',
        'dbname' => 'crud_xor',
        'user' => 'root',
        'pass' => '',
        'charset' => 'utf8mb4',
    ],
    'secret_key' => 'isi_dengan_kunci_rahasia_min_32_byte'
];
```

---

## 4️⃣ Jalankan Server PHP

Masuk ke folder src/:
```bash
    cd src
    php -S 127.0.0.1:8000
```

Jika berhasil, terminal akan menampilkan:
```bash
PHP Development Server started...
Listening on http://127.0.0.1:8000
```

Jangan tutup terminal ini.

---

## 5️⃣ Testing Menggunakan curl

Buka terminal baru dan jalankan contoh perintah berikut:

➤ READ (GET) — Ambil Semua Data
```bash
    curl http://127.0.0.1:8000/read
```

➤ CREATE (POST)
```bash
    curl -X POST http://127.0.0.1:8000/create \
  -H "Content-Type: application/json" \
  -d '{"name":"Apel","description":"Buah merah","price":12000}'
```

➤ READ SATU DATA
```bash
    curl http://127.0.0.1:8000/read?id=1
```

➤ UPDATE (PUT)
```bash
    curl -X PUT http://127.0.0.1:8000/update \
  -H "Content-Type: application/json" \
  -d '{"id":1,"price":15000}'
```

➤ DELETE
```bash
    curl http://127.0.0.1:8000/delete?id=1
```

---