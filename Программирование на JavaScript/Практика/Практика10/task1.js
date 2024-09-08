// task 1
{
    function func(string) {
        string = string.replace(/[ ]+/g, ' ');
        return string;
    }
    alert(func('Hello       World      Javascript'))
}