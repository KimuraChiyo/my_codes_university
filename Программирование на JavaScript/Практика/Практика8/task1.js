// task 1
{
    function func(sep) {
        let date = new Date();
        return `${date.getDate()}${sep}${date.getMonth() + 1}${sep}${date.getFullYear()}`
    }

    alert(func('/'));
    alert(func('-'));
}