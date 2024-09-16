// task 3
{ 
    function pow(x, n) {
        if (n >= 1) {
            let num = x;
            for (let i = 0; i < n - 1; i++) {
                num *= x;
            }
            return num;
        } else {
            return `Нормальные числа введи!`;
        }
    }
    
    alert(`pow(2, 3) = ${pow(2, 3)}`);
    alert(`pow(1, 3) = ${pow(1, 3)}`);
    alert(`pow(1, 0) = ${pow(1, 0)}`);
}

