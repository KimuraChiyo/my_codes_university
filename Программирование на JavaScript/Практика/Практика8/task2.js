// task 2
{
    function func(month, year) {
        return new Date(year, month, 0).getDate();
    }
    alert(func(1, 2012)); 
    alert(func(2, 2012));
    alert(func(2, 2013));
    alert(func(12, 2012));
}