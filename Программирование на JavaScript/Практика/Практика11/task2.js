// task 2
{
    function square(num) {
        return num * num;
    }

    function func(num, func1) {
        return func1(num);
    }

    alert(func(func(func(2, square), square), square));

}