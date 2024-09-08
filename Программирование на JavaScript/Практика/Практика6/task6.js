// task 6
{
    function func(char, string) {
        let count = 0;
        string = string.toLowerCase();
        for (let pos in string) {
            if (string[pos] == char) {
                count++;
            }
        }
        return count;
    }

    alert(func("a", "Amsterdam is the capital of the Netherlands"));
}