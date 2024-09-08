// task 2
{
    function max(a, b) {
        return (a > b) ? a
                       : (a != b) ? b 
                                  : "Эти числа равны";
    }
    let a = 1, b = 2;
    alert(`a = ${a} \nb = ${b} \nmax(a, b) = ${max(a, b)}`);
    a = 3, b = 1;
    alert(`a = ${a} \nb = ${b} \nmax(a, b) = ${max(a, b)}`);
    a = 2; b = 2;
    alert(`a = ${a} \nb = ${b} \nmax(a, b) = ${max(a, b)}`);
}