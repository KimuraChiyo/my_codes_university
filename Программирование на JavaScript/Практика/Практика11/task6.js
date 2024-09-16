// task 6
{
    function product(num1) {
        function calculate(num2) { return num2 * num1; }
        return calculate;
    }

    function sum(num1) {
        function calculate(num2) { return num2 + num1; }
        return calculate;
    }

    function difference(num1) {
        function calculate(num2) { return num2 - num1; }
        return calculate;
    }

    function quotient(num1) {
        function calculate(num2) { return num1 != 0 ? num2 / num1 : 'Exception: division by zero...'; }
        return calculate;
    }

    function zero(func1) { return func1 ? func1(0) : 0 }
    function one(func1) { return func1 ? func1(1) : 1; }
    function two(func1) { return func1 ? func1(2) : 2; }
    function three(func1) { return func1 ? func1(3) : 3; }
    function four(func1) { return func1 ? func1(4) : 4; }
    function five(func1) { return func1 ? func1(5) : 5; }
    function six(func1) { return func1 ? func1(6) : 6; }
    function seven(func1) { return func1 ? func1(7) : 7; }
    function eight(func1) { return func1 ? func1(8) : 8; }
    function nine(func1) { return func1 ? func1(9) : 9; }
    
    alert(three(quotient(zero())));
    alert(two(product(six())));
    alert(nine(difference(four())));
    alert(four(difference(five())));
    alert(eight(quotient(two())));
    alert(two(quotient(eight())));
    alert(three(sum(five())));
}
