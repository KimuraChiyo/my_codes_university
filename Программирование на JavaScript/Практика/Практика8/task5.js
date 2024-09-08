// task 5
{
    function addWeeks(date, count) {
        return new Date(date.getTime() + 1000 * 60 * 60 * 24 * 7 * count);
    }

    alert(addWeeks(new Date(), 1));
}