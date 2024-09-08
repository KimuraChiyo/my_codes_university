// task 8
{
    function func(string) {
        let regex = /[a-zA-Z0-9?.,;!]+[ ?.,;!]+/g;
        return string.match(regex).length;
    }
    alert(func('Oh, hey there! What is going on? Tell me.'));
}