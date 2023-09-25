import datetime as dt


def alarm(date, delta=10):
    deltatime = dt.timedelta(minutes=delta)
    start_date = dt.date(2021, 1, 4)
    date = dt.date(*map(int, date.split('-')))

    if date == dt.date(2021, 1, 4):
        ord_day = 1
    else:
        ord_day = int(str(date - start_date).split()[0]) + 1

    day = ord_day % 7
    week = (ord_day - 1) // 7 + 1

    if week % 2:
        if day in [1, 2, 3, 5]:
            start_time = dt.timedelta(hours=8, minutes=30)
            supp_time = start_time + deltatime
            start_time = str(start_time)
            supp_time = str(supp_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'), supp_time[:supp_time.rfind(':')].rjust(5, '0')
        elif day == 4:
            start_time = dt.timedelta(hours=7, minutes=45)
            supp_time = start_time + deltatime
            start_time = str(start_time)
            supp_time = str(supp_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'), supp_time[:supp_time.rfind(':')].rjust(5, '0')
        else:
            start_time = dt.timedelta(hours=10)
            start_time = str(start_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'),
    else:
        if day in [1, 2, 5]:
            start_time = dt.timedelta(hours=9)
            supp_time = start_time + deltatime
            start_time = str(start_time)
            supp_time = str(supp_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'), supp_time[:supp_time.rfind(':')].rjust(5, '0')
        elif day in [3, 4]:
            start_time = dt.timedelta(hours=9, minutes=30)
            supp_time = start_time + deltatime
            start_time = str(start_time)
            supp_time = str(supp_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'), supp_time[:supp_time.rfind(':')].rjust(5, '0')
        else:
            start_time = dt.timedelta(hours=11)
            start_time = str(start_time)
            need = start_time[:start_time.rfind(':')].rjust(5, '0'),
    return need
