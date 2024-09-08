import datetime as dt


def asteroid_angle(x):
    start_date = dt.date(2000, 1, 1)
    curr_date = dt.datetime.now().date()
    return round((int(str(curr_date - start_date).split()[0]) % x) / x * 360)
