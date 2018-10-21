#include <iostream>
class RecitationBST {
public:
     struct node {
        int key;
        node *left, *right;
    };

     node *newNode(int item) {
         node *temp = new node();
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    void inorder( node *root) {
        if (root != NULL) {
            inorder(root->left);
            printf("%d \n", root->key);
            inorder(root->right);
        }
    }

     node* insert(node *node, int key) {
        /* If the tree is empty, return a new node */
        if (node == NULL) return newNode(key);

        /* Otherwise, recur down the tree */
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

     node* search(node *root, int key) {
        // Base Cases: root is null or key is present at root
        if (root == NULL || root->key == key)
            return root;

        // Key is greater than root's key
        if (root->key < key)
            return search(root->right, key);

        // Key is smaller than root's key
        return search(root->left, key);
    }

    void remove() {

     }
};