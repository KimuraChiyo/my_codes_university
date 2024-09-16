// task 6
{
    let regex = / ([a-zA-Z])[a-zA-Z]*\1/g;

    let string = 'pushp pop avada lopap';
    let res = (' ' + string).match(regex);
    res.forEach((elem, pos) => {
        res[pos] = elem.replace(/ /g, '');
    });
    alert(printableArray(res));
}