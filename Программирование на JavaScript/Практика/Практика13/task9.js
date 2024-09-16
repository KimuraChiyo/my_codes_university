// task 9
{
    function func(o1, o2) {
        let set = new Set();
        for (let o1elem of o1) {
            for (let o2elem of o2) {
                if (o2elem.includes(o1elem)) {
                    set.add(o1elem);
                }
            }
        }
        return Array.from(set).sort()
    }

    let A = ['some', 'less', 'hold', 'absence'];
    let B = ['stronghold', 'wireless', 'seamless', 'lonesome','troublesome','script','algorithm'];
    console.log(func(A, B)) // ['hold', 'less', 'some']
}