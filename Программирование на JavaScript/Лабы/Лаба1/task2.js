// task 2
{
    for (let num = 1; num < 101; num++) {
        let result = '';
        if (num % 3 == 0) {
            result += 'Fizz';
        } 
        if (num % 5 == 0) {
            result += 'Buzz';
        }
        if (num % 3 && num % 5) {
            result += num;
        }
        console.log(result);
    }
}
