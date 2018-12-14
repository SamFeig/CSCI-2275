#include <iostream>
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    DeleteAll(root);
}

void BST::DeleteAll(BSTNode * node)
{
    // clean to the left
    if (node->leftChild != NULL)
        DeleteAll(node->leftChild);
    // clean to the right
    if (node->rightChild != NULL)
        DeleteAll(node->rightChild);
    // delete this node
    cout<<"Deleting: "<<node->key<<endl;
    delete node;

}


/* Helper for the printBST recursive function */
void BST::printBST()
{
    printBST(root);

}

/* Prints the BST(in order traversal) */
void BST::printBST(BSTNode * node)
{

    // Left Node
    if(node->leftChild!=NULL)
        printBST(node->leftChild);

    // Value
    //cout<<"Movie: "<<node->title<< endl;
    cout<<"Node: "<<node->key<<endl;
    // Right Node
    if(node->rightChild!=NULL)
        printBST(node->rightChild);

}

void BST::addBSTNode(int key)
{
    // Create the node we will be inserting
    BSTNode * newNode = new BSTNode(key);
    BSTNode * x = root;
    BSTNode * y = NULL;

    // Do we have an empty tree?
    if (root == NULL)
        root = newNode;

        // If the tree is not empty
    else
    {

        // Get to the end of the tree, where we need to add this node.
        while (x != NULL)
        {

            y = x;
            if(newNode->key < x->key)
                x = x->leftChild;
            else
                x = x->rightChild;

        }

        // set the parent of this node to be the previous node.
        newNode->parent = y;

        // Determine which child to this previous node we are at.
        if (newNode->key < y->key)
            y->leftChild = newNode;
        else
            y->rightChild = newNode;
    }

    return;

}
BSTNode* BST::searchRecursive(BSTNode *node, int key){
    if(node != NULL){
        if(node->key == key){
            return node;
        }else if(node->key > key){
            return searchRecursive(node->leftChild, key);
        }else{
            return searchRecursive(node->rightChild, key);
        }
    }else{
        return NULL;
    }
}

BSTNode* BST::search(int key)
{
    BSTNode *node = root;
    bool found = false;
    while(node != NULL && !found){
        if(node->key < key){
            node = node->rightChild;
        }else if(node->key > key){
            node = node->leftChild;
        }else{
            found = true;
        }
    }
    return node;
}

int BST::countBSTNodes()
{
    int *count = new int;
    *count = 0;
    if(root != NULL)
        *count = *count + 1;
    countBSTNodes(root, count);
    return *count;
}

void BST::countBSTNodes(BSTNode *root, int *count)
{

    if (root->leftChild != NULL){
        *count = *count + 1;
        countBSTNodes(root->leftChild, count);
    }
    if(root->rightChild != NULL){
        *count = *count + 1;
        countBSTNodes(root->rightChild, count);
    }

}

BSTNode* BST::findMin(BSTNode *n) {
    BSTNode *x = n;
    while(x->leftChild != NULL) {
        x=x->leftChild;
    }
    return x;
}


void BST::deleteRootAndReplaceLeftMin() {
    if(root == NULL) {
        return;
    }
//  Assume root has leftChild as stated in assignment
    BSTNode* leftMin = findMin(root->leftChild);

//    Left child of root is min
    if(root->leftChild == leftMin) {
//        No children of leftMin
        if(leftMin->leftChild == NULL && leftMin->rightChild == NULL) {
            leftMin->leftChild = NULL;
            leftMin->rightChild = root->rightChild;
            leftMin->parent = NULL;
        }
//      leftMin has rightChild
        else {
            leftMin->leftChild = leftMin->rightChild;
            leftMin->rightChild = root->rightChild;
            leftMin->parent = NULL;
        }
    }
//    leftMin is in left subtree but is not leftChild of root (Has a parent that isn't root)
    else {
//        No children of leftMin
        if(leftMin->rightChild == NULL) {
            leftMin->parent->leftChild = NULL;
            leftMin->parent = NULL;

            leftMin->leftChild = root->leftChild;
            leftMin->rightChild = root->rightChild;
        }
//      leftMin has rightChild
        else {
            leftMin->parent->leftChild = leftMin->rightChild;
            leftMin->parent = NULL;

            leftMin->leftChild = root->leftChild;
            leftMin->rightChild = root->rightChild;
        }
    }

    delete root;
    root = leftMin;
}

//Correct Answer
//void BST::deleteRootAndReplaceLeftMin()
//{
//    if (root != nullptr && root->leftChild != nullptr)
//    {
//        BSTNode *repNode = treeMinimum(root);
//
//        if (repNode->rightChild != nullptr)
//            repNode->rightChild->parent = repNode->parent;
//        repNode->parent->leftChild = repNode->rightChild;
//
//        repNode->leftChild = root->leftChild;
//        if(repNode->leftChild != nullptr)
//            repNode->leftChild->parent = repNode;
//        repNode->rightChild = root->rightChild;
//        if(repNode->rightChild != nullptr)
//            repNode->rightChild->parent = repNode;
//
//        delete root;
//        root = repNode;
//    }
//    else if (root->leftChild == nullptr)
//    {
//        if (root->rightChild != nullptr)
//        {
//            BSTNode * tempRoot = root->rightChild;
//            delete root;
//            root = tempRoot;
//        }
//        else
//        {
//            delete root;
//            root = nullptr;
//        }
//    }
//}
