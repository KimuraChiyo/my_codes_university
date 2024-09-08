// task 2
{
    function isLeapYear(num) {
        if ((num % 400 == 0) || (num % 4 == 0 && num % 100 != 0)) {
            return true;
        }
        return false;
    }

    function func(startYear, endYear) {
        let string = ''
        for (let i = startYear; i < endYear + 1; i++) {
            if (isLeapYear(i)) {
                string += `${i} `;
            }
        }
        return string;
    }

    alert(func(2000, 2022));
}