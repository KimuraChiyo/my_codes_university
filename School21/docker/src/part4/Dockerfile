# Based on nginx (1.4)
FROM nginx

# Copying nginx.conf into container (1.3)
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

# Change working dir
WORKDIR /home/

# Copying server source code
COPY ./server.c ./server.c

# Copying script for entrypoint running
COPY ./script.sh ./script.sh

# Installing dependencies
RUN apt-get -qq update && apt-get -qq install -y gcc libfcgi libfcgi-dev spawn-fcgi 

# Set entrypoint command
ENTRYPOINT ["sh", "./script.sh"]
