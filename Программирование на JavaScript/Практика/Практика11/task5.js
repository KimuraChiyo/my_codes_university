// task 5
{
    function createPass(str1) {
        function guessPass(str2) {
            return str1 == str2;
        }

        return guessPass;
    }


    let guess = createPass('123');
    console.log(guess('123'));
    console.log(guess('1234'));
}
