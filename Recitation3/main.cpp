#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

class Vehicle{
	public:
		int capacity;
		int num_wheels;
		int max_speed;
	void print_details(){
		cout<<"This is a vehicle"<<endl;
		cout<<"Capacity: "<<capacity<<endl;
		cout<<"Number of wheels: "<<num_wheels<<endl;
		cout<<"Maximum speed: "<<max_speed<<endl;
	}

	bool will_people_fit(int c){
		if(c>capacity){
			return false;
		}
		else{
			return true;
		}
	}
};

// 3 access types here public, private, protected
class Bike : public Vehicle{
	public:
		int num_gears;
	void print_details(){
		// Call the base class printer method
		Vehicle::print_details();
		cout<<"This vehicle is a Bike"<<endl;
		cout<<"Number of gears: "<<num_gears<<endl;
	}
};

class Car : public Vehicle {
public:
	string brand;
	string model;
	int year;
	void print_details(){
		Vehicle::print_details();
		cout<<"This vehicle is a Car"<<endl;
		cout<<"Brand "<<brand<<endl;
		cout<<"Model "<<model<<endl;
		cout<<"Year "<<year<<endl;
	}
};

// Implement a derived class for car where variables are brand, model and make_year

int main(int argc, char ** argv){
	Car c[101];
	ifstream myfile(argv[1]);
	string line;
	int i = 0;
	while (getline(myfile,line)) {
		stringstream ss(line);
		string brand;
		string model;
		string year;
		string capacity;
		string numWheels;
		string speed;

		getline(ss, brand, ',');
		getline(ss, model, ',');
		getline(ss, year, ',');
		getline(ss, capacity, ',');
		getline(ss, numWheels, ',');
		getline(ss, speed, ',');

		c[i].brand = brand;
		c[i].model = model;
		c[i].year = stoi(year);
		c[i].capacity = stoi(capacity);
		c[i].num_wheels = stoi(numWheels);
		c[i].max_speed = stoi(speed);
		i++;
	}

	for(int j = 0; j < i; j++) {
		if(c[j].capacity >= 4) {
			c[j].print_details();
			cout<<endl;
		}
	}
	return 0;
}