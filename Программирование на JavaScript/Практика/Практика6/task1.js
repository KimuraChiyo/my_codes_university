// task 1
{
    function twosPower(num) {
        while (num > 1) {
            if (num % 2) {
                return false;
            } else {
                num /= 2;
            }
        }
        return true;
    }

    alert(`twosPower(16) = ${twosPower(16)}`);
    alert(`twosPower(32) = ${twosPower(32)}`);
    alert(`twosPower(9) = ${twosPower(9)}`);
}