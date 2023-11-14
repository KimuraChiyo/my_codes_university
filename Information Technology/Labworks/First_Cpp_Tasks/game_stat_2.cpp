#include <iostream>
int main() {

	float fuel, speed, s, time, S; double consumed, remained; char q, a;
	std::cout << "How much fuel do you have at start? "; std::cin >> fuel;
	if ((fuel < 0) || (50 <= fuel)) {
		std::cout << "\nInvalid data.";
		return 0;
	}

	std::cout << '\n' << "Car stats" << '\n';
	std::cout << "Fuel: " << fuel << '\n';
	std::cout << "Fuel capacity: 50" << '\n';
	std::cout << "Fuel consumption: 0\n";
	std::cout << "Speed: 0" << '\n';
	std::cout << "Maximum speed: 110\n\n";
	std::cout << "Route info\n";
	std::cout << "Distance: 360 km\n";
	std::cout << "----------------------------------------\n";
	std::cout << "You have to drive a route 360 km long.\n";
	std::cout << "But first you need to check if you have enough fuel\n\n";

	std::cout << "Do you need a refill? "; std::cin >> q;
	if (q == 'y') {
		std::cout << "\nChoose an option.\n";
		std::cout << "a. 10 litres\n";
		std::cout << "b. 20 litres\n";
		std::cout << "c. 30 litres\n";
		std::cout << "d. custom amount\n\n";

		std::cout << "Your choice: "; std::cin >> a;
		switch (a) {
		case 'a': {
			fuel += 10;
			break;
		}
		case 'b': {
			fuel += 20;
			break;
		}
		case 'c': {
			fuel += 30;
			break;
		}
		case 'd': {
			int needed;
			std::cout << "\nHow much fuel do you need? "; std::cin >> needed;
			fuel += needed;
			break;
		}
		}
	}

	std::cout << "Your fuel before start: " << fuel << "\n\n";

	if (fuel > 50) {
		std::cout << "Game over. Too much gas!";
		return 0;
	}

	std::cout << "What speed will you choose? "; std::cin >> speed;
	if (speed > 110)
		speed = 110;
	if (speed < 0) {
		std::cout << "Invalid data.";
		return 0;
	}
	std::cout << "Your speed before start: " << speed << " km/h\n";

	float A, b, c;
	std::cout << "\nType in equation parameters.";
	std::cout << "\na = "; std::cin >> A;
	std::cout << "b = "; std::cin >> b;
	std::cout << "c = "; std::cin >> c;

	s = speed / 10;
	double fuelConsumption = s * s * A + b * s + c;
	if (speed == 0)
		fuelConsumption = 0;
	std::cout << "\nFuel consumption with chosen speed: " << fuelConsumption << " litres per 100 km\n\n";

	
	double need_fuel = fuelConsumption * 3.6;
	if (need_fuel <= fuel) {
		S = 360; 
		time = (int)((S / speed) * 3600);
		consumed = fuelConsumption * 3.6;
		remained = fuel - consumed;
	}
	else {
		if (fuelConsumption != 0) {
			S = (100 / fuelConsumption) * fuel;
			consumed = fuel;
			time = (int)((S / speed) * 3600);
			remained = 0;
		} else {
			S = 0;
			consumed = 0;
			time = 0;
			remained = fuel;
		}
	}

	std::cout << "Destination result" << '\n';
	std::cout << "Distance traveled: " << S << " km" << '\n';
	std::cout << "Time spent: " << (int) (time / 3600) << " h ";
	std::cout << (((int) time % 3600 / 60)) << " min ";
	std::cout << ((int) time % 60) << " sec.\n";
	std::cout << "Fuel consumed: " << consumed << " litres" << '\n';
	std::cout << "Fuel remained: " << remained << " litres" << '\n';
	std::cout << "----------------------------------------" << '\n';

	if (S == 360) {
		std::cout << "Congratulations! You have reached destination point!\n";
	}
	else {
		int count = ((int)((360 - S) / 0.001));
		if (count % 10 >= 5) {
			count /= 10;
			count += 1;
		}
		else
			count /= 10;
		std::cout << "You haven't reached destination point. " << (float) count / 100 << " km left.\n";
	}

	int opt_speed = 0;
	for (float i = 0; i <= 110; i++) {
		if ((2 * A * (i / 10) + b) == 0) {
			opt_speed = i;
		}
	}
	
	std::cout << "\nThe optimal speed for that car is " << opt_speed << " km/h.\n";
	std::cout << "With that speed:\n   ";
	s = opt_speed / 10;
	fuelConsumption = s * s * A + b * s + c;
	std::cout << "Fuel consumption would be " << fuelConsumption << " per 100 km.\n   ";
	std::cout << "You need " << fuelConsumption * 3.6 << " l of fuel to reach your destination.\n   ";
	int saved_fuel = 0;
	saved_fuel = (int)((consumed - fuelConsumption * 3.6) * 1000);
	while (saved_fuel % 100 != 0) {
		saved_fuel += 1;
	}
	if (saved_fuel > 0) {
		std::cout << "You could save " << (float)saved_fuel / 1000 << " l of fuel.\n   ";
		std::cout << "It would take " << ((360 / opt_speed) * 3600) / 3600 << " h " << (((360 / opt_speed) * 3600) % 3600) / 60 << " min " << (((360 / opt_speed) * 3600) % 60) << "sec.";
	}
	else {
		std::cout << "You wouldn't reach your destination anyway, but you could drive " << (100 / fuelConsumption) * fuel - S << " kms more.";
	}
	return 0;
}