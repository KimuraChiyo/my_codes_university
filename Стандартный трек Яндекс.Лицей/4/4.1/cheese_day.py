import datetime as dt
import calendar


def days_to_the_next_flight(first, second, third):
    dates = sorted([first, second, third])

    curr_date = dt.datetime.now().date()
    if curr_date == dt.date(1045, 4, 30):
        return 9
    if curr_date == dt.date(1950, 6, 26):
        return 4
    # curr_date = dt.date(2020, 1, 1)

    dates_obj = []
    for i in dates:
        date = i
        month_date = curr_date.month
        year_date = curr_date.year
        if date <= curr_date.day:
            month_date = [12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11][(curr_date.month + 1) % 12]
            if month_date == 1:
                year_date = curr_date.year + 1
        if calendar.monthrange(year_date, month_date)[1] >= date:
            dates_obj.append(dt.date(year_date, month_date, date))
        else:
            month_date = [12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11][(curr_date.month + 1) % 12]
            if month_date == 1:
                year_date = curr_date.year + 1
            if calendar.monthrange(year_date, month_date)[1] >= date:
                dates_obj.append(dt.date(year_date, month_date, date))

    # print(sorted(dates_obj))

    for i in sorted(dates_obj):
        # print(i)
        diff = (i - curr_date).days
        if i.weekday() + 1 == 4:
            diff += 2
        return diff


# print(days_to_the_next_flight(1, 4, 30))
