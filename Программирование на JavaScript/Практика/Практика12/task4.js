// task 4 
{
    function generateArray() {
        let arr = [];
        for (let i = 0; i < 10; i++) {
            arr.push(Math.floor(Math.random() * 9) + 1);
        }
        return arr;
    }
    function recursPrint(arr) {
        if (arr.length){
            console.log(arr.reverse().pop());
            return recursPrint(arr.reverse());
        } else {
            return 0;
        }
    }
    let arr = generateArray();
    let arr_cpy = arr;
    console.log(arr);
    recursPrint(arr_cpy);
}