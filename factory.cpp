#include "factory.h"
Car::Car(){}
Car::Car(string &name, string &type, string &transmission, int count, int price) : 
		name_(name), type_(type), transmission_(transmission), count_(count), price_(price){}
Car::~Car(){}
string & Car::getName(){
	return name_;
}
string & Car::getType(){
	return type_;
}
string & Car::getTransmission(){
	return transmission_;
}
int & Car::getCount(){
	return count_;
}
int & Car::getPrice(){
	return price_;
}
void Car::Print() {
	cout << name_ << "\t" << type_ << "\t" << transmission_ << "\t" << count_ << "\t" << price_ << endl;
}
Factory::Factory(){

}
Factory::~Factory(){

}
void Factory::ReadFile(string file_name){
	fstream file;
	file.open(file_name, ios_base::in);
	if (!file.is_open()) {
		cout << "Can`t open file!" << endl;
		return;
	}
	while (!file.eof()) {
		Car new_car;
		string factory_name;
		file >> factory_name;
		file >> new_car.getName();
		file >> new_car.getType();
		file >> new_car.getTransmission();
		file >> new_car.getCount();
		file >> new_car.getPrice();
		if (factory_.find(factory_name) != factory_.end()) {
			factory_[factory_name].push_back(new_car);
		}
		else {
			factory_.insert(pair<string, vector<Car>>(factory_name, vector<Car>()));
		}
		
	}
}
void Factory::Show() {
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		cout << "Factory : " << iter->first << endl;
		for (int i = 0; i < iter->second.size(); i++) {
			sort(iter->second.begin(), iter->second.end(), [](Car &a, Car &b)->bool{return a.getPrice()<b.getPrice(); });
			iter->second[i].Print();
		}
	}
}
void Factory::NumbOfCars() {
	int min, max;
	cout << "Enter min and max price:" << endl;
	cin >> min >> max;
	cout << "Count of cars:" << endl;
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		cout << "Factory : " << iter->first << endl;
		int n = 0;
		for (int i = 0; i < iter->second.size(); i++) {
			if (iter->second[i].getPrice() >= min && iter->second[i].getPrice() <= max) {
				n += iter->second[i].getCount();
			}
		}
		cout << "Count : " << n << endl;
	}
}
void Factory::RemoveCar() {
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		for (auto car = iter->second.begin(); car != iter->second.end(); ) {
			if (car->getTransmission() == "Manual_Transmission") {
				car=iter->second.erase(car);
			}
			else {
				car++;
			}
		}
	}
}
void Factory::CalculateSum() {
	int sum = 0;
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		for (int i = 0; i < iter->second.size(); i++) {
			if (iter->second[i].getType() == "Car") {
				sum += iter->second[i].getPrice()*iter->second[i].getCount();
			}
		}
	}
	cout << "Price of all cars: " << sum << endl;
}
void Factory::ShowFactory() {
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		for (int i = 0; i < iter->second.size(); i++) {
			if (iter->second[i].getTransmission() == "Automatic_Transmission") {
				cout << "Factory : " << iter->first << endl;
				break;
			}
		}
	}
}
void Factory::ShowTruck() {
	map<string, Car> trucks;
	for (auto iter = factory_.begin(); iter != factory_.end(); iter++) {
		for (int i = 0; i < iter->second.size(); i++) {
			if (iter->second[i].getType() == "Truck") {
				trucks.insert(pair<string, Car>(iter->second[i].getName(), iter->second[i]));
			}
		}
	}
	cout << "Cars : " << endl;
	for (auto iter = trucks.begin(); iter != trucks.end(); iter++) {
		cout << iter->first << endl;
	}
}