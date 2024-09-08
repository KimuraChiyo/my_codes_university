// task 3
{
    function func(n) {
        if (n >= 1) {
            let sum = 0;
            let top = 1;
            let bottom = 1;
            for (let i = 0; i < n; i++, bottom += 3) {
                sum += (top / bottom);
            }
            return sum.toFixed(2);
        } else {
            return "Натуральное число введи да";
        }
    }

    alert(func(1));
    alert(func(2));
    alert(func(5));
}