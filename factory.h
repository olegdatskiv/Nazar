#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Car {
public:
	Car();
	Car(string &, string &, string &, int, int);
	virtual ~Car();
	string & getName();
	string & getType();
	string & getTransmission();
	int & getCount();
	int & getPrice();
	void Print();
private:
	string name_;
	string type_;
	string transmission_;
	int count_;
	int price_;
};
class Factory
{
public:
	Factory();
	virtual ~Factory();
	void ReadFile(string );
	void Show();
	void NumbOfCars();
	void RemoveCar();
	void CalculateSum();
	void ShowFactory();
	void ShowTruck();
private:
	map <string, vector<Car>> factory_;
};

