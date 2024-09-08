// task 5
{
    let string = 'aaa aBa aca aDa afa aZa aga';
    let regex = /a[a-fA-Z]a/g;
    let result = string.match(regex);
    alert(printableArray(result));
}