// task 5
{
    function func(string) {
        let ascii_code_capitalize = string[0].charCodeAt(0) + ('A'.charCodeAt(0) - 'a'.charCodeAt(0));
        let res = '';
        for (let pos in string) {
            if (pos == 0) {
                res += String.fromCharCode(ascii_code_capitalize);
                continue;
            }
            res += string[pos];
        }
        return res;
    }
    
    alert(func("hello world"));

}