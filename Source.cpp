#include "factory.h"

int main() {
	
	Factory f;
	f.ReadFile("info.txt");
	f.Show();
	f.NumbOfCars();
	f.RemoveCar();
	f.Show();
	f.CalculateSum();
	f.ShowFactory();
	f.ShowTruck();
	system("pause");
	return 0;
}