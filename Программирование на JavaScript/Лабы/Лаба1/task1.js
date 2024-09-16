// task 1
{
    let sign = undefined;
    let value = undefined;
    let prod = 1;
    for (let i = 0; i < 3; i++) {
        let default_num = (i == 0) ? 3 : ((i == 1) ? -7 : 2);
        prod *= +prompt(`Введите число ${i + 1}:`, default_num);
    }
    alert((prod / Math.abs(prod) == -1) ? '-' : '+' );
}
