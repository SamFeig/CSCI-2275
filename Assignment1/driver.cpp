#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Define struct for items
struct item {
	string for_sale = "";
	string type = "";
	int price = -1;
};

// Main function run
int main(int argc, char *argv[])
{
	//Assume there will be no more than 100 elements
	item items[100];
	// input file name
	ifstream myfile(argv[1]);
	string line;
	int cur_items = 0;
	while (getline(myfile,line))
	{
		stringstream ss(line);
    	string type;
    	string for_sale;
    	string price;
    	getline(ss, type, ',');
    	getline(ss, for_sale, ',');
    	getline(ss, price);
    	items[cur_items].type=type;
    	items[cur_items].for_sale=for_sale;
    	items[cur_items].price=stoi(price);
    	cur_items++;
  	}
  	cout<<"There are "<<cur_items<<" in the list";

  	// Logic goes here

	return 0;
}
