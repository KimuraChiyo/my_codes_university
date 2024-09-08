// task 7
{
    function func(dateStr1, dateStr2) {
        let [month1, day1, year1] = dateStr1.split('/');
        let [month2, day2, year2] = dateStr2.split('/');
        [month1, day1, year1, month2, day2, year2].forEach(Number);
        let date1 = new Date(year1, month1 - 1, day1);
        let date2 = new Date(year2, month2 - 1, day2);
        return Math.abs(date1 - date2) / (1000 * 60 * 60 * 24);
    }

    alert(func('01/01/2020', '02/20/2020'));
}