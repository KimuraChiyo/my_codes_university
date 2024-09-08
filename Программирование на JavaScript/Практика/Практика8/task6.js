// task 6
{
    function isLeapYear(year) {
        return (new Date(year, 2, 0).getDate()) == 29;
    }

    alert(isLeapYear(1896));
    alert(isLeapYear(1900));
    alert(isLeapYear(1904));
}