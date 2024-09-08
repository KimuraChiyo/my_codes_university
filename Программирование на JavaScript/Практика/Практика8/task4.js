// task 4
{
    function func(dateStr) {
        let [month, day, year] = dateStr.split(' ');
        day = day.slice(0, day.length - 1);
        let arr = {
            'Jan': 0,
            'Feb': 1,
            'Mar': 2,
            'Apr': 3,
            'May': 4,
            'Jun': 5,
            'Jul': 6,
            'Aug': 7,
            'Sep': 8,
            'Oct': 9,
            'Nov': 10,
            'Dec': 11
        }
        return new Date(Number(year), Number(arr[month]), Number(day) - 1).getDay() > 4;
    }

    alert(func('Oct 17, 2020'));
    alert(func('Sep 1, 2020'));
}