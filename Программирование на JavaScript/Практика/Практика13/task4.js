// task 4
{
    function sum(json) {
        let sum = 0;
        for (let key in json) {
            sum += json[key];
        }
        return sum;
    }
    function func(string) {
        let json = JSON.parse(string);
        let part_weigth = 360 / sum(json);
        for (let key in json) {
            json[key] *= part_weigth;
        }
        return json;
    }


    let string = '{"A": 4, "B" : 5, "C" : 6, "D" : 1, "E" : 4}';
    console.log(func(string));
}