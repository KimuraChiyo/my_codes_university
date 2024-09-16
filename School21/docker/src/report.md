code# Simple Docker

## Contents
1. [Chapter III](#chapter-iii) \
    3.1. [Готовый докер](#part-1-готовый-докер) \
    3.2. [Операции с контейнером](#part-2-операции-с-контейнером) \
    3.3. [Мини веб-сервер](#part-3-мини-веб-сервер) \
    3.4. [Свой докер](#part-4-свой-докер) \
    3.5. [Dockle](#part-5-dockle) \
    3.6. [Базовый Docker Compose](#part-6-базовый-docker-compose)

## Chapter III

## Part 1. Готовый докер

**== Задание ==**

##### 1) Возьми официальный докер-образ с **nginx** и выкачай его при помощи `docker pull`.
<img src="./screens/1.1._docker_pull_nginx.jpg" alt="docker pull nginx" width="600"/>

##### 2) Проверь наличие докер-образа через `docker images`.
<img src="./screens/1.2._docker_images.jpg" alt="docker images" width="600"/>

##### 3) Запусти докер-образ через `docker run -d [image_id|repository]`.
<img src="./screens/1.3._docker_run.jpg" alt="docker run" width="600"/>

##### 4) Проверь, что образ запустился через `docker ps`.
<img src="./screens/1.4._docker_ps.jpg" alt="docker ps" width="600"/>

##### 5) Посмотри информацию о контейнере через `docker inspect [container_id|container_name]`.
<img src="./screens/1.5._docker_inspect.jpg" alt="docker inspect" width="600"/>

##### 6) По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера.
- Размер:<br>
<img src="./screens/1.6.1._inspect_size.jpg" alt="docker inspect size" width="600"/><br>
- Замапленные порты:<br>
<img src="./screens/1.6.2._inspect_ports.jpg" alt="docker inspect ports" width="600"/><br>
- IP контейнера:<br>
<img src="./screens/1.6.3._inspect_ipaddress.jpg" alt="docker inspect ipaddress" width="600"/><br>

##### 7) Останови докер образ через `docker stop [container_id|container_name]`.
<img src="./screens/1.7._docker_stop.jpg" alt="docker stop" width="600"/>

##### 8) Проверь, что образ остановился через `docker ps`.
<img src="./screens/1.8._docker_ps.jpg" alt="docker ps" width="600"/>

##### 9) Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*.
<img src="./screens/1.9._docker_run.jpg" alt="docker run with ports" width="600"/>

##### 10) Проверь, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**.
<img src="./screens/1.10._localhost.jpg" alt="localhost nginx" width="600"/>

##### 11) Перезапусти докер контейнер через `docker restart [container_id|container_name]`.
##### 12)Проверь любым способом, что контейнер запустился.
- Перезапуск контейнера с проверкой:<br>
<img src="./screens/1.11+12._docker_restart.jpg" alt="docker restart + checking restart" width="1100"/>

- В отчёт помести скрины:
  - вызова и вывода всех использованных в этой части задания команд;
  - стартовой страницы **nginx** по адресу *localhost:80* (адрес должен быть виден).

## Part 2. Операции с контейнером

**== Задание ==**

##### 1) Прочитай конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*.
<img src="./screens/2.1._exec_cat_nginx_conf.jpg" alt="docker exec cat etc/nginx/nginx.conf" width="800"/><br>

##### 2) Создай на локальной машине файл *nginx.conf*.
<img src="./screens/2.2._touch_nginx_conf.jpg" alt="touch nginx.conf" width="800"/><br>

##### 3) Настрой в нем по пути */status* отдачу страницы статуса сервера **nginx**.
<img src="./screens/2.3._nginx_conf.jpg" alt="nginx.conf" width="800"/><br>

##### 4) Скопируй созданный файл *nginx.conf* внутрь докер-образа через команду `docker cp`.
<img src="./screens/2.4._docker_cp.jpg" alt="docker cp nginx.con into container" width="800"/><br>

##### 5) Перезапусти **nginx** внутри докер-образа через команду *exec*.
<img src="./screens/2.5._nginx_reload.jpg" alt="reload nginx in container" width="800"/><br>

##### 6) Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
<img src="./screens/2.6._localhost_status.jpg" alt="localhost/status" width="800"/><br>

##### 7) Экспортируй контейнер в файл *container.tar* через команду *export*.
<img src="./screens/2.7._docker_export.jpg" alt="docker export" width="800"/><br>

##### 8) Останови контейнер.
<img src="./screens/2.8._docker_stop.jpg" alt="docker stop" width="800"/><br>

##### 9) Удали образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры.
<img src="./screens/2.9._docker_rmi.jpg" alt="docker rmi -f image" width="1100"/><br>

##### 10) Удали остановленный контейнер.
<img src="./screens/2.10._docker_rm.jpg" alt="docker rm container" width="800"/><br>

##### 11) Импортируй контейнер обратно через команду *import*.
<img src="./screens/2.11._docker_import.jpg" alt="docker import tar" width="800"/><br>

##### 12) Запусти импортированный контейнер.
<img src="./screens/2.12._docker_run.jpg" alt="docker import -c" width="1100"/><br>

##### 13) Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
<img src="./screens/2.13._localhost_status.jpg" alt="localhost/status" width="800"/><br>

- В отчёт помести скрины:
  - вызова и вывода всех использованных в этой части задания команд;
  - содержимое созданного файла *nginx.conf*;
  - страницы со статусом сервера **nginx** по адресу *localhost:80/status*.

## Part 3. Мини веб-сервер

**== Задание ==**

##### 1) Напиши мини-сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!`.
<img src="./screens/3.1._server.jpg" alt="fastcgi server" width="600"/><br>

##### 2) Запусти написанный мини-сервер через *spawn-fcgi* на порту 8080.
- 2.1) Импортируем образ контейнера из tar-файла:<br>
<img src="./screens/3.2.1._docker_import.jpg" alt="docker import" width="1000"/><br>
- 2.2) Запускаем контейнер и проверяем, что он запущен:<br>
<img src="./screens/3.2.2._docker_run_ps.jpg" alt="docker run container + checking he is running" width="1000"/><br>
- 2.3) Копируем наш сервер в контейнер:<br>
<img src="./screens/3.2.3._docker_cp.jpg" alt="docker cp server.c" width="1000"/><br>
- 2.4) Устанавливаем зависимости для компиляции и запуска:<br>
<img src="./screens/3.2.4._download_dependencies.jpg" alt="download dependencies" width="1000"/><br>
- 2.5) Компилируем и запускаем сервер:<br>
<img src="./screens/3.2.5._run_server.jpg" alt="compile server.c and running him with spawn-fcgi" width="600"/><br>

##### 3) Напиши свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*.
- 3.1) Файл nginx.conf с прослушиванием 81 порта и сервером на 8080 порту:<br>
<img src="./screens/3.3.1._nginx_conf.jpg" alt="nginx.conf with listen 81 and localhost:8080" width="1000"/><br>
- 3.2) Копируем файл nginx.conf и перезапускаем nginx:<br>
<img src="./screens/3.3.2._docker_cp_plus_reload_nginx.jpg" name="nginx.conf" alt="docker cp and reload nginx" width="1000"/><br>

##### 4) Проверь, что в браузере по *localhost:81* отдается написанная тобой страничка.
<img src="./screens/3.4._localhost_81.jpg" alt="compile server.c and running him with spawn-fcgi" width="500"/><br>

##### 5) Положи файл *nginx.conf* по пути *./nginx/nginx.conf* (это понадобится позже).
<a href="#nginx.conf">Пункт 3.2</a>

## Part 4. Свой докер

**== Задание ==**

#### 1) Напиши свой докер-образ, который:
##### 1.1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер);
##### 1.2) запускает его на 8080 порту;
##### 1.3) копирует внутрь образа написанный *./nginx/nginx.conf*;
##### 1.4) запускает **nginx**.
- Dockerfile:<br>
<img src="./screens/4.1.1._dockerfile.jpg" alt="dockerfile" width="700"/><br>
- Entrypoint script:<br>
<img src="./screens/4.1.2._entrypoint_script.jpg" alt="entrypoint script" width="400"/><br>

##### 2) Собери написанный докер-образ через `docker build` при этом указав имя и тег.
```bash
sudo docker build -t part4:1.0 .
```
- docker build start:<br>
<img src="./screens/4.2.1._docker_build_start.jpg" alt="docker build start" width="800"/><br>
- docker build finish:<br>
<img src="./screens/4.2.2._docker_build_finish.jpg" alt="docker build finish" width="800"/><br>

##### 3) Проверь через `docker images`, что все собралось корректно.
```bash
docker images
```
<img src="./screens/4.3._docker_images.jpg" alt="docker images" width="700"/><br>

##### 4) Запусти собранный докер-образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а (см. [Часть 2](#part-2-операции-с-контейнером)).
```bash
sudo docker run -d -p 80:81 -v $(pwd)/nginx/nginx.conf:/etc/nginx/nginx.conf part4:1.0
```
<img src="./screens/4.4._docker_run.jpg" alt="docker run with mapping" width="700"/><br>

##### 5) Проверь, что по localhost:80 доступна страничка написанного мини сервера.
<img src="./screens/4.5._localhost.jpg" alt="localhost" width="500"/><br>

##### 6)  Допиши в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**.
<img src="./screens/4.6._add_status_page.jpg" alt="adding status page" width="600"/><br>

##### 7)  Перезапусти докер-образ.
```bash
sudo docker ps
```
```bash
sudo docker stop container
```
```bash
sudo docker run -d -p 80:81 -v $(pwd)/nginx/nginx.conf:/etc/nginx/nginx.conf part4:1.0
```
```bash
sudo docker ps
```
<img src="./screens/4.7._restart_container.jpg" alt="restart container" width="700"/><br>

##### 8) Проверь, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**
<img src="./screens/4.8._localhost_status.jpg" alt="localhost status" width="400"/><br>

## Part 5. **Dockle**

**== Задание ==**

##### 1) Просканируй образ из предыдущего задания через `dockle [image_id|repository]`.
```bash
sudo dockle part4:1.0
```
- Dockle result before changes:<br>
<img src="./screens/5.1._dockle.jpg" alt="dockle after changes" width="800"/><br>

##### 2) Исправь образ так, чтобы при проверке через **dockle** не было ошибок и предупреждений.
- Changed Dockerfile:<br>
<img src="./screens/5.2.1._changed_dockerfile.jpg" alt="changed dockerfile" width="700"/><br>
```bash
sudo dockle -ak NGINX_GPGKEY -ak NGINX_GPGKEY_PATH -ak NGINX_GPGKEYS -ak NGINX_GPGKEYS_PATH  part5:1.0
```
- Dockle result after changes:<br>
<img src="./screens/5.2.2._dockle.jpg" alt="dockle after changes" width="600"/><br>

## Part 6. Базовый **Docker Compose**

**== Задание ==**

##### 1) Напиши файл *docker-compose.yml*, с помощью которого:
##### 1.1) Подними докер-контейнер из [Части 5](#part-5-инструмент-dockle) _(он должен работать в локальной сети, т.е. не нужно использовать инструкцию **EXPOSE** и мапить порты на локальную машину)_.
##### 1.2) Подними докер-контейнер с **nginx**, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера.
- Dockerfile:<br>
<img src="./screens/6.1.2.1._dockerfile.jpg" alt="new dockerfile" width="600"/><br>
- Entrypoint script:<br>
<img src="./screens/6.1.2.2._entrypoint_script.jpg" alt="new entrypoint script" width="600"/><br>
- nginx.conf:<br>
<img src="./screens/6.1.2.3._nginx_conf.jpg" alt="new nginx conf" width="600"/><br>

##### 2) Замапь 8080 порт второго контейнера на 80 порт локальной машины.
<img src="./screens/6.2._dockercompose_yml.jpg" alt="docker-compose.yml" width="600"/><br>

##### 3) Останови все запущенные контейнеры.
<img src="./screens/6.3._docker_ps.jpg" alt="docker-compose.yml" width="600"/><br>

##### 4) Собери и запусти проект с помощью команд `docker-compose build` и `docker-compose up`.
- build:<br>
<img src="./screens/6.4.1._docker-compose_build.jpg" alt="docker-compose build" width="600"/><br>
- up:<br>
<img src="./screens/6.4.2._docker-compose_up_d.jpg" alt="docker-compose up -d" width="600"/><br>

##### 5) Проверь, что в браузере по *localhost:80* отдается написанная тобой страничка, как и ранее.
- localhost:<br>
<img src="./screens/6.5.1._localhost.jpg" alt="localhost" width="600"/><br>
- localhost/status:<br>
<img src="./screens/6.5.2._localhost_status.jpg" alt="localhost/status" width="600"/><br>
