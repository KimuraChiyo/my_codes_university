count = 3
set_goboy = set()
set_flute = set()
set_sax = set()
while count > 0:
    familia = input()
    while familia != '':
        if count == 3:
            set_goboy.add(familia)
        elif count == 2:
            set_flute.add(familia)
        elif count == 1:
            set_sax.add(familia)
        familia = input()
    count -= 1
all_set = set_goboy | set_flute | set_sax
set_goboy_flute = set_goboy & set_flute
set_flute_sax = set_flute & set_sax
set_goboy_sax = set_goboy & set_sax
set_all = set_goboy & set_flute & set_sax
need_set = all_set - set_goboy_flute - set_flute_sax - set_goboy_sax - set_all
print(*need_set, sep='\n')

