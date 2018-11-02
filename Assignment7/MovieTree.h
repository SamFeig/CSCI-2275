//
//  MovieTree.hpp
//  Assignment-7
//  CSCI 2275
//

#ifndef MOVIETREE_H
#define MOVIETREE_H

#include <string>
#include "heap.cpp"

struct MovieNodeBST {
    char letter;
    MovieNodeBST* parent;
    MovieNodeBST* left;
    MovieNodeBST* right;
    Heap* heap = new Heap(15);
    
    MovieNodeBST(){}

    MovieNodeBST(char in_letter) {
        letter = in_letter;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    };
};

class MovieTree {
    
public:
    MovieTree();
    MovieTree(char* argv[]);
    ~MovieTree();
    void printMovieInventory();
    int countMovieNodes();
    void deleteMovieNode(std::string title);
    void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
    void findMovie(std::string title);
    void rentMovie(std::string title);
    void printMenu();
    void readFile(std::string filename);
    void printTop10Between(char A, char B);

private:
    void DeleteAll(MovieNodeBST *node); //use this for the post-order traversal deletion of the tree
    void printMovieInventory(MovieNodeBST * node);
    void countMovieNodes(MovieNodeBST *node, int &count);
    void printTop10Between(MovieNodeBST *node, char A, char B);
    MovieNodeBST* searchBST(MovieNodeBST *node, std::string title); //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
    MovieNodeH* searchH(MovieNodeBST*, std::string title); //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
    MovieNodeBST* treeMinimum(MovieNodeBST *node); //use this to find the left most leaf node of the BST, you'll need this in the delete function
    MovieNodeBST* root = nullptr;

};
#endif // MOVIETREE_H
