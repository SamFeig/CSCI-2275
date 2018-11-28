#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.cpp"
using namespace std;

void run(Graph<string> &G);
void printMenu();
void readFile(Graph<string> &G, char* argv[]);

int main(int argc, char* argv[]) {
    Graph<string> G;
    readFile(G, argv);
    run(G);
    return 0;
}

void run(Graph<string> &G) {
    string input, name, name2, hops;
    bool quit = false;

    while(!quit) {
        cout<<endl;
        printMenu();
        getline(cin, input);
        try {
            switch (stoi(input)) {
                case 1: //Print list of people and their acquaintances
                    G.printGraph();
                    break;

                case 2: //Print distance between 2 people
                    cout << "Enter a name" << endl;
                    getline(cin, name);
                    cout << "Enter another name" << endl;
                    getline(cin, name2);

                    if(any_of(name.begin(), name.end(), ::isdigit) || any_of(name2.begin(), name2.end(), ::isdigit)) {
                        cout<<"You didnt enter a string, try again"<<endl;
                        break;
                    }


                    printf("%d", G.findDistBetween(name, name2));
                    break;

                case 3: //Print people who are ‘n’ hops away
                    cout << "Enter a name" << endl;
                    getline(cin, name);

                    cout << "Enter number of hops" << endl;
                    getline(cin, hops);

                    if(any_of(name.begin(), name.end(), ::isdigit)){
                        cout<<"You didnt enter a string, try again"<<endl;
                        break;
                    }

                    G.findPeopleNAway(name, stoi(hops));
                    break;

                case 4: //Quit
                    cout << "Quitting!" << endl;
                    quit = true;
                    break;

                default:
                    cout << "That was not a valid input. Please try again." << endl;
            }
        }
        catch(invalid_argument& e) {
            cout<<"You didnt enter a number, try again"<<endl;
        }
        catch(exception& e) {
            cout<<"Exception: " <<e.what() <<endl <<"Try again." <<endl;
        }
    }
}

void printMenu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Print list of people and their acquaintances" << endl;
    cout << "2. Print distance between 2 people" << endl;
    cout << "3. Print people who are ‘n’ hops away" << endl;
    cout << "4. Quit" << endl;
}

void readFile(Graph<string>& G, char* argv[]) {
    ifstream file(argv[1]);
    vector<pair<string, pair<string, int>>> e;
    string line, root, tmp, name, weight;
    bool end = false;

    while(getline(file, line)) {
        stringstream ss(line);

        getline(ss, root, '-');
        G.insertVertex(root);

        while(getline(ss, name, ',')) {
            end = false;
            while(!end) {
                getline(ss, weight, ',');
                end = true;
            }
            if(tmp.find("\r") != -1) {
                tmp = tmp.substr(0, tmp.size() - 1);
            }
            e.push_back(make_pair(root, make_pair(name, stoi(weight))));
        }
    }

    for(int i = 0; i < e.size(); i++) {
        G.insertEdge(e[i].first, e[i].second.first, e[i].second.second);
    }
};