//
// Created by Sam Feig on 12/5/18.
//

#include <iostream>
using namespace std;

class treap {
public:
    struct TreapNode {
        int key;
        int priority;
        TreapNode *left, *right;
    };

    treap() {
        srand(time(NULL));
    }

//    Returns new root after rotation
    TreapNode *rightRotate(TreapNode *y) {
        TreapNode *x = y->left,  *T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

//    Returns new root after rotation
    TreapNode *leftRotate(TreapNode *x) {
        TreapNode *y = x->right, *T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    TreapNode* newNode(int key) {
        TreapNode* temp = new TreapNode;
        temp->key = key;
        temp->priority = rand()%100;
        temp->left = temp->right = nullptr;
        return temp;
    }

    TreapNode* search(TreapNode* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

//         Key is greater than root
        if (root->key < key) {
            return search(root->right, key);
        }

//         Key is smaller than root
        return search(root->left, key);
    }

    TreapNode* insert(TreapNode* root, int key) {
//         If root NULL, create new node
        if (!root) {
            return newNode(key);
        }

        if (key <= root->key) {
            root->left = insert(root->left, key);

            // Fix Heap
            if (root->left->priority > root->priority) {
                root = rightRotate(root);
            }
        }
        else {
            root->right = insert(root->right, key);

            // Fix Heap
            if (root->right->priority > root->priority) {
                root = leftRotate(root);
            }
        }
        return root;
    }

    TreapNode* deleteNode(TreapNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        }
        else if (root->left == nullptr) {
            TreapNode *temp = root->right;
            delete(root);
            root = temp;
        }
        else if (root->right == nullptr) {
            TreapNode *temp = root->left;
            delete(root);
            root = temp;
        }
//         Key is root and has left and right children
        else if (root->left->priority < root->right->priority) {
            root = leftRotate(root);
            root->left = deleteNode(root->left, key);
        }
        else {
            root = rightRotate(root);
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    void inorder(TreapNode* root) {
        if(root) {
            inorder(root->left);
            cout << "key: "<< root->key << " | priority: " << root->priority;
            if (root->left) {
                cout << " | left child: " << root->left->key;
            }
            if (root->right) {
                cout << " | right child: " << root->right->key;
            }
            cout << endl;
            inorder(root->right);
        }
    }
};