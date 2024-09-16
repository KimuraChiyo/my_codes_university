# Basic CI/CD

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Настройка gitlab-runner](#part-1-настройка-gitlab-runner)  
   1.2. [Сборка](#part-2-сборка)  
   1.3. [Тест кодстайла](#part-3-тест-кодстайла)   
   1.4. [Интеграционные тесты](#part-4-интеграционные-тесты)  
   1.5. [Этап деплоя](#part-5-этап-деплоя)  
   1.6. [Дополнительно. Уведомления](#part-6-дополнительно-уведомления)


## Chapter I

### Part 1. Настройка **gitlab-runner**

**== Задание ==**

##### Подними виртуальную машину *Ubuntu Server 22.04 LTS*.
<img src="./screens/1.1._cat_issue_22-04.jpg" alt="cat etc/issue ws1" width="400"/>

##### Скачай и установи на виртуальную машину **gitlab-runner**.
```bash
curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | sudo bash
```
```bash
sudo apt-get install gitlab-runner
```
<img src="./screens/1.2._check_status_gitlab-runner.jpg" alt="systemctl status gitlab-runner.service" width="800"/>

##### Запусти **gitlab-runner** и зарегистрируй его для использования в текущем проекте (*DO6_CICD*).
- Для регистрации понадобятся URL и токен, которые можно получить на страничке задания на платформе.
```bash
sudo gitlab-runner register
```
<img src="./screens/1.3._register_runner.jpg" alt="gitlab-runner register" width="1000"/>

### Part 2. Сборка

**== Задание ==**

#### Напиши этап для **CI** по сборке приложений из проекта *C2_SimpleBashUtils*.

##### В файле _gitlab-ci.yml_ добавь этап запуска сборки через мейк файл из проекта _C2_.

##### Файлы, полученные после сборки (артефакты), сохрани в произвольную директорию со сроком хранения 30 дней.
- Build Job:<br>
<img src="./screens/2.1._build_job.jpg" alt="build job" width="450"/><br>

- Result:<br>
<img src="./screens/2.2._build_job_result.jpg" alt="build job results" width="750"/>

### Part 3. Тест кодстайла

**== Задание ==**

#### Напиши этап для **CI**, который запускает скрипт кодстайла (*clang-format*).
- Style Job:<br>
<img src="./screens/3.1._style_job.jpg" alt="style job" width="550"/><br>

##### Если кодстайл не прошел, то «зафейли» пайплайн.

##### В пайплайне отобрази вывод утилиты *clang-format*.
- Отстутсвие clang-format на машине с раннером:<br>
<img src="./screens/3.2._style_job_failed.jpg" alt="style job result without clang-format" width="700"/><br>
- Устанавливаем clang-format на ws1 с помощью команды:<br>

```bash
sudo apt install -y clang-format
```
- Успешная работа пайплайна:<br>
<img src="./screens/3.3._style_job_success.jpg" alt="style job success result" width="700"/><br>

- Изменим файл s21_grep_functions.c:<br>
<img src="./screens/3.4._style_error.jpg" alt="edit for clang-format error" width="300"/><br>

- Проверим на локальной машине, что ошибка выдаётся:<br>
<img src="./screens/3.5._style_error_check.jpg" alt="chesk clang-format on local machine" width="700"/><br>

- Проверим в пайплайне, что ошибка выдаётся:<br>
<img src="./screens/3.6._style_job_failed.jpg" alt="style job failed" width="700"/><br>

P.S. После проверки выдачи ошибки при некорректной проверке на стиль кода всё было возвращено в начальное состояние, т.е. без ошибок

### Part 4. Интеграционные тесты

**== Задание ==**

#### Напиши этап для **CI**, который запускает твои интеграционные тесты из того же проекта.

##### Запусти этот этап автоматически только при условии, если сборка и тест кодстайла прошли успешно.

##### Если тесты не прошли, то «зафейли» пайплайн.

##### В пайплайне отобрази вывод, что интеграционные тесты успешно прошли / провалились.
- Test Job:<br>
<img src="./screens/4.1._test_job.jpg" alt="test job" width="600"/><br>

- Проверка запуска только с корректными build и style(пропущен, т.к. зафейлен кодстайл):<br>
<img src="./screens/4.2._test_job_skipped.jpg" alt="test job skipped" width="600"/><br>

- Изменим немного тестовый скрипт для того, чтобы появились ошибки:<br>
<img src="./screens/4.3._change_test_script_for_errors.jpg" alt="changed script for errors" width="600"/><br>

- Т.к. появились ошибки в исполнении тестов, то пайплайн зафейлен:<br>
<img src="./screens/4.4._failed_pipeline.jpg" alt="failed pipeline" width="700"/><br>

P.s. перед следующим шагом был исправлен тестовый скрипт, чтобы ошибки отсутствовали<br>

- Успешное завершение тестирования:<br>
<img src="./screens/4.5._success_pipeline.jpg" alt="success pipeline" width="700"/><br>

### Part 5. Этап деплоя

**== Задание ==**

##### Подними вторую виртуальную машину *Ubuntu Server 22.04 LTS*.
<img src="./screens/5.1._cat_issue_22-04_on_ws2.jpg" alt="ws2 cat /etc/issue" width="700"/><br>

#### Напиши этап для **CD**, который «разворачивает» проект на другой виртуальной машине.

##### Запусти этот этап вручную при условии, что все предыдущие этапы прошли успешно.

##### Напиши bash-скрипт, который при помощи **ssh** и **scp** копирует файлы, полученные после сборки (артефакты), в директорию */usr/local/bin* второй виртуальной машины.
- Будь готов объяснить по скрипту, как происходит перенос.

- Для начала необходимо настроить связь между двумя машинами. Здесь нам пригодится опыт из LinuxNetwork part2<br>
- ws1, installer-config:<br>
<img src="./screens/5.2._ws1_installer_conf.jpg" alt="ws1 00-installer-config" width="700"/><br>

```bash
sudo netplan apply
```
- ws1, ip a:<br>
<img src="./screens/5.3._ws1_ip_a.jpg" alt="ws1 ip a" width="1000"/><br>

- ws2, installer-config:<br>
<img src="./screens/5.4._ws2_installer_conf.jpg" alt="ws2 00-installer-config" width="700"/><br>

```bash
sudo netplan apply
```
- ws2, ip a:<br>
<img src="./screens/5.5._ws2_ip_a.jpg" alt="ws2 ip a" width="1000"/><br>

- ping ws2 from ws1:<br>
<img src="./screens/5.6._ping_ws2_from_ws1.jpg" alt="ping ws2 from ws1" width="700"/><br>
- ping ws1 from ws2:<br>
<img src="./screens/5.7._ping_ws1_from_ws2.jpg" alt="ping ws1 from ws2" width="700"/><br>

- Затем пишем bash-скрипт, который копирует файлы на вторую машину:<br>
<img src="./screens/5.8._script.jpg" alt="script.sh" width="700"/><br>

##### В файле _gitlab-ci.yml_ добавь этап запуска написанного скрипта.
<img src="./screens/5.9._deploy_job.jpg" alt="deploy job" width="700"/><br>

В результате ты должен получить готовые к работе приложения из проекта *C2_SimpleBashUtils* (s21_cat и s21_grep) на второй виртуальной машине.<br>
<img src="./screens/5.10._deploy_result.jpg" alt="deploy result" width="700"/><br>

##### В случае ошибки «зафейли» пайплайн.
- Фейлился пайплайн сначала при передаче файлов(обменялся ключами), затем при перемещении(дал права доступа). Оба решения закомментированы в script.sh <br>
- Ошибка в передаче файлов:<br>
<img src="./screens/5.11._fail1.jpg" alt="deploy fail1" width="700"/><br>
- Ошибка в перемещении файлов:<br>
<img src="./screens/5.12._fail2.jpg" alt="deploy fail2" width="700"/><br>

##### Сохрани дампы образов виртуальных машин.
**P.S. Ни в коем случае не сохраняй дампы в гит!**
- Не забудь запустить пайплайн с последним коммитом в репозитории.

- ws2:<br>
<img src="./screens/5.13._dump_ws1.jpg" alt="ws1 dump" width="700"/><br>
- ws2:<br>
<img src="./screens/5.14._dump_ws2.jpg" alt="ws2 dump" width="700"/><br>


### Part 6. Дополнительно. Уведомления

**== Задание ==**

##### Настрой уведомления о успешном/неуспешном выполнении пайплайна через бота с именем «[твой nickname] DO6 CI/CD» в *Telegram*.
- Текст уведомления должен содержать информацию об успешности прохождения как этапа **CI**, так и этапа **CD**.
- В остальном текст уведомления может быть произвольным.

- Проверим выдачу неуспешного пайплайна:<br>
<img src="./screens/6.1._failed.jpg" alt="fail pipeline message" width="700"/><br>
Исправим ошибку в стиле(специально созданную)<br>
- Проверим выдачу успешного пайплайна:<br>
<img src="./screens/6.2._success.jpg" alt="success pipeline message" width="700"/><br>

