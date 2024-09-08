// task 3
{
    function randomString() {
        let string = '';
        for (let i = 0; i <= 5; i++) {
            string += (Math.floor(Math.random() * 100) + 1);
            if (i % 2) {
                string += i < 5 ? '= ' : '=';
            } else {
                string += '+';
            }
        }
        return string;
    }

    function equalize(string) {
        string += ' ';
        let regex = /[0-9]+\+[0-9]+/y;
        while (/= /.test(string)) {
            let res = regex.exec(string);
            string = string.replace(/= /, `=${eval(res.toString())} `);
            regex.lastIndex += res.toString().length;
        }
        return string;
    }

    let string = randomString();
    alert(equalize(string));
    alert(equalize('1+2= 3+4= 5+6='));
}