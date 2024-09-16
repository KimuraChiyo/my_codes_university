#!/bin/bash

# compiling source code (1.1)
gcc ./server.c -lfcgi -o ./server

# spawn on 8080 (1.2)
spawn-fcgi -p 8080 ./server

# nginx on foreground
nginx -g "daemon off;"
