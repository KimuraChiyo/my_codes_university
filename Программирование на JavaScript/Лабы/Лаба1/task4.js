// task 4
{
    let a = +prompt('Введите a: ', 372);
    let b = +prompt('Введите b: ', 248);
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    console.log(a + b);
}
