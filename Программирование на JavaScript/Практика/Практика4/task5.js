// task 5
{
    function func(obj) {
        for (let key in obj) {
            return false;
        }
        return true;
    }

    let object1 = {};
    alert(`${printableObj(object1)}func(object1) = ${func(object1)}`);
    object1.name = 'object1';
    alert(`${printableObj(object1)}func(object1) = ${func(object1)}`);
}