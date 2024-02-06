CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'kkleinsc'@'localhost' IDENTIFIED BY 'kkleinsc';
GRANT ALL PRIVILEGES ON wordpress.* TO 'kkleinsc'@'localhost';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'kkleinsc';
