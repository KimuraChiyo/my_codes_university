// task 2
{
    let string = 'x1x x22x x333x x4444x x55555x xx xcx xtpx';
    let regex = /x[0-9]*x/g;
    let result = string.match(regex);
    alert(printableArray(result));
}