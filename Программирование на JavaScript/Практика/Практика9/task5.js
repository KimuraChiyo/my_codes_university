// task 5
{
    let string = 'aaa aBa aca aDa afa aZa aga';
    let regex = /a[A-f]a/g;
    let result = string.match(regex);
    alert(printableArray(result));
}