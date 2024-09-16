// task 7
{
    let regex = /[A-z]+/g;

    let string = 'sayHi() checkAge() showMessage()';
    let res = string.match(regex);
    alert(printableArray(res));
}