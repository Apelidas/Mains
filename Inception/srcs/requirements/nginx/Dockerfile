FROM debian:12.2

RUN apt-get update
RUN apt-get install -y nginx && apt install openssl -y
RUN openssl req -x509 -nodes -newkey rsa:4096 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=DE/ST=Wob/L=Wob/O=42 School/OU=kkleinsc/CN=kkleinsc"
