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

    alert(`twosPower(2) = ${twosPower(2)}`);
    alert(`twosPower(4) = ${twosPower(4)}`);
    alert(`twosPower(8) = ${twosPower(8)}`);
    alert(`twosPower(16) = ${twosPower(16)}`);
    alert(`twosPower(32) = ${twosPower(32)}`);
    alert(`twosPower(5) = ${twosPower(5)}`);
    alert(`twosPower(9) = ${twosPower(9)}`);
}