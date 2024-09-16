// task 4
{
    function func(num, arr) {
        let retArr = [];
        for (let pos in arr) {
            let divisor = arr[pos];
            let countOccurance = Math.floor((num / divisor));
            for (let i = 0; i < countOccurance; i++) {
                retArr.push(divisor);
            }
            num -= countOccurance * divisor;
        }
        return retArr;
    }


    alert(printableArray(func(96, [25, 10, 5, 2, 1])));
}
