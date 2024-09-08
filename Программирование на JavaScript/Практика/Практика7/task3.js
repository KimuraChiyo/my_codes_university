// task 3.1
{
    function squares(n) {
        let arr = [];
        for (let i = 1; i <= n; i++) {
            arr[i - 1] = i * i;
        }
        return arr;
    }
    alert(printableArray(squares(10)))
}
// task 3.2
{
    function range(n, start, step) {
        let arr = [];
        for (let i = 0, num = start; i < n; i++, num += step) {
            arr.push(num);
        }
        return arr;
    }
    alert(printableArray(range(10, 0, 10)));
}
// task 3.3
{
    function random(n, min, max) {
        let arr = []
        for (let i = 0; i < n; i++) {
            arr.push(Math.floor(Math.random() * (max - min + 1)) + min);
        }
        return arr;
    }
    alert(printableArray(random(10, 10, 20)));
}
// task 3.4
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

    function primes(n) {
        let arr = [];
        let num = 2;
        while (arr.length < n) {
            if (isPrime(num)) {
                arr.push(num)
            }
            num++;
        }
        return arr;
    }
    alert(printableArray(primes(6)));
}