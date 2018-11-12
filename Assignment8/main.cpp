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

//    G.insertVertex("S");
//    G.insertVertex("K");
//    G.insertVertex("R");
//    G.insertVertex("I");
//
//    G.insertVertex("M");
//    G.insertVertex("P");
//
//    G.insertEdge("S","K");
//    G.insertEdge("K","R");
//    G.insertEdge("K","I");
//    G.insertEdge("S","R");
//    G.insertEdge("R","I");
//
//    G.insertEdge("M","P");
//
//    G.DFS("S");
//
//    readFile(G, argv);
//    G.DFS("Divya");
//    G.connectedComponents();
//    G.BFS("Tim", "Paramvir");
//    G.findLeastIntroductions("Tim", "Tessa");
    return 0;
}

void run(Graph<string> &G) {
    string input, name, name2;
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

                case 2: //Print if people know each other
                    cout << "Enter a name" << endl;
                    getline(cin, name);
                    cout << "Enter another name" << endl;
                    getline(cin, name2);

                    if(any_of(name.begin(), name.end(), ::isdigit) || any_of(name2.begin(), name2.end(), ::isdigit)) {
                        cout<<"You didnt enter a string, try again"<<endl;
                        break;
                    }

                    printf("%s", (G.adjacent(name, name2) ? "true" : "false"));
                    break;

                case 3: //Print groups
                    G.connectedComponents();
                    break;

                case 4: //Find the least number of introductions required
                    cout << "Enter a name" << endl;
                    getline(cin, name);
                    cout << "Enter another name" << endl;
                    getline(cin, name2);

                    if(any_of(name.begin(), name.end(), ::isdigit) || any_of(name2.begin(), name2.end(), ::isdigit)) {
                        cout<<"You didnt enter a string, try again"<<endl;
                        break;
                    }

                    G.findLeastIntroductions(name, name2);

                    break;

                case 5: //Quit
                    cout << "Quitting!" << endl;
                    quit = true;
                    break;

                default:
                    cout << "That was not a valid input. Please try again." << endl;
            }
        }
        catch(exception& e) {
            cout<<"Exception: " <<e.what() <<endl <<"Try again." <<endl;
        }
    }
}

void printMenu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Print list of people and their acquaintances" << endl;
    cout << "2. Print if people know each other" << endl;
    cout << "3. Print groups" << endl;
    cout << "4. Find the least number of introductions required" << endl;
    cout << "5. Quit" << endl;
}

void readFile(Graph<string>& G, char* argv[]) {
    ifstream file(argv[1]);
    vector<pair<string, string>> e;
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string root;
        string tmp;

        getline(ss, root, '-');
        G.insertVertex(root);

        while (getline(ss, tmp, ',')) {
            if (tmp.find("\r") != -1) {
                tmp = tmp.substr(0, tmp.size() - 1);
            }
            e.push_back(make_pair(root, tmp));
        }
    }

    for(int i = 0; i < e.size(); i++) {
        G.insertEdge(e[i].first, e[i].second);
    }
};
