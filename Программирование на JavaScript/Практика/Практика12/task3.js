// task 3
{
    function func(num1, num2) {
        if (num1) {
            return 1 + func(num1 - 1, num2);
        } else {
            if (num2) {
                return 1 + func(num1, num2 - 1);
            } else {
                return 0;
            }
        }
    }

    alert(func(12, 21));
    alert(func(21, 21));
}