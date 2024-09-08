// task 1
{
    let num = prompt("Введите число: ", 0)
    let result = 0;
    if (num != 0) result = 1 * (num / Math.abs(num))
    alert(`Conditional: Результат для этого числа равен ${result}`)
}
// task 2
{
    let a = prompt("Введите a: ", 0);
    let b = prompt("Введите b: ", 0);
    let result;
    result = ((a + b) < 4) ? 'Мало': 'Много';
    alert( `Conditional: result = ${result}`)
}
// task 3
{
    let login = prompt("Введите логин: ", 'Директор');
    let message;
    message = (login == 'Сотрудник') ? 'Привет' : ((login == 'Директор') ? 'Здравствуйте' : ((login == '') ? 'Нет логина' : '')) ;
    alert( `Conditional: message = "${message}"`)
}