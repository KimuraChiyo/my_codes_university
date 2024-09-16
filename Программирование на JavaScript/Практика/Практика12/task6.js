// task 6
{
    function func(num) {
        if (num > 0) {
            let sum;
            do {
                sum = (num % 10) + func(Math.floor(num / 10));
                num = sum;
            } while (sum > 9);
            return sum;
        } else {
            return 0;
        }
    }

    console.log(func(8));
    console.log(func(123456));
    console.log(func(12345678));
}