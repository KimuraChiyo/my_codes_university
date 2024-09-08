// task 6
{
    function factorial(num) {
        if (num >= 0) {
            let result = num == 0 ? 1 : num;
            for (let i = num - 1; i > 0; i--) {
                result *= i;
            }
             return result;
        } else {
            return `Нормальное число введи!`;
        }
    }
    alert( `factorial(0) = ${factorial(0)}`);
    alert( `factorial(1) = ${factorial(1)}`);
    alert( `factorial(5) = ${factorial(5)}`);
    alert( `factorial(6) = ${factorial(6)}`);
}