// task 8
{
    function isPrime(num) {
        let result = true;
        for (let i = 2; i <= Math.floor(Math.sqrt(num)); i++) {
            if (num % i == 0) {
                result = false;
                break;
            }
        }
        return result;
    }

    for (let i = 2; i < 12; i++)
        alert(`Число ${i} является простым ${isPrime(i)}`);
}
