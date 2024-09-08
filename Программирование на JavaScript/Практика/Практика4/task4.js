// task 4
{
    function multTen(obj) {
        for (let key in obj) {
            if (isNaN(obj[key])) {
                continue;
            }
            obj[key] *= 10;
        }
    }

    let salaries = {
        Adam: 250,
        Bob: 350,
        Cindy: 400,
        Donald: "Fired"
    };

    alert(printableObj(salaries));
    multTen(salaries);
    alert(printableObj(salaries));
}