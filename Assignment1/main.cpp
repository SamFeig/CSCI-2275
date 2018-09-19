/*
 * Sam Feig
 * Assignment 1
 * CSCI 2275-800
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// Define struct for items
struct item {
    string for_sale = "";
    string type = "";
    int price = -1;
};

int shiftArray(item[], int, int&);
void split(item[], item[], int&, item[], int&);
void maxProfit(item[], int, item[], int);
void maxBargan(item[], int, item[], int);

int main(int argc, char *argv[])
{
    //Assume there will be no more than 100 elements
    item items[100];
    //Seperate arrays for the two best match functions as it must remove elements
    item sellItems[100];
    item sellItems2[100];
    int sellSize = 0;
    int sellSize2 = 0;
    item buyItems[100];
    item buyItems2[100];
    int buySize = 0;
    int buySize2 = 0;


    // input file name is argv[1]
    ifstream myfile (argv[1]);
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
    cout<<"There are "<<cur_items<<" in the list" <<endl;
    cout<<"----------------------" <<endl;

    //split into buy and sell arrays
    split(items, sellItems, sellSize, buyItems, buySize);
    split(items, sellItems2, sellSize2, buyItems2, buySize2);

    //sort by price for maxProfit
    sort(sellItems, sellItems+sellSize, [](item a, item b){ return a.price < b.price; });
    sort(buyItems, buyItems+buySize, [](item a, item b){ return a.price < b.price; });

    //sort by price for maxBargan
    sort(sellItems2, sellItems2+sellSize2, [](item a, item b){ return a.price < b.price; });
    sort(buyItems2, buyItems2+buySize2, [](item a, item b){ return a.price < b.price; });

//    cout <<endl <<"Sell: "<< sellSize <<endl;
//    for( int i = 0 ; i < sellSize ; i++) {
//        cout <<sellItems[i].type << sellItems[i].for_sale << " " << sellItems[i].price << endl ;
//    }
//    cout <<endl <<"Buy: "<< buySize <<endl;
//    for( int i = 0 ; i < buySize ; i++) {
//        cout <<buyItems[i].type << buyItems[i].for_sale << " " << buyItems[i].price << endl ;
//    }

    maxProfit(sellItems, sellSize, buyItems, buySize);
    cout<<"----------------------" <<endl;
    maxBargan(sellItems2, sellSize, buyItems2, buySize);

    return 0;
}

void split(item items[], item sell[], int &sellSize, item buy[], int &buySize) {
    for(int i = 0; i < 100; i++) {
        if(items[i].for_sale == " for sale") {
            sell[sellSize] = items[i];
            sellSize++;
        }
        else {
            buy[buySize] = items[i];
            buySize++;
        }
    }
}

int shiftArray(item items[], int index, int& size) {
    for(int i = index; i < size ; i++) {
        items[i] = items[i+1];
    }
    size--;
    return size;
}

void maxProfit(item sell[], int sellSize, item buy[], int buySize) {
    int counter = 0;
    cout <<endl <<"maxProfit:" <<endl;
    //cout <<"Sell Size " <<sellSize <<" Buy Size " <<buySize <<endl;
    for(int j = buySize; j >= 0; j--) {
        for(int i = 0; i < sellSize; i++) {
            //check that types match and sell price is less than buy price
            if(sell[i].type == buy[j].type && sell[i].price <= buy[j].price) {
               // cout<< "i: " <<i <<" j: " <<j <<endl;
                  //cout << "match: " << sell[i].type <<" ... Sell at " <<sell[i].price << " Buy at " <<buy[j].price <<endl;
                cout <<sell[i].type <<" " <<buy[j].price <<endl;
                counter++;
                //shift arrays to remove items already matched
                  sellSize = shiftArray(sell, i, sellSize);
                  buySize = shiftArray(buy, j, buySize);
            }
        }
    }
    for(int i = 0; i < sellSize; i++) {
        cout <<endl <<"Match not found" <<endl;
        cout <<sell[i].type << " " <<sell[i].price <<endl <<endl;
    }
    for(int i = 0; i < buySize; i++) {
        cout <<endl <<"Match not found" <<endl;
        cout <<buy[i].type << " " <<buy[i].price <<endl <<endl;
    }
    cout<<counter<<endl;
}

void maxBargan(item sell[], int sellSize, item buy[], int buySize) {
    cout <<endl <<"maxBargan:" <<endl;
    //cout <<"Sell Size " <<sellSize <<" Buy Size " <<buySize <<endl;
    for(int i = 0; i < sellSize; i++) {
        for (int j = 0; j < buySize; j++) {
            //check that types match and sell price is less than buy price
            if (sell[i].type == buy[j].type && sell[i].price <= buy[j].price) {
                // cout<< "i: " <<i <<" j: " <<j <<endl;
                //cout << "match: " << sell[i].type << " ... Sell at " << sell[i].price << " Buy at " << buy[j].price << endl;
                cout <<buy[j].type <<" " <<buy[j].price <<endl;
                //shift arrays to remove items already matched
                sellSize = shiftArray(sell, i, sellSize);
                buySize = shiftArray(buy, j, buySize);
            }
        }
    }
    //print unmatched
    for(int i = 0; i < sellSize; i++) {
        cout <<endl <<"Match not found" <<endl;
        cout <<sell[i].type << " " <<sell[i].price <<endl <<endl;
    }
    for(int i = 0; i < buySize; i++) {
        cout <<endl <<"Match not found" <<endl;
        cout <<buy[i].type << " " <<buy[i].price <<endl <<endl;
    }
}