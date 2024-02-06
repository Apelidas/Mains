CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'kkleinsc'@'%' IDENTIFIED BY 'kkleinsc';
GRANT ALL PRIVILEGES ON wordpress.* TO 'kkleinsc'@'%';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'kkleinsc';
