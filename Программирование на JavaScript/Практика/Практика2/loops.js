// task 1
{
    let start = Number(prompt('Введите начало диапазона: ', 0));
    let end = Number(prompt('Введите конец диапазона: ', 10));
    for (let i = start; i <= end; i++) {
        console.log(`${i} - ${i % 2 ? 'нечетное': 'четное'}`);
    }
}
// task 2
{
    let max_num = 777777;
    let num = 0;
    let step = 1;

    while ((num + step) * (num + step) * (num + step) < max_num) {
        num += step;
    }

    console.log(`Искомое число: ${num}`);
}
// task 3
{
    let num = Number(prompt('Введите число: ', 246822));
    let num_cpy = String(num);
    let sum = 0;
    while (num > 0) {
        digit = num % 10;
        if (digit % 2 == 0) {
            sum += digit;
        }
        num = Math.floor(num / 10);
    }
    console.log(`Алгоритм 1: Сумма четных цифр числа равна ${sum}`);
    let sum2 = 0;
    for (let char of num_cpy) {
        if (Number(char) % 2 == 0) {
            sum2 += Number(char);
        }
    }
    console.log(`Алгоритм 2: Сумма четных цифр числа равна ${sum2}`);
}
