#db_name = Database Name
#db_user = User
#db_pwd = User Password

echo "CREATE DATABASE IF NOT EXISTS $db_name ;" > mdb.sql
echo "CREATE USER IF NOT EXISTS '$db_user'@'%' IDENTIFIED BY '$db_pwd' ;" >> mdb.sql
echo "GRANT ALL PRIVILEGES ON $db_name.* TO '$db_user'@'%' ;" >> mdb.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345' ;" >> mdb.sql
echo "FLUSH PRIVILEGES;" >> mdb.sql

mysql < mdb.sql