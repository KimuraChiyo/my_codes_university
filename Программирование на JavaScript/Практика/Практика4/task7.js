// part 7
{
    function func(a, b) {
        for (let key in a) {
            if (b[key]) {
                continue;
            }
            delete a[key];
        }
        return a;
    }
    let a = {
        'a': 'js',
        'b': 'html',
        'c': 'css'
    };
    let b = {
        'b': 'python' ,
        'c': 'pascal'
    };
    alert(`${printableObj(a)}`);
    alert(`${printableObj(b)}`);
    alert(`${printableObj(func(a, b))}`);
}