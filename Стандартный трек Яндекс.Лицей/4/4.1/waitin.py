import datetime as dt


def days_left(date):
    curr_date = dt.datetime.now().date()
    lst_date = date.split('.')
    input_data = dt.date(*map(int, lst_date[::-1]))
    return str(input_data - curr_date).split()[0]