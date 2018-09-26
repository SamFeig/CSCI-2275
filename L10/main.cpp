#include <iostream>
using namespace std;

struct node {
	string name;
	int count;
	node() {}
	node(string n, int c) {
		name = n;
		count = c;
	}
};


int main() {
    node myNode("Boulder", 1);
    cout<<myNode.name <<" " <<myNode.count<<endl;

    node *ptrNode = new node("Denver", 2);
    cout<<(*ptrNode).name <<" " <<(*ptrNode).count<<endl;
	cout<<ptrNode->name <<" " <<ptrNode->count <<endl;

	node *arrayNodes = new node[10];

	arrayNodes[1].name = "Boulder";

    return 0;
}