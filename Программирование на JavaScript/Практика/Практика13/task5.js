// task 5
{
    function getMethods(obj) { 
        let arr = []
        for (let key of Reflect.ownKeys(obj)) {
            if (typeof key == 'string' && String(obj[key]).includes('function')) {
                arr.push(key);
            }
        }
        return arr;
    }

    console.log(getMethods(String.prototype));
}