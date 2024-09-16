// task 7
{   
    function func(o) {
        ro = {};
        for (key in o) {
            ro[o[key]] = key;
        }
        return ro;
    }

    let obj = {name: "Vasya", age: 25};
    console.log(func(obj));
}
