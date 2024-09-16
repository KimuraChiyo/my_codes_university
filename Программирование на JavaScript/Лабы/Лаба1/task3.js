// task 3
{
    for (let num = 100; num <= 999; num++) {
        let [hundreds, tens, ones] = String(num).split('');
        if ((hundreds ** 3 + tens ** 3 + ones ** 3) == num) {
            console.log(`Armstrong's num: ${num}`);
        }
    }
}
