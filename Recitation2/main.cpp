#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//Creating a struct data type: a template to define all instances
struct CarData {
    string model;
    string make;
    string year;
};

int main(int argc, char* argv[]) {
    CarData carArray[10];

    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open(argv[1]); //open the file

    if(inFile.is_open()) {  //error check
        cout << "opened successfully" << endl;
        int cur_items = 0;
        while(getline(inFile,line)) {
            stringstream ss(line);
            string make;
            string model;
            string year;

            getline(ss, carArray[cur_items].make, ' ');
            getline(ss, carArray[cur_items].model, ' ');
            getline(ss, carArray[cur_items].year, ' ');
            cur_items++;
        }
        inFile.close(); //close the file
    }
    else {
        cout << "File unsuccessfully opened" << endl;
    }
    cout <<"Array: " <<endl;
    for(int i = 0 ; i < 10; i++) {
        cout << "make:" << carArray[i].make << " model:" << carArray[i].model << " year:"
             << carArray[i].year << endl;
    }

    outFile.open(argv[3]);
    if(outFile.is_open()) {  //error check
        cout << "outFile opened successfully" << endl;
            for(int i = 0 ; i < 10; i++) {
                outFile << carArray[i].make <<"\t";
                outFile << carArray[i].model <<"\t";
                outFile << carArray[i].year <<"\t" <<"\n";
            }
        outFile.close(); //close the file
    }
    else {
        cout << "outFile unsuccessfully opened" << endl;
    }

}