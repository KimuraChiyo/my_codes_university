// task 3
{
    let string = 'aba aea aca aza axa';
    let regex = /a[bex]a/g;
    let result = string.match(regex);
    alert(printableArray(result));
}