// task 3
{
    const obj = {three: 3, two: 2, five: 5, four: 4};
    let arr = Array.from(Object.keys(obj), (x) => [x, obj[x]]).sort(function(a, b) { return a[1] - b[1]; })
    console.log(JSON.stringify(Object.fromEntries(arr), null, 2))
}