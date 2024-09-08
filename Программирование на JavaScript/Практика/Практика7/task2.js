// task 2
{
    function getMatrix(n, m) {
        let matrix = [];
        for (let i = 0; i < n; i++) {
            matrix.push([]);
            for (let j = 0; j < m; j++) {
                matrix[i].push(Math.floor(Math.random() * 10))
            }
        }
        return matrix;
    }
    function printableMatrix(matrix, n, m) {
        let string = '';
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                string += matrix[i][j] + ' ';
            }
            string += '\n';
        }
        return string;
    }

    alert(printableMatrix(getMatrix(4, 4), 4, 4));
}