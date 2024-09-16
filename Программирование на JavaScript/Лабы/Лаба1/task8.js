// task 8
{
    let prod = 1;
    for (let i = 2; i < 11; i++) {
        let sum = 1;
        for (let j = 2; j <= i; j++) {
            sum += j;
        }
        prod *= sum;
    }
    console.log(prod)
}

