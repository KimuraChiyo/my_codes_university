// task 2
{
    function randomString() {
        let string = '';
        for (let i = 0; i < 5; i++) {
            string += (Math.floor(Math.random() * 9) + 1);
            if (i != 4) {
                string += ' ';
            }
        }
        return string;
    }

    function replaceWithSquares(string) {
        string = ' ' + string + ' ';
        console.log(string);
        for (let i = 9; i >= 1; i--) {
            let regex = new RegExp(String.raw`\s${i}\s`, "g");
            string = string.replace(regex, ` ${i * i} `);
        }
        return string.slice(1, string.length - 1);
    }

    let string = randomString();
    alert('"' +string + '" -> "' + replaceWithSquares(string) + '"');
}