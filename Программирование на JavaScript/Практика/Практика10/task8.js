// task 8
{
    function func(num) {
        if (num >= 1000) {
            let cond = String(num).indexOf('.');
            let after_dot = '';
            if (cond != -1) {
                after_dot = String(num).slice(cond);
                num = String(num).slice(0, cond);
            }
            num = String(num).split('').reverse().join('');
            
            let regex = /\d{4}/g;
            while (regex.test(String(num))) {
                let result = num.match(regex);
                let rStr = result[0];
                let toStr = rStr.slice(0, rStr.length - 1) + ',' + rStr[rStr.length - 1];
                num = num.replace(rStr, toStr);
            }
            num = String(num).split('').reverse().join('') + after_dot;
        } else {
            alert('Слишком маленькое число');
        }
        return num;
    }

    alert(func(12345678.9111))
    alert(func(1234))
    alert(func(12345.67))
    alert(func(123456))
}
