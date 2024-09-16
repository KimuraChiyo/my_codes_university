// task 7
{   
    function sum(arr) {
        let res = 0;
        for (let pos in arr) {
            res += arr[pos];
        }
        return res;
    }
    function func(string) {
        let regex = /[0-9]+/g;
        let result = string.match(regex);
        result = result.map(Number);
        return sum(result);
    }

    alert(func('Hello World! 1 23 JavaScript 456'));
}
