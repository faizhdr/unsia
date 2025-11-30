-- db_dump.sql
CREATE DATABASE IF NOT EXISTS `crud_xor` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE `crud_xor`;

CREATE TABLE `items` (
  `id` int unsigned NOT NULL AUTO_INCREMENT,
  `nonce` varchar(64) NOT NULL, -- base64(nonce)
  `name_enc` text NOT NULL,     -- base64(encrypted_name)
  `description_enc` text,
  `price` decimal(12,2) DEFAULT 0.00,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- contoh data (optional)
INSERT INTO items (nonce, name_enc, description_enc, price) VALUES
('','', '', 0.00);
