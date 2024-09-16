// task 2
{
    function Car(carModel, kmPerLiter) {
        this.model = carModel,
        this.consumption = kmPerLiter,
        this.fuelTank = 0,
        this.odometer = 0
    }
    
    // I
    Car.prototype.refuel = function(liters) {
        this.fuelTank += liters;
    }
    // II
    Car.prototype.drive = function(distance) {
        let possible_dist = this.fuelTank * this.consumption;
        if (possible_dist >= distance) {
            this.odometer += distance;
            this.fuelTank -= distance / this.consumption;
            return `На одометре ${this.odometer} км, в топливном баке ${this.fuelTank} литров топлива`
        } else {
            this.odometer += possible_dist;
            this.fuelTank = 0;
            return `Закончилось топливо после преодоления ${possible_dist} км. На одометре ${this.odometer} км. Осталось ${this.fuelTank} литров топлива`
        }
    }
    // tests
    let car = new Car('c', 1);
    car.refuel(10);
    console.log(car.drive(5));
    console.log(car.drive(5));
    car.refuel(10);
    console.log(car.drive(10));
    car.refuel(10);
    console.log(car.drive(20));
}