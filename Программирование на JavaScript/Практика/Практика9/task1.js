// task 1
{
    let string = 'x1x x2x x3x x4x x5x xbx xvx';
    let regex = /x[0-9]x/g;
    let result = string.match(regex);
    alert(printableArray(result));
}