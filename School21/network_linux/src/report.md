## Part 1. Инструмент **ipcalc**

**== Задание ==**

##### Подними виртуальную машину (далее -- ws1)
<img src="./screens/1.0._ws1.jpg" alt="ws1" width="500"/><br>

#### 1.1. Сети и маски
##### Определи и запиши в отчёт:

##### 1) Адрес сети *192.167.38.54/13*
<img src="./screens/1.1.1._ipcalc_192_167_38_54_13.jpg" alt="ipcalc 192.167.38.54/13" width="500"/><br>
- Адрес сети находится в строке Network: 192.160.0.0

##### 2) Перевод маски *255.255.255.0* в префиксную и двоичную запись, */15* в обычную и двоичную, *11111111.11111111.11111111.11110000* в обычную и префиксную

- Перевод маски 255.255.255.0 в префиксную и двоичную запись
<br><img src="./screens/1.1.2.1._ipcalc_255_255_255_0.jpg" alt="ipcalc 255.255.255.0" width="500"/><br>
Двоичная запись: <b>11111111.11111111.11111111.00000000</b><br>
Префиксная запись(количество единиц в двоичной записи) = <b>/24</b>


- Перевод маски /15 в обычную и двоичную
<br><img src="./screens/1.1.2.2._ipcalc_0_0_0_0_15.jpg" alt="ipcalc 0.0.0.0/15" width="500"/><br>
Обычная запись: <b>255.254.0.0</b><br>
Двоичная запись: <b>11111111.11111110.00000000.00000000</b>

- Перевод маски *11111111.11111111.11111111.11110000* в обычную и префиксную
<br>В этой маске 28 единиц, следовательно, префикс этой сети - /28
<br><img src="./screens/1.1.2.3._ipcalc_0_0_0_0_28.jpg" alt="ipcalc 0.0.0.0/28" width="500"/><br>
Обычная запись: <b>255.255.255.240</b><br>
Префиксная запись(количество единиц в двоичной записи) = <b>/28</b>

##### 3) Минимальный и максимальный хост в сети *12.167.38.4* при масках: */8*, *11111111.11111111.00000000.00000000*, *255.255.254.0* и */4*

- Минимальный и максимальный хост в сети *12.167.38.4* при маске /8<br>
<img src="./screens/1.1.3.1._ipcalc_12_167_38_4_8.jpg" alt="ipcalc 12.167.38.4/8" width="500"/><br>

- Минимальный и максимальный хост в сети *12.167.38.4* при маске 11111111.11111111.00000000.00000000(префикс /16)<br>
<img src="./screens/1.1.3.2._ipcalc_12_167_38_4_16.jpg" alt="ipcalc 12.167.38.4/16" width="500"/><br>

- Минимальный и максимальный хост в сети *12.167.38.4* при маске 255.255.254.0<br>
<img src="./screens/1.1.3.3._ipcalc_12_167_38_4_255_255_254_0.jpg" alt="ipcalc 12.167.38.4 255.255.254.0" width="500"/><br>

- Минимальный и максимальный хост в сети *12.167.38.4* при маске /4<br>
<img src="./screens/1.1.3.4._ipcalc_12_167_38_4_4.jpg" alt="ipcalc 12.167.38.4/4" width="500"/><br>


#### 1.2. localhost
##### Определи и запиши в отчёт, можно ли обратиться к приложению, работающему на localhost, со следующими IP: *194.34.23.100*, *127.0.0.2*, *127.1.0.1*, *128.0.0.1*

Для того, чтобы можно было обратиться к приложению, работающему на localhost, с конкретным IP необходимо, чтобы адрес находился в диапазоне от 127.0.0.1 до 127.255.255.254<br>
<img src="./screens/1.2._ipcalc_127_0_0_1_8.jpg" alt="ipcalc 127.0.0.1/8" width="500"/><br>

- 194.34.23.100 - нельзя обратиться
- 127.0.0.2 - можно обратиться
- 127.1.0.1 - можно обратиться
- 128.0.0.1 - нельзя обратиться

#### 1.3. Диапазоны и сегменты сетей
##### Определи и запиши в отчёт:
##### 1) Какие из перечисленных IP можно использовать в качестве публичного, а какие только в качестве частных: *10.0.0.45*, *134.43.0.2*, *192.168.4.2*, *172.20.250.4*, *172.0.2.1*, *192.172.0.1*, *172.68.0.2*, *172.16.255.255*, *10.10.10.10*, *192.169.168.1*

- *10.0.0.45* - частный
<br><img src="./screens/1.3.1.1._ipcalc_10_0_0_45.jpg" alt="ipcalc 10.0.0.45" width="500"/><br>

- *134.43.0.2* - публичный
<br><img src="./screens/1.3.1.2._ipcalc_134_43_0_2.jpg" alt="ipcalc 134.43.0.2" width="500"/><br>

- *192.168.4.2* - частный
<br><img src="./screens/1.3.1.3._ipcalc_192_168_4_2.jpg" alt="ipcalc 192.168.4.2" width="500"/><br>

- *172.20.250.4* - частный
<br><img src="./screens/1.3.1.4._ipcalc_172_20_250_4.jpg" alt="ipcalc 172.20.250" width="500"/><br>

- *172.0.2.1* - публичный
<br><img src="./screens/1.3.1.5._ipcalc_172_0_2_1.jpg" alt="ipcalc 172.0.2.1" width="500"/><br>

- *192.172.0.1* - публичный
<br><img src="./screens/1.3.1.6._ipcalc_192_172_0_1.jpg" alt="ipcalc 192.172.0.1" width="500"/><br>

- *172.68.0.2* - публичный
<br><img src="./screens/1.3.1.7._ipcalc_172_68_0_2.jpg" alt="ipcalc 172.68.0.2" width="500"/><br>

- *172.16.255.255* - частный
<br><img src="./screens/1.3.1.8._ipcalc_172_16_255_255.jpg" alt="ipcalc 172.16.255.255" width="500"/><br>

- *10.10.10.10* - частный
<br><img src="./screens/1.3.1.9._ipcalc_10_10_10_10.jpg" alt="ipcalc 10.10.10.10" width="500"/><br>

- *192.169.168.1* - публичный
<br><img src="./screens/1.3.1.10._ipcalc_192_169_168_1.jpg" alt="ipcalc 192.169.168.1" width="500"/><br>


##### 2) Какие из перечисленных IP адресов шлюза возможны у сети *10.10.0.0/18*: *10.0.0.1*, *10.10.0.2*, *10.10.10.10*, *10.10.100.1*, *10.10.1.255*
Адрес шлюза возможен, если адрес находится в диапазоне от 10.10.0.1 до 10.10.63.254<br>
<img src="./screens/1.3.2._ipcalc_10_10_0_0_18.jpg" alt="ipcalc 10.10.0.0/18" width="500"/><br>

- *10.0.0.1* - невозможен<br>
- *10.10.0.2* - возможнен<br>
- *10.10.10.10* - возможен<br>
- *10.10.100.1* - невозможен<br>
- *10.10.1.255* - возможен<br>


## Part 2. Статическая маршрутизация между двумя машинами

**== Задание ==**

##### Подними две виртуальные машины (далее -- ws1 и ws2).
<img src="./screens/2.0._ws1_ws2.jpg" alt="ws1 ws2" width="500"/><br>

##### С помощью команды `ip a` посмотри существующие сетевые интерфейсы.
- В отчёт помести скрин с вызовом и выводом использованной команды.

- ws1:<br>
<img src="./screens/2.0.1.1._ws1.jpg" alt="ip a ws1" width="500"/><br>

- ws2:<br>
<img src="./screens/2.0.1.2._ws2.jpg" alt="ip a ws2" width="500"/><br>

##### Опиши сетевой интерфейс, соответствующий внутренней сети, на обеих машинах и задать следующие адреса и маски: ws1 - *192.168.100.10*, маска */16*, ws2 - *172.24.116.8*, маска */12*.

Описание сетевых интерфейсов:
- ws1:
1) lo - 127.0.0.1/8
2) enp0s3 - 10.0.2.15/24

- ws2:
1) lo - 127.0.0.1/8
2) enp0s3 - 10.0.2.15/24

- В отчёт помести скрины с содержанием изменённого файла *etc/netplan/00-installer-config.yaml* для каждой машины.

- ws1:<br>
<img src="./screens/2.0.2.1._ws1.jpg" alt="cat 00-installer ws1" width="500"/><br>

- ws2:<br>
<img src="./screens/2.0.2.2._ws2.jpg" alt="cat 00-installer ws2" width="500"/><br>

##### Выполни команду `netplan apply` для перезапуска сервиса сети.
- В отчёт помести скрин с вызовом и выводом использованной команды.
- ws1:<br>
<img src="./screens/2.0.3.1._ws1.jpg" alt="ip a ws1" width="500"/><br>

- ws2:<br>
<img src="./screens/2.0.3.2._ws2.jpg" alt="ip a ws2" width="500"/><br>

#### 2.1. Добавление статического маршрута вручную
##### Добавь статический маршрут от одной машины до другой и обратно при помощи команды вида `ip r add`.
- ws1: - ip r add 172.24.116.8 dev enp0s3 
- ws2: - ip r add 192.168.100.10 dev enp0s3 
##### Пропингуй соединение между машинами.
- ws1: - ping 172.24.116.8 -c 4
- ws2: - ping 192.168.100.10 -c 4

- В отчёт помести скрин с вызовом и выводом использованных команд.
- ws1:<br>
<img src="./screens/2.1.1._ws1.jpg" alt="ip r add for ws1 + ping" width="500"/><br>

- ws2:<br>
<img src="./screens/2.1.2._ws2.jpg" alt="ip r add for ws2 + ping" width="500"/><br>

#### 2.2. Добавление статического маршрута с сохранением
##### Перезапусти машины.
- $ reboot
##### Добавь статический маршрут от одной машины до другой с помощью файла *etc/netplan/00-installer-config.yaml*.
- В отчёт помести скрин с содержанием изменённого файла *etc/netplan/00-installer-config.yaml*.
- ws1:<br>
<img src="./screens/2.2.1.1._ws1.jpg" alt="00-installer for ws1" width="500"/><br>

- ws2:<br>
<img src="./screens/2.2.1.2._ws2.jpg" alt="00-installer for ws1" width="500"/><br>
- $ sudo netplan apply - чтобы сохранить изменения настроек.

##### Пропингуй соединение между машинами.
- В отчёт помести скрин с вызовом и выводом использованной команды.
- ws1:<br>
<img src="./screens/2.2.2.1._ws1.jpg" alt="ping ws2 from ws1" width="500"/><br>

- ws2:<br>
<img src="./screens/2.2.2.2._ws2.jpg" alt="ping ws1 from ws2" width="500"/><br>

## Part 3. Утилита **iperf3**

**== Задание ==**

#### 3.1. Скорость соединения
##### Переведи и запиши в отчёт: 8 Mbps в MB/s, 100 MB/s в Kbps, 1 Gbps в Mbps.
- 8 Mbps == 1 MB/s
- 100 MB/s == 800000 Kbps
- 1 Gbps == 1000 Mbps

#### 3.2. Утилита **iperf3**
##### Измерь скорость соединения между ws1 и ws2.

1) Запускаем iperf3 на ws2 в режиме сервера с помощью команды:<br>
- $ iperf3 -s -f K

2) Затем на ws1 запускаем iperf3 в режиме клиента с помощью команды:<br>
- $ iperf3 -c 172.24.116.8 -f K

- В отчёт помести скрины с вызовом и выводом использованных команд.
- ws1:<br>
<img src="./screens/3.2.1_ws2.jpg" alt="iperf3 -s -f K on ws2" width="800"/><br>

- ws2:<br>
<img src="./screens/3.2.2_ws1.jpg" alt="iperf3 -c 172.24.116.8 -f K on ws1" width="800"/><br>

## Part 4. Сетевой экран

**== Задание ==**

#### 4.1. Утилита **iptables**
##### Создай файл */etc/firewall.sh*, имитирующий фаерволл, на ws1 и ws2:
```shell
#!/bin/sh

# Удаление всех правил в таблице «filter» (по-умолчанию).
iptables -F
iptables -X
```
##### Нужно добавить в файл подряд следующие правила:
##### 1) На ws1 примени стратегию, когда в начале пишется запрещающее правило, а в конце пишется разрешающее правило (это касается пунктов 4 и 5).
##### 2) На ws2 примени стратегию, когда в начале пишется разрешающее правило, а в конце пишется запрещающее правило (это касается пунктов 4 и 5).
##### 3) Открой на машинах доступ для порта 22 (ssh) и порта 80 (http).
##### 4) Запрети *echo reply* (машина не должна «пинговаться», т.е. должна быть блокировка на OUTPUT).
##### 5) Разреши *echo reply* (машина должна «пинговаться»).
- В отчёт помести скрины с содержанием файла */etc/firewall* для каждой машины.
- ws1:<br>
<img src="./screens/4.1.1._ws1.jpg" alt="cat etc/firewall" width="500"/><br>

- ws2:<br>
<img src="./screens/4.1.2._ws2.jpg" alt="cat etc/firewall" width="500"/><br>

##### Запусти файлы на обеих машинах командами `chmod +x /etc/firewall.sh` и `/etc/firewall.sh`.
- В отчёт помести скрины с запуском обоих файлов;
- ws1:<br>
<img src="./screens/4.1.3._ws1.jpg" alt="sh etc/firewall ws2" width="500"/><br>

- ws2:<br>
<img src="./screens/4.1.4._ws2.jpg" alt="sh etc/firewall ws2" width="500"/><br>

- В отчёте опиши разницу между стратегиями, применёнными в первом и втором файлах.<br>
Если сначала писать запрещающее правило, а затем разрешающее, то запрещающее будет перекрывать разрешающее - следовательно, ws1 невозможно пропинговать, а ws2 возможно.

#### 4.2. Утилита **nmap**
##### Командой **ping** найди машину, которая не «пингуется», после чего утилитой **nmap** покажи, что хост машины запущен.
*Проверка: в выводе nmap должно быть сказано: `Host is up`*.
- В отчёт помести скрины с вызовом и выводом использованных команд **ping** и **nmap**.
- ws1:<br>
<img src="./screens/4.2.1._ping_ws1.jpg" alt="ping ws1 -c 4" width="500"/><br>
Видно, что ws1 не пингуется, поэтому нужно будет применить nmap на ws2.

- ws2:<br>
<img src="./screens/4.2.2._ping_ws2.jpg" alt="ping ws2 -c 4" width="500"/><br>
<img src="./screens/4.2.3._nmap_ws2.jpg" alt="nmap ws1 on ws2" width="500"/><br>

##### Сохрани дампы образов виртуальных машин
<p><a name="part4" href="#dumps">К дампам</a></p>

## Part 5. Статическая маршрутизация сети

**== Задание ==**

Сеть: \
![part5_network](misc/images/part5_network.png)

##### Подними пять виртуальных машин (3 рабочие станции (ws11, ws21, ws22) и 2 роутера (r1, r2)).
<img src="./screens/5.0._5_vms.jpg" alt="5 vms" width="500"/><br>

#### 5.1. Настройка адресов машин
##### Настрой конфигурации машин в *etc/netplan/00-installer-config.yaml* согласно сети на рисунке.
- В отчёт помести скрины с содержанием файла *etc/netplan/00-installer-config.yaml* для каждой машины.

- r1:<br>
<img src="./screens/5.1.1.1._r1.jpg" alt="r1 00-installer" width="500"/><br>
- r2:<br>
<img src="./screens/5.1.1.2._r2.jpg" alt="r2 00-installer" width="500"/><br>
- ws11:<br>
<img src="./screens/5.1.1.3._ws11.jpg" alt="ws11 00-installer" width="500"/><br>
- ws22:<br>
<img src="./screens/5.1.1.4._ws22.jpg" alt="ws22 00-installer" width="500"/><br>
- ws21:<br>
<img src="./screens/5.1.1.5._ws21.jpg" alt="ws21 00-installer" width="500"/><br>

##### Перезапусти сервис сети. Если ошибок нет, то командой `ip -4 a` проверь, что адрес машины задан верно. Также пропингуй ws22 с ws21. Аналогично пропингуй r1 с ws11.
- В отчёт помести скрины с вызовом и выводом использованных команд.

- r1:<br>
<img src="./screens/5.1.2.1._r1.jpg" alt="r1 netplan apply + ip a" width="800"/><br>
- r2:<br>
<img src="./screens/5.1.2.2._r2.jpg" alt="r2 netplan apply + ip a" width="800"/><br>
- ws11:<br>
<img src="./screens/5.1.2.3._ws11.jpg" alt="ws11 netplan apply + ip a" width="800"/><br>
- ws22:<br>
<img src="./screens/5.1.2.4._ws22.jpg" alt="ws22 netplan apply + ip a" width="800"/><br>
- ws21:<br>
<img src="./screens/5.1.2.5._ws21.jpg" alt="ws21 netplan apply + ip a" width="800"/><br>
- ping ws22 from ws21:<br>
<img src="./screens/5.1.2.6._ping_ws22.jpg" alt="ping ws22 from ws21" width="800"/><br>
- ping r1 from ws11:<br>
<img src="./screens/5.1.2.7._ping_r1.jpg" alt="ping r1 from ws11" width="800"/><br>

#### 5.2. Включение переадресации IP-адресов
##### Для включения переадресации IP, выполни команду на роутерах:
`sysctl -w net.ipv4.ip_forward=1`
*При таком подходе переадресация не будет работать после перезагрузки системы.*
- В отчёт помести скрин с вызовом и выводом использованной команды.
- r1:<br>
<img src="./screens/5.2.1.1._r1.jpg" alt="r1 sysctl" width="500"/><br>
- r2:<br>
<img src="./screens/5.2.1.2._r2.jpg" alt="r2 sysctl" width="500"/><br>

##### Открой файл */etc/sysctl.conf* и добавь в него следующую строку:
`net.ipv4.ip_forward = 1`
*При использовании этого подхода, IP-переадресация включена на постоянной основе.*
- В отчёт помести скрин с содержанием изменённого файла */etc/sysctl.conf*.
- r1:<br>
<img src="./screens/5.2.2.1._r1.jpg" alt="r1 sysctl" width="800"/><br>
- r2:<br>
<img src="./screens/5.2.2.2._r2.jpg" alt="r2 sysctl" width="800"/><br>

#### 5.3. Установка маршрута по-умолчанию
Пример вывода команды `ip r` после добавления шлюза:
```
default via 10.10.0.1 dev eth0
10.10.0.0/18 dev eth0 proto kernel scope link src 10.10.0.2
```
##### Настрой маршрут по-умолчанию (шлюз) для рабочих станций. Для этого добавь `default` перед IP роутера в файле конфигураций.
- В отчёт помести скрин с содержанием файла *etc/netplan/00-installer-config.yaml*;
- ws11:<br>
<img src="./screens/5.3.1.1._ws11.jpg" alt="ws11 00-installer" width="500"/><br>
- ws22:<br>
<img src="./screens/5.3.1.2._ws22.jpg" alt="ws22 00-installer" width="500"/><br>
- ws21:<br>
<img src="./screens/5.3.1.3._ws21.jpg" alt="ws21 00-installer" width="500"/><br>

##### Вызови `ip r` и покажи, что добавился маршрут в таблицу маршрутизации.
- В отчёт помести скрин с вызовом и выводом использованной команды.
- ws11:<br>
<img src="./screens/5.3.2.1._ws11.jpg" alt="ws11 ip r" width="800"/><br>
- ws22:<br>
<img src="./screens/5.3.2.2._ws22.jpg" alt="ws22 ip r" width="800"/><br>
- ws21:<br>
<img src="./screens/5.3.2.3._ws21.jpg" alt="ws21 ip r" width="800"/><br>

##### Пропингуй с ws11 роутер r2 и покажи на r2, что пинг доходит. Для этого используй команду:
`tcpdump -tn -i eth0`
- В отчёт помести скрин с вызовом и выводом использованных команд.
- tcpdump:<br>
<img src="./screens/5.3.3.1._tcpdump_r2.jpg" alt="tcpdump -rn -i enp0s3 r2" width="800"/><br>
- ws21:<br>
<img src="./screens/5.3.3.2._ping_r2.jpg" alt="ping r2" width="800"/><br>

#### 5.4. Добавление статических маршрутов
##### Добавь в роутеры r1 и r2 статические маршруты в файле конфигураций. Пример для r1 маршрута в сетку 10.20.0.0/26:
```shell
# Добавь в конец описания сетевого интерфейса eth1:
- to: 10.20.0.0
  via: 10.100.0.12
```
- В отчёт помести скрины с содержанием изменённого файла *etc/netplan/00-installer-config.yaml* для каждого роутера.
- r1:<br>
<img src="./screens/5.4.1.1._r1.jpg" alt="r1 routes" width="500"/><br>
- r2:<br>
<img src="./screens/5.4.1.2._r2.jpg" alt="r2 routes" width="500"/><br>

##### Вызови `ip r` и покажи таблицы с маршрутами на обоих роутерах. Пример таблицы на r1:
```
10.100.0.0/16 dev eth1 proto kernel scope link src 10.100.0.11
10.20.0.0/26 via 10.100.0.12 dev eth1
10.10.0.0/18 dev eth0 proto kernel scope link src 10.10.0.1
```
- В отчёт помести скрин с вызовом и выводом использованной команды.
- r1:<br>
<img src="./screens/5.4.2.1._r1.jpg" alt="r1 ip r" width="800"/><br>
- r2:<br>
<img src="./screens/5.4.2.2._r2.jpg" alt="r2 ip r" width="800"/><br>

##### Запусти команды на ws11:
`ip r list 10.10.0.0/[маска сети]` и `ip r list 0.0.0.0/0`
- В отчёт помести скрин с вызовом и выводом использованных команд;
- r2:<br>
<img src="./screens/5.4.3._ws11.jpg" alt="ws11 ip r list" width="800"/><br>
- В отчёте объясни, почему для адреса 10.10.0.0/\[маска сети\] был выбран маршрут, отличный от 0.0.0.0/0, хотя он попадает под маршрут по-умолчанию
<br>
Так происходит, потому что этот маршрут 10.10.0.0/18 обладает бОльшей точностью.


#### 5.5. Построение списка маршрутизаторов
Пример вывода утилиты **traceroute** после добавления шлюза:
```
1 10.10.0.1 0 ms 1 ms 0 ms
2 10.100.0.12 1 ms 0 ms 1 ms
3 10.20.0.10 12 ms 1 ms 3 ms
```
##### Запусти на r1 команду дампа:
`tcpdump -tnv -i eth0`
##### При помощи утилиты **traceroute** построй список маршрутизаторов на пути от ws11 до ws21.
- В отчёт помести скрины с вызовом и выводом использованных команд (tcpdump и traceroute);
- r1:<br>
<img src="./screens/5.5.1.1._r1.jpg" alt="tcpdump -tnv -i enp0s3" width="800"/><br>
- ws11:<br>
<img src="./screens/5.5.1.2._ws11.jpg" alt="traceroute 10.20.0.10" width="800"/><br>

- В отчёте, опираясь на вывод, полученный из дампа на r1, объясни принцип работы построения пути при помощи **traceroute**.<br>
Утилита отправляет 3 UDP-пакета, предназначенных для целевого узла, через транзитные (нецелевые) узлы. В заголовках передаваемых пакетов поддерживается TTL-поле. Оно указывает на время жизни. Оно определяет количество узлов, через которые пакет может пройти. На каждом узле TTL уменьшается на единицу. Если на пути к удаленному адресату время жизни пакета станет равно 0, маршрутизатор отбросит пакет и отправит источнику ICMP-сообщение об ошибке «Time Exceeded» (время истекло).

#### 5.6. Использование протокола **ICMP** при маршрутизации
##### Запусти на r1 перехват сетевого трафика, проходящего через eth0 с помощью команды:
`tcpdump -n -i eth0 icmp`

##### Пропингуй с ws11 несуществующий IP (например, *10.30.0.111*) с помощью команды:
`ping -c 1 10.30.0.111`
- В отчёт помести скрин с вызовом и выводом использованных команд.
- r1:<br>
<img src="./screens/5.6.1._r1.jpg" alt="tcpdump -n -i enp0s3 icmp" width="800"/><br>
- ws11:<br>
<img src="./screens/5.6.2._ws11.jpg" alt="ping -c 1 10.30.0.111" width="800"/><br>

##### Сохрани дампы образов виртуальных машин.
<p><a name="part5" href="#dumps">К дампам</a></p>

## Part 6. Динамическая настройка IP с помощью **DHCP**

**== Задание ==**

##### Для r2 настрой в файле */etc/dhcp/dhcpd.conf* конфигурацию службы **DHCP**:
##### 1) Укажи адрес маршрутизатора по-умолчанию, DNS-сервер и адрес внутренней сети. Пример файла для r2:
```shell
subnet 10.100.0.0 netmask 255.255.0.0 {}

subnet 10.20.0.0 netmask 255.255.255.192
{
    range 10.20.0.2 10.20.0.50;
    option routers 10.20.0.1;
    option domain-name-servers 10.20.0.1;
}
```
##### 2) В файле *resolv.conf* пропиши `nameserver 8.8.8.8`.
- В отчёт помести скрины с содержанием изменённых файлов.<br>
- dhcpd.conf on r2:<br>
<img src="./screens/6.1.1._dhcpd_conf.jpg" alt="dhcpd.conf" width="800"/><br>
- resolv.conf on r2:<br>
<img src="./screens/6.1.2._resolv_conf.jpg" alt="resolv.conf" width="800"/><br>

##### Перезагрузи службу **DHCP** командой `systemctl restart isc-dhcp-server`. Машину ws21 перезагрузи при помощи `reboot` и через `ip a` покажи, что она получила адрес. Также пропингуй ws22 с ws21.
- В отчёт помести скрины с вызовом и выводом использованных команд.<br>
- restart dhcp service on r2:<br>
<img src="./screens/6.2.1._restart_dhcp.jpg" alt="restart dhcp service" width="800"/><br>

- $ reboot // ws21
- ip a on ws21 + ping ws22 from ws21:<br>
<img src="./screens/6.2.2._ip_a_and_ping.jpg" alt="ip a ws21 + ping ws22 from ws21" width="800"/><br>

##### Укажи MAC адрес у ws11, для этого в *etc/netplan/00-installer-config.yaml* надо добавить строки: `macaddress: 10:10:10:10:10:BA`, `dhcp4: true`.
- В отчёт помести скрин с содержанием изменённого файла *etc/netplan/00-installer-config.yaml*.<br>
<img src="./screens/6.3._ws11_00_installer.jpg" alt="ws11 00-installer" width="800"/><br>

##### Для r1 настрой аналогично r2, но сделай выдачу адресов с жесткой привязкой к MAC-адресу (ws11). Проведи аналогичные тесты.
- В отчёте этот пункт опиши аналогично настройке для r2.
- dhcpd.conf on r1:<br>
<img src="./screens/6.4.1._dhcpd_conf.jpg" alt="dhcpd.conf r1" width="800"/><br>
- resolv.conf on r1:<br>
<img src="./screens/6.4.2._resolv_conf.jpg" alt="resolv.conf r1" width="800"/><br>
- restart dhcp service on r1:<br>
<img src="./screens/6.4.3._restart_dhcp.jpg" alt="restart dhcp service r1" width="800"/><br>

- $ reboot // ws11
- ip a after reboot:<br>
<img src="./screens/6.4.4._ip_a.jpg" alt="ip a ws11" width="800"/><br>

##### Запроси с ws21 обновление ip адреса.
- В отчёте помести скрины ip до и после обновления.
- ip a before update:<br>
<img src="./screens/6.5.1._ip_a_before.jpg" alt="ip a before update ws21" width="800"/><br>

- update + ip a after update:<br>
<img src="./screens/6.5.2._update_ip_a_after.jpg" alt="update + ip a after update ws21" width="800"/><br>

- В отчёте опиши, какими опциями **DHCP** сервера пользовался в данном пункте.<br>
Флаг -r явно освобождает адрес и после этого клиент завершает работу.<br>
Команда <em>sudo dhclient -r enp0s3</em> освобождает предыдущий адрес.<br>
Затем команда <em>sudo dhclient enp0s3</em> присваивает новый адрес.

##### Сохрани дампы образов виртуальных машин.
<p><a name="part6" href="#dumps">К дампам</a></p>

## Part 7. **NAT**

**== Задание ==**

*В данном задании используются виртуальные машины из Части 5.*
##### В файле */etc/apache2/ports.conf* на ws22 и r1 измени строку `Listen 80` на `Listen 0.0.0.0:80`, то есть сделай сервер Apache2 общедоступным.
- В отчёт помести скрин с содержанием изменённого файла.
- r1:<br>
<img src="./screens/7.1.1._r1_ports_conf.jpg" alt="r1 ports.conf" width="700"/><br>
- ws22:<br>
<img src="./screens/7.1.2._ws22_ports_conf.jpg" alt="ws22 port.conf" width="700"/><br>

##### Запусти веб-сервер Apache командой `service apache2 start` на ws22 и r1.
- В отчёт помести скрины с вызовом и выводом использованной команды.
- r1:<br>
<img src="./screens/7.2.1._r1_apache_start.jpg" alt="r1 apache server start" width="500"/><br>
- ws22:<br>
<img src="./screens/7.2.2._ws22_apache_start.jpg" alt="ws22 apache server start" width="500"/><br>

##### Добавь в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:
##### 1) Удаление правил в таблице filter - `iptables -F`;
##### 2) Удаление правил в таблице "NAT" - `iptables -F -t nat`;
##### 3) Отбрасывать все маршрутизируемые пакеты - `iptables --policy FORWARD DROP`.
- current firewall:<br>
<img src="./screens/7.3._firewall.jpg" alt="firewall" width="500"/><br>

##### Запусти файл также, как в Части 4.
- starting firewall:<br>
<img src="./screens/7.4._sh_firewall.jpg" alt="start firewall" width="500"/><br>

##### Проверь соединение между ws22 и r1 командой `ping`.
*При запуске файла с этими правилами, ws22 не должна «пинговаться» с r1.*
- В отчёт помести скрины с вызовом и выводом использованной команды.
- ping ws22:<br>
<img src="./screens/7.5._not_ping_ws22.jpg" alt="not ping ws22" width="500"/><br>

##### Добавь в файл ещё одно правило:
##### 4) Разрешить маршрутизацию всех пакетов протокола **ICMP**.
- current firewall:<br>
<img src="./screens/7.6._accept_icmp.jpg" alt="accept icmp in firewall" width="500"/><br>

##### Запусти файл также, как в Части 4.
- starting firewall:<br>
<img src="./screens/7.7._sh_firewall.jpg" alt="start firewall" width="500"/><br>

##### Проверь соединение между ws22 и r1 командой `ping`.
*При запуске файла с этими правилами, ws22 должна «пинговаться» с r1.*
- В отчёт помести скрины с вызовом и выводом использованной команды.
- ping ws22:<br>
<img src="./screens/7.8._ping_ws22.jpg" alt="ping ws22" width="500"/><br>

##### Добавь в файл ещё два правила:
##### 5) Включи **SNAT**, а именно маскирование всех локальных ip из локальной сети, находящейся за r2 (по обозначениям из Части 5 - сеть 10.20.0.0).
*Совет: стоит подумать о маршрутизации внутренних пакетов, а также внешних пакетов с установленным соединением.*
##### 6) Включи **DNAT** на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети.
*Совет: стоит учесть, что при попытке подключения возникнет новое tcp-соединение, предназначенное ws22 и 80 порту.*
- В отчёт помести скрин с содержанием изменённого файла.
- current firewall:<br>
<img src="./screens/7.9._firewall_dnat_snat.jpg" alt="dnat/snat in firewall" width="800"/><br>

##### Запусти файл также, как в Части 4.
- starting firewall:<br>
<img src="./screens/7.10._sh_firewall.jpg" alt="start firewall" width="500"/><br>

*Перед тестированием рекомендуется отключить сетевой интерфейс **NAT** (его наличие можно проверить командой `ip a`) в VirtualBox, если он включен.*
##### Проверь соединение по TCP для **SNAT**: для этого с ws22 подключиться к серверу Apache на r1 командой:
`telnet [адрес] [порт]`
- telnet r1 from ws22:<br>
<img src="./screens/7.11._telnet_r1.jpg" alt="telnet r1" width="500"/><br>

##### Проверь соединение по TCP для **DNAT**: для этого с r1 подключиться к серверу Apache на ws22 командой `telnet` (обращаться по адресу r2 и порту 8080).
- В отчёт помести скрины с вызовом и выводом использованных команд.
- telnet ws22 from r1:<br>
<img src="./screens/7.12._telnet_ws22.jpg" alt="telnet r1" width="500"/><br>

##### Сохрани дампы образов виртуальных машин
<p><a name="part7" href="#dumps">К дампам</a></p>

## Part 8. Дополнительно. Знакомство с **SSH Tunnels**

**== Задание ==**

*В данном задании используются виртуальные машины из Части 5.*

##### Запусти на r2 фаервол с правилами из Части 7.
<img src="./screens/8.1._sh_firewall.jpg" alt="start firewall" width="800"/><br>

##### Запусти веб-сервер **Apache** на ws22 только на localhost (то есть в файле */etc/apache2/ports.conf* измени строку `Listen 80` на `Listen localhost:80`).
<img src="./screens/8.2._ports_conf_apache_start.jpg" alt="start apache + ports.conf" width="800"/><br>

##### Воспользуйся *Local TCP forwarding* с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21.
- $ ssh -L [local_port]:[remote_host]:[remote_host_port] [remote_ip] -p [ssh_port]<br>
<img src="./screens/8.3._LocalTCP_forwarding.jpg" alt="telnet r1" width="800"/><br>

##### Воспользуйся *Remote TCP forwarding* c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11.
- $ ssh -R [remote_port]:[local_host]:[local_host_port] [remote_ip] -p [ssh_port]<br>
<img src="./screens/8.4._RemoteTCP_forwarding.jpg" alt="telnet r1" width="800"/><br>

##### Для проверки, сработало ли подключение в обоих предыдущих пунктах, перейди во второй терминал (например, клавишами Alt + F2) и выполни команду:
`telnet 127.0.0.1 [локальный порт]`
- В отчёте опиши команды, необходимые для выполнения этих четырёх пунктов, а также приложи скриншоты с их вызовом и выводом.
- Local TCP forwarding:<br>
<img src="./screens/8.5.1._LocalTCP_check.jpg" alt="telnet r1" width="800"/><br>
- Remote TCP forwarding:<br>
<img src="./screens/8.5.2._RemoteTCP_check.jpg" alt="telnet r1" width="800"/><br>

##### Сохрани дампы образов виртуальных машин.
<p><a name="part8" href="#dumps">К дампам</a></p>

ДАМПЫ ИЗ 4 части:<br>
<a name="dumps" href="#part4">К части 4</a><br>
- ws1:<br>
<img src="./screens/9._dumps_ws1.jpg" alt="ws1 dump" width="700"/><br>
- ws2:<br>
<img src="./screens/9._dumps_ws2.jpg" alt="ws2 dump" width="700"/><br>


ДАМПЫ ИЗ 5, 6, 7, 8 частей:<br>
<a name="dumps" href="#part5">К части 5</a><br>
<a name="dumps" href="#part6">К части 6</a><br>
<a name="dumps" href="#part7">К части 7</a><br>
<a name="dumps" href="#part8">К части 8</a><br>
- r1:<br>
<img src="./screens/9._dumps_r1.jpg" alt="r1 dump" width="700"/><br>
- r2:<br>
<img src="./screens/9._dumps_r2.jpg" alt="r2 dump" width="700"/><br>
- ws21:<br>
<img src="./screens/9._dumps_ws21.jpg" alt="ws21 dump" width="700"/><br>
- ws22:<br>
<img src="./screens/9._dumps_ws22.jpg" alt="ws22 dump" width="700"/><br>
- ws11:<br>
<img src="./screens/9._dumps_ws11.jpg" alt="ws11 dump" width="700"/><br>