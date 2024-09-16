// task 7
{
    function retNumForEquation(num, pos) {
        let positions = ['x^2', 'x', ''];
        let sign = num > 0 ? '+ ' : '- ';
        if (pos == 1 && num > 0) {
            sign = '';
        }
        return sign + Math.abs(num) + positions[pos - 1];
    }

    function squareEquation(a, b, c) {
        let discriminant = b * b - 4 * a * c;
        let equation = `${retNumForEquation(a, 1)} ${retNumForEquation(b, 2)} ${retNumForEquation(c, 3)} = 0\n`;
        let count = '';
        let x1 = '';
        let x2 = '';
        if (discriminant > 0) {
            count = `Два разных корня\n`;
            x1 = `x1 = ${((-b + Math.sqrt(discriminant)) / (2 * a))}\n`;
            x2 = `x2 = ${((-b - Math.sqrt(discriminant)) / (2 * a))}\n`;
        } else if (discriminant == 0) {
            count = `Два равных корня\n`;
            let result = a != 0 ? ((-b + Math.sqrt(discriminant)) / (2 * a)) : 0;
            x1 = `x1 = ${result}\n`;
            x2 = `x2 = ${result}\n`;
        } else {
            count = `Два иррациональных корня\n`;
        }

        return equation + count + x1 + x2;
    }
    
    alert(`squareEquation(1, -8, 0):\n${squareEquation(1, -8, 0)}`);
    alert(`squareEquation(1, -8, 16):\n${squareEquation(1, -8, 16)}`);
    alert(`squareEquation(1, -8, 17):\n${squareEquation(1, -8, 17)}`);
    alert(`squareEquation(1, 1, 1):\n${squareEquation(1, 1, 1)}`);
    alert(`squareEquation(-1, -1, -1):\n${squareEquation(-1, -1, -1)}`);
}

