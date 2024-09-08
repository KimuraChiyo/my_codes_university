// task 4
{
    let string = '‘aba aea aca aza axa a.a a+a a*a';
    let regex = /a[b.+*]a/g;
    let result = string.match(regex);
    alert(printableArray(result));
}