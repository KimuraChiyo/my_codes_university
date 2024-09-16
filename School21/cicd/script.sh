#!/bin/bash

# Настройка обмена между ws1 и ws2

# 1) Меняем пользователя на раннер:
# sudo su gitlab-runner
# 2) Генерируем ключ за раннер:
# ssh-keygen -t rsa
# 3) Копируем ключ на ws2:
# ssh-copy-id ironmakr@172.24.116.8:
# 4) Подключаемся к ws2:
# ssh ironmakr@172.24.116.8:


# Копируем утилиты
scp ./src/cat/s21_cat ironmakr@172.24.116.8:~/
scp ./src/grep/s21_grep ironmakr@172.24.116.8:~/

# Даём права доступа для выполнения без sudo 
# sudo chown -R ironmakr /usr/local/bin

# Передаем команду по ssh для перемещения файлов
ssh ironmakr@172.24.116.8 "mv s21_* /usr/local/bin"
