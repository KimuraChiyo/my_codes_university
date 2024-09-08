// task 1
{
    function insertEvenDash(num) {
        let result = '';
        string = String(num);
        let flag = 0;
        for (let i = 0; i < string.length; i++) {
            if (string[i] % 2 == 0) {
                if (flag) {
                    result += '-' + string[i];
                    continue;
                }
                result += string[i];
                flag = 1;
            } else {
                result += string[i];
                if (flag) {
                    flag = 0;
                }
            }
        }
        return result;
    }

    alert(insertEvenDash(827468124208));
}