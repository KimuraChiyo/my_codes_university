// task 1 
{
    let browser = prompt("Введите свой браузер: ", 'Chrome')
    if (browser == 'Edge') {
        alert("You've got the Edge!");
    } else if (browser == 'Chrome' || browser == 'Firefox' || browser == 'Safari' || browser == 'Opera') {
        alert('Okay we support these browsers too');
    } else {
        alert("We hope that this page looks ok!")
    }
}
// task 2
{
    const number = +prompt('Введите число между 0 и 3', '');
    switch (number) {
        case 0: {
            alert("Вы ввели число 0");
            break;
        }
        case 1: {
            alert("Вы ввели число 1");
            break;
        }
        case 2: {
            alert("Вы ввели число 2, а может, и 3");
            break;
        }
        case 3: {
            alert("Вы ввели число 2, а может, и 3");
            break;
        }
        default: {
            alert("Вы ввели число не из заданного диапазона");
            break;
        }
    }
}