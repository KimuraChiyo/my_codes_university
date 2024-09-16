// task 6
{
    function func(o1, o2) {
        o = {};
        for (key in o1) {
            if (o2.hasOwnProperty(key)) {
                o[key] = o1[key] == o2[key] ? o1[key] : [o1[key], o2[key]];
            }
        }
        return o;
    }

    let obj12 = {one: 1, two: 2, three: 3};
    let obj23 = {two: 2, three: 3, four: 4};

    console.log(func(obj12, obj23))
}