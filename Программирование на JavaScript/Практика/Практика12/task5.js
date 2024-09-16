// task 5
{

    function generateArray(n) {
        let arr = [];
        for (let i = 0; i < n; i++) {
            arr.push(Math.floor(Math.random() * 200) + (-100));
        }
        return arr;
    }

    function recMax(arr) {
        if (arr.length) {
            let arr_num = arr.reverse().pop();
            function max(num1, num2) {
                return num1 > num2 ? num1 : num2;
            }
            return max(arr_num, recMax(arr.reverse()));
        } else {
            return 0;
        }
    }

    let arr = generateArray(10);
    let arr_cpy = arr;
    console.log(arr);
    console.log(recMax(arr_cpy))
}