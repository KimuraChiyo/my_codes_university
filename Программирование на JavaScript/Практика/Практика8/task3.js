// task 3
{
    function func(date) {
        return date.toLocaleString('en-US', {month: "long"});
    }

    alert(func(new Date("08/25/2009")));
}