mkdir -p /var/run/mysqld
chown mysql:mysql /var/run/mysqld
chmod 755 /var/run/mysqld

service mysql start

mysql -u root -e "CREATE DATABASE IF NOT EXISTS wordpress;"
mysql -u root -e "CREATE USER IF NOT EXISTS 'kkleinsc'@'localhost' IDENTIFIED BY 'kkleinsc';"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'kkleinsc'@'localhost' IDENTIFIED BY 'kkleinsc';"
mysql -u root -e "FLUSH PRIVILEGES;"

