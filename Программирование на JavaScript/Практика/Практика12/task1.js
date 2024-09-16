// task 1
{
    function func(num1) {
        if (num1 == 1) {
            return 1;
        } else {
            return num1 + func(num1 - 1);
        }
    }
    alert(func(5))
}