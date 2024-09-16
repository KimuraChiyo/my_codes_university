// task 5
{
    let sum = 0;
    for (let i = 1; i <= 1000; i++) {
        sum += ((!(i % 3) || !(i % 5)) && (i % 15)) ? i : 0;
    }
    console.log(sum);
}
