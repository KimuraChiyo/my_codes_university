// task 4
{
    function func(string, num) {
        // не хотел через слайс))0))0)0
        let result = '';
        if (num > 0) {
            let i = 0;
            for (let pos in string) {
                result += string[pos];
                i++;
                if (i == num) {
                    break;
                }
            }
        }
        return result;
    }
    alert(func("Hello World", 4));
    alert(func("Hello World", 2));
}