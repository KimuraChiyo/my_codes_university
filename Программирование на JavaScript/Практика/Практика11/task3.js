// task 3
{
    function square(num) {
        return num * num;
    }
    function cube(num) {
        return num * num * num;
    }

    function add(num, func1, func2) {
        return func1(num) + func2(num);
    }

    alert(add(2, square, cube));
}
