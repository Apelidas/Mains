FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server

EXPOSE 3306

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /

RUN chmod +x /setup.sh
RUN sh /setup.sh

CMD ["mysqld"]
