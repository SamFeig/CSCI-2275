//
// Created by Sam Feig on 10/18/18.
//

#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

MovieTree::MovieTree(char* argv[]) {
    readFile(argv[1]);
    string input, name;
    bool quit = false;

    while(!quit) {
        cout<<endl;
        printMenu();
        getline(cin, input);
//        cin >> input;
//        cin.ignore(256, '\n');

        switch(stoi(input)) {
            case 1: //Find a movie
                cout<<"Enter the name of a movie" <<endl;
                getline(cin, name);
                findMovie(name);
                break;

            case 2: //Rent a movie
                cout<<"Enter the name of a movie" <<endl;
                getline(cin, name);
                rentMovie(name);
                break;

            case 3: //Print the inventory
                printMovieInventory();
                break;

            case 4: //Delete a movie
                cout<<"Enter the name of a movie" <<endl;
                getline(cin, name);
                deleteMovieNode(name);
                break;

            case 5: //Count the movies
                cout<<"Tree contains: "<<countMovieNodes()<<" movies."<<endl;
                break;

            case 6: //Quit
                cout<<"Quitting!" <<endl;
                quit = true;
                break;

            default:
                cout<<"That was not a valid input. Please try again."<<endl;
        }
    }
}

MovieTree::~MovieTree() {
    DeleteAll(root);
}

void MovieTree::DeleteAll(MovieNodeBST* node){
    if(root == nullptr){
        return;
    }

//    Recursively delete each node in the BST
    if(node->left != nullptr) {
        DeleteAll(node->left );
    }
    if(node->right != nullptr) {
        DeleteAll(node->right);
    }

//    Delete each node in the LL
    MovieNodeLL* current = node->head;
    MovieNodeLL* temp;
    while(current != nullptr){
        temp = node->head->next;
        cout << "Deleting: " << node->head->title << endl;
        delete node->head;
        node->head = temp;
        current = node->head;
    }
    node->head = nullptr;
    delete node;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
    char letter = title[0];

//    Create MovieNodeLL to be added to its LL
    MovieNodeLL* newMovie = new MovieNodeLL(ranking, title, releaseYear, quantity);

//    Create a BST node to be added
    MovieNodeBST* newIndex = new MovieNodeBST(letter);

//    If BST is empty, set newIndex as root. If LL is empty, set newMovie as head
    if(root == nullptr) {
        root = newIndex;
        root->head = newMovie;
        root->head->next = nullptr;
        return;
    }
    MovieNodeBST* parent = nullptr;
    MovieNodeBST* tmp = root;

//    Find if newIndex is already in BST
    while(tmp != nullptr){
        parent = tmp;
        if(newIndex->letter < tmp->letter){
            tmp = tmp->left;
        }
        else if(newIndex->letter == tmp->letter){
            newIndex = tmp;
            break;
        }
        else{
            tmp = tmp->right;
        }
    }

//    newIndex not in BST, so it must be added as a new node
    if(newIndex != tmp) {
        if(newIndex->letter < parent->letter) {
            parent->left = newIndex;
            newIndex->parent = parent;
        }
        else if(newIndex->letter > parent->letter) {
            parent->right = newIndex;
            newIndex->parent = parent;
        }
    }

//    Check if newIndex is new node in BST (LL has no values), if so set newMovie as head of LL
    if(newIndex->head == nullptr) {
        newIndex->head = newMovie;
        newIndex->head->next = nullptr;
    }

//    Nodes already in LL so add newMovie alphabetically
    else {
        int i = 1;
        MovieNodeLL *current = newIndex->head;

//        Loop through LL
        while(current != nullptr) {
//            If newMovie is same as previous alphabetically, check each letter in title
            while(current->title[i] == newMovie->title[i]) {
                i++;
//                Has checked all letters in title
                if(i == current->title.length()) {
                    if(current->next == nullptr) {
//                        Set newMovie as tail
                        current->next = newMovie;
                        newMovie->next = nullptr;
                        i = 1;
                        return;
                    }
                    else {
                        current = current->next;
                        i = 1;
                    }
                }
//                newMovie is shorter than existing movies so it should go at the head of LL
                else if(i == newMovie->title.length()) {
//                    Handle if current node is head
                    if(current == newIndex->head) {
                        newMovie->next = newIndex->head;
                        newIndex->head = newMovie;
                        return;
                    }
//                    Handle placement of newMovie in middle of LL
                    else {
                        MovieNodeLL* previous = nullptr;
                        MovieNodeLL* temp = newIndex->head;
//                        Find movie before current
                        while(temp != current) {
                            previous = temp;
                            temp = temp->next;
                        }
                        newMovie->next = current;
                        previous->next = newMovie;
                        return;
                    }
                }

            }
//            If newMovie is behind previous alphabetically
            if(current->title[i] < newMovie->title[i]) {
                if (current->next == nullptr) {
//                    Set newMovie as the tail
                    current->next = newMovie;
                    newMovie->next = nullptr;
                    i = 1;
                    return;

                }
                else {
                    current = current->next;
                    i = 1;
                }
            }
//            If newMovie is ahead of previous alphabetically
            else if(current->title[i] > newMovie->title[i]) {
                if(current == newIndex->head) {
                    newMovie->next = newIndex->head;
                    newIndex->head = newMovie;
                    return;
                }
                else {
                    MovieNodeLL* previous = nullptr;
                    MovieNodeLL* temp = newIndex->head;
                    while(temp != current){
                        previous = temp;
                        temp = temp->next;
                    }
                    newMovie->next = current;
                    previous->next = newMovie;
                    return;
                }
            }
        }
    }
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST* node, string title){
    char letter = title[0];
    if(node == nullptr){
        return node;
    }

    else if (node->letter == letter){
        return node;
    }

    else if(node->letter > letter){
        return searchBST(node->left, title);
    }

    else {
        return searchBST(node->right, title);
    }
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* node, string title){
    if(node == nullptr){
        return node;
    }

    else if(node->title == title){
        return node;
    }

    else {
        return searchLL(node->next, title);
    }
}

void MovieTree::findMovie(string title){
//    Search BST for starting letter of movie title
    MovieNodeBST* index = searchBST(root, title);

    if (index == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search LL at specified BST node for movie title
    MovieNodeLL* movie = searchLL(index->head, title);

    if(movie == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }

    else {
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << movie->ranking << endl;
        cout << "Title:" << movie->title << endl;
        cout << "Year:" << movie->year << endl;
        cout << "Quantity:" << movie->quantity << endl;
    }
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST* node){
    MovieNodeBST* x = node;
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

void MovieTree::deleteMovieNode(string title){
//    Search BST for starting letter of movie title
    MovieNodeBST* index = searchBST(root, title);

    if(index == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search LL at specified BST node for movie title
    MovieNodeLL* delMovie = searchLL(index->head, title);

    if(delMovie == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }

//    Check if movie being deleted is head of LL, if so delete BST node as well
    else if((delMovie == index->head) && (index->head->next == nullptr)) {
        index->head = nullptr;
        delete(delMovie);

        if((index->left == nullptr) && (index->right == nullptr)){
            if (index->parent == nullptr){
                delete(index);
                return;
            }
            else if(index->parent->left == index){
                index->parent->left = nullptr;
                delete(index);
                return;
            }
            else if(index->parent->right == index){
                index->parent->right = nullptr;
                delete(index);
                return;
            }
        }

//        Check if index has left or right children
        else if(index->left == nullptr) {
            index->right->parent = index->parent;
            if(index->parent == nullptr){
                root = index->right;
                delete index;
                return;
            }
            else if(index->parent->left == index) {
                index->parent->left = index->right;
                delete index;
                return;
            }
            else if(index->parent->right == index) {
                index->parent->right = index->right;
                delete index;
                return;
            }
        }
        else if(index->right == nullptr) {
            if(index->parent == nullptr) {
                root = index->left;
                delete index;
                return;
            }
            else if(index->parent->left == index) {
                index->parent->left = index->left;
                delete index;
                return;
            }
            else if(index->parent->right == index) {
                index->parent->right = index->left;
                delete index;
                return;
            }
        }
//        Has 2 children
        else {
            MovieNodeBST* min = treeMinimum(index->right);

            if(min == index->right) {
                min->left = index->left;
                index->left->parent = min;

                if(index->parent == nullptr) {
                    root = min;
                    delete index;
                    return;
                }
                else if(index == index->parent->left) {
                    min->parent = index->parent;
                    index->parent->left = min;
                    delete(index);
                    return;
                }
                else if(index == index->parent->right) {

                    min->parent = index->parent;
                    index->parent->right = min;
                    delete(index);
                    return;
                }
            }
            else {
                min->parent->left = min->right;
                min->right->parent = min->parent;
                min->left = index->left;
                min->right = index->right;
                min->left->parent = min;
                min->right->parent = min;

                if(index->parent == nullptr) {
                    root = min;
                    delete index;
                    return;
                }
                else if(index->parent->left == index) {

                    min->parent = index->parent;
                    index->parent->left = min;
                    delete index;
                    return;
                }
                else if(index->parent->right == index) {

                    min->parent = index->parent;
                    index->parent->right = min;
                    delete index;
                    return;
                }
            }
        }
    }
    else {
//        Movie to delete is head of LL
        if (index->head == delMovie) {
            index->head = delMovie->next;
            delete delMovie;
            return;
        }

//      Movie to delete is not the head of LL
        MovieNodeLL *previous = nullptr;
        MovieNodeLL *tmp = index->head;

//        Itterate through LL until delMovie is found
        while (tmp != delMovie) {
            previous = tmp;
            tmp = previous->next;
        }

        previous->next = delMovie->next;
        delete delMovie;
        return;
    }
}

void MovieTree::rentMovie(string title){
//    Search BST for node Movie is located at
    MovieNodeBST* index = searchBST(root, title);
    if (index == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search LL at BST node for the movie
    MovieNodeLL* movie = searchLL(index->head, title);

    if (movie == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Print our movie info and decrement quantity
    else {
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << movie->ranking << endl;
        cout << "Title:" << movie->title << endl;
        cout << "Year:" << movie->year << endl;
        movie->quantity--;
        cout << "Quantity:" << movie->quantity << endl;
    }

//    If no movies left, delete node in LL
    if (movie->quantity == 0) {
        deleteMovieNode(movie->title);
    }
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int &count){
    if (root == nullptr){
        return;
    }

//    Post Order count all nodes in BST
    if(node->left != nullptr){
        countMovieNodes(node->left , count);
    }
    if(node->right !=nullptr){
        countMovieNodes(node->right, count);
    }

//    Go though each LL and count movies
    MovieNodeLL* current = node->head;
    while(current != nullptr){
        count += 1;
        current = current->next;
    }
}

int MovieTree::countMovieNodes(){
    int count = 0;
    countMovieNodes(root, count);
    return count;
}

void MovieTree::printMovieInventory(MovieNodeBST * node){
    if(root == nullptr){
        return;
    }

//    InOrder Traverse the BST
    if(node->left != nullptr){
        printMovieInventory(node->left);
    }

//    Print each movie in the LL for that node in the BST
    MovieNodeLL* current = node->head;
    while(current != nullptr){
        cout << "Movie: " << current->title << " " << current->quantity<< endl;
        current = current->next;
    }

    if(node->right != nullptr){
        printMovieInventory(node->right );
    }
}

void MovieTree::printMovieInventory(){
    if(root == nullptr){
        cout << "Movie Inventory is empty" << endl;
    }
    else {
        printMovieInventory(root);
    }
}

void MovieTree::printMenu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count the movies" << endl;
    cout << "6. Quit" << endl;
}

void MovieTree::readFile(string filename) {
    ifstream file(filename);
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string rank;
        string title;
        string year;
        string quantity;

        getline(ss, rank, ',');
        getline(ss, title, ',');
        getline(ss, year, ',');
        getline(ss, quantity, ',');

        addMovieNode(stoi(rank), title, stoi(year), stoi(quantity));
    }
}