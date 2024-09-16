# Based on nginx in part4 (1.4)
FROM nginx

# Copying nginx.conf into container (1.3)
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

# Change working dir
WORKDIR /home/

# Copying server source code
COPY ./server.c ./server.c

# Copying script for entrypoint running
COPY ./script.sh ./script.sh

# Installing dependencies + privilegies for user
# + rm -rf apt lists to resolve DKL-DI-0005
RUN apt-get -qq update && apt-get -qq install -y gcc spawn-fcgi libfcgi-dev; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chown -R nginx:nginx /home; \
    rm -rf /var/lib/apt/lists

# Change user to nginx to resolve CIS-DI-0001
USER nginx

# Set entrypoint command
ENTRYPOINT ["sh", "./script.sh"]
