//
// Created by Sam Feig on 10/15/18.
//

#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree(){}

MovieTree::MovieTree(char* argv[]) {
    readFile(argv[1]);

    string input, name;
    string A, B;
    bool quit = false;

    while(!quit) {
        cout<<endl;
        printMenu();
        getline(cin, input);

        try {
            switch (stoi(input)) {
                case 1: //Find a movie
                    cout << "Enter the name of a movie" << endl;
                    getline(cin, name);
                    findMovie(name);
                    break;

                case 2: //Rent a movie
                    cout << "Enter the name of a movie" << endl;
                    getline(cin, name);
                    rentMovie(name);
                    break;

                case 3: //Print the inventory
                    printMovieInventory();
                    break;

                case 4: //Delete Movie
                    cout << "Enter the name of a movie" << endl;
                    getline(cin, name);
                    deleteMovieNode(name);
                    break;

                case 5: //Count Movies
                    cout << "Tree contains: " << countMovieNodes() << " movies." << endl;
                    break;

                case 6: //Print top 10 between 2 letters
                    cout << "Enter the first character to search between" << endl;
                    getline(cin, A);
                    cout << "Enter the second character to search between" << endl;
                    getline(cin, B);
                    printTop10Between(A[0], B[0]);
                    break;

                case 7: //Quit
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

MovieTree::~MovieTree() {
    DeleteAll(root);
}

void MovieTree::DeleteAll(MovieNodeBST* index){
    if(index == nullptr){
        return;
    }

    DeleteAll(index->left);
    DeleteAll(index->right);;
    index->heap->~Heap();
    cout<<"Deleting " <<index->letter <<" BST index" <<endl;
    delete index;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
    char letter = title[0];

//    Create MovieNodeLL to be added to its LL
//    MovieNodeH* newMovie = new MovieNodeH(ranking, title, releaseYear, quantity);

//    Create a BST index to be added
    MovieNodeBST* newIndex = new MovieNodeBST(letter);

//    If BST is empty, set newIndex as root. If LL is empty, set newMovie as head
    if(root == nullptr) {
        root = newIndex;
        root->heap->push(ranking, title, releaseYear, quantity);
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
            newIndex->heap->push(ranking, title, releaseYear, quantity);
            break;
        }
        else{
            tmp = tmp->right;
        }
    }

//    newIndex not in BST, so it must be added as a new index
    if(newIndex != tmp) {
        if(newIndex->letter < parent->letter) {
            parent->left = newIndex;
            newIndex->parent = parent;
        }
        else if(newIndex->letter > parent->letter) {
            parent->right = newIndex;
            newIndex->parent = parent;
        }
        newIndex->heap->push(ranking, title, releaseYear, quantity);
    }
}

void MovieTree::deleteMovieNode(string title){
//    Search BST for starting letter of movie title
    MovieNodeBST* index = searchBST(root, title);

    if(index == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search H at specified BST index for movie title
    MovieNodeH* delMovie = searchH(index, title);


    if(delMovie == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }
//    heap has more than 1 movie in it
    if(index->heap->size() > 1) {
        delMovie->quantity = 0;
        index->heap->decSize();
        index->heap->maxHeapify(1);
    }
//    heap has only 1 movie so must delete BST index too
    else {
        delMovie->quantity = 0;
        index->heap->decSize();

//          No children
        if((index->left == nullptr) && (index->right == nullptr)) {
//            root
            if (index->parent == nullptr) {
                delete index;
                return;
            }
//            is left child no children
            else if (index->parent->left == index) {
                index->parent->left = nullptr;
                delete index;
                return;
            }
//            is right child noi children
            else if (index->parent->right == index) {
                index->parent->right = nullptr;
                delete index;
                return;
            }
        }
//        Check if index has left or right children
        else if(index->left == nullptr) {
            index->right->parent = index->parent;
//            index is root and has right child
            if(index->parent == nullptr) {
                root = index->right;
                delete index;
                return;
            }
//            is left child and has right child
            else if(index->parent->left == index) {
                index->parent->left = index->right;
                delete index;
                return;
            }
//            is right child and has right child
            else if(index->parent->right == index) {
                index->parent->right = index->right;
                delete index;
                return;
            }
        }
        else if (index->right == nullptr) {
//            index->left->parent = index->parent;
//            index is root and has left child
            if (index->parent == nullptr) {
                root = index->left;
                delete index;
                return;
            }
//            is left child and has left child
            else if (index->parent->left == index) {
                index->parent->left = index->left;
                delete index;
                return;
            }
//            is right child and has left child
            else if (index->parent->right == index) {
                index->parent->right = index->left;
                delete index;
                return;
            }
        }
//        Has 2 children
        else {
            MovieNodeBST *min = treeMinimum(index->right);

            if (min == index->right) {
                min->left = index->left;
                index->left->parent = min;
//              is root and has 2 children
                if (index->parent == nullptr) {
                    root = min;
                    delete index;
                    return;
                }
//                is left child and has 2 children
                else if (index == index->parent->left) {
                    min->parent = index->parent;
                    index->parent->left = min;
                    delete index;
                    return;
                }
//                is right child and has 2 children
                else if (index == index->parent->right) {
                    min->parent = index->parent;
                    index->parent->right = min;
                    delete index;
                    return;
                }
            }
//            min is not root and has a right child
            else {//if (min->right != nullptr) {
                min->parent->left = min->right;
                min->right->parent = min->parent;
                min->left = index->left;
                min->right = index->right;
                min->left->parent = min;
                min->right->parent = min;
//              node is root
                if (index->parent == nullptr) {
                    root = min;
                    delete index;
                    return;
                }
                else if (index->parent->left == index) {

                    min->parent = index->parent;
                    index->parent->left = min;
                    delete index;
                    return;
                }
                else if (index->parent->right == index) {

                    min->parent = index->parent;
                    index->parent->right = min;
                    delete index;
                    return;
                }
            }
//            min is root
//            else {
//                root = nullptr;
//                delete index;
//            }
        }
    }
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST* index, string title){
    char letter = title[0];
    if(index == nullptr){
        return index;
    }

    else if (index->letter == letter){
        return index;
    }

    else if(index->letter > letter){
        return searchBST(index->left, title);
    }

    else {
        return searchBST(index->right, title);
    }
}

MovieNodeH* MovieTree::searchH(MovieNodeBST *bst, string title) {
    return bst->heap->search(title);
}

void MovieTree::printTop10Between(char A, char B) {
    printTop10Between(root, A, B);
}

void MovieTree::printTop10Between(MovieNodeBST *index, char A, char B) {
    if(index == nullptr) {
        return;
    }
    if(A < index->letter) {
        printTop10Between(index->left, A, B);
    }
//      If root's data lies in range, then prints root's data
    if(A <= index->letter && B >= index->letter ) {
        index->heap->printTop10Array();
        index->heap->reAddTop10();
    }
//      If root->data is smaller than k2, then only we can get o/p keys in right subtree
    if(B > index->letter) {
        printTop10Between(index->right, A, B);
    }
}

void MovieTree::findMovie(string title){
//    Search BST for starting letter of movie title
    MovieNodeBST* index = searchBST(root, title);

    if (index == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search LL at specified BST index for movie title
    MovieNodeH* movie = searchH(index, title);

    if(movie == nullptr) {
        cout << "Movie Not Found." << endl;
        return;
    }

    else {
        cout<<endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << movie->ranking << endl;
        cout << "Title:" << movie->title << endl;
        cout << "Year:" << movie->year << endl;
        cout << "Quantity:" << movie->quantity << endl;
    }
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST* index){
    MovieNodeBST* x = index;
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

void MovieTree::rentMovie(string title){
//    Search BST for index Movie is located at
    MovieNodeBST* index = searchBST(root, title);
    if (index == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Search H at BST index for the movie
    MovieNodeH* movie = searchH(index, title);

    if (movie == nullptr){
        cout << "Movie Not Found." << endl;
        return;
    }

//    Print out movie info and decrement quantity
    else {
        cout<<endl;
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << movie->ranking << endl;
        cout << "Title:" << movie->title << endl;
        cout << "Year:" << movie->year << endl;
        movie->quantity--;
        cout << "Quantity:" << movie->quantity << endl;
    }

//    If no movies left, move down in heap
    if (movie->quantity == 0) {
        index->heap->decSize();
        index->heap->maxHeapify(1);
//        deleteMovieNode(movie->title);
    }
}

void MovieTree::countMovieNodes(MovieNodeBST *index, int &count){
    if (root == nullptr){
        return;
    }

//    Post Order count all nodes in BST
    if(index->left != nullptr){
        countMovieNodes(index->left , count);
    }
    if(index->right != nullptr){
        countMovieNodes(index->right, count);
    }

    count += index->heap->size();
}

int MovieTree::countMovieNodes(){
    int count = 0;
    countMovieNodes(root, count);
    return count;
}

void MovieTree::printMovieInventory(MovieNodeBST * index){
    if(root == nullptr){
        return;
    }

//    InOrder Traverse the BST
    if(index->left != nullptr){
        printMovieInventory(index->left);
    }

//    Print each movie in the LL for that index in the BST
    index->heap->printArray();

    if(index->right != nullptr){
        printMovieInventory(index->right );
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
    cout << "6. Print top 10 between 2 letters" << endl;
    cout << "7. Quit" << endl;
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