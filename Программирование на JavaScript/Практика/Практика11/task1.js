// task 1
{
    function f1() {
        return 1;
    }

    function f2() {
        return 2;
    }
    
    function f3() {
        return 3;
    }

    function func(func1, func2) {
        return func1() + func2();
    }

    alert(func(f1, f2));
    alert(func(f2, f3));
    alert(func(f1, f3));
}