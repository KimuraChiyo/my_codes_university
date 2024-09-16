// task 4
{
    function generateArray() {
        let arr = [];
        for (let i = 0; i < 10; i++) {
            arr.push(Math.floor(Math.random() * 9) + 1);
        }
        return arr;
    }
    function cube(arr) {
        arr.forEach((element, i) => {
            arr[i] = element ** 3;
        });
        return arr;
    }

    function func(arr, func1) {
        return func1(arr);
    }

    console.log(func(generateArray(), cube))
}