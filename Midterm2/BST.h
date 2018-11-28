#ifndef BST_H
#define BST_H

struct BSTNode{
    int key;
    BSTNode *parent;
    BSTNode *leftChild;
    BSTNode *rightChild;

    BSTNode(){};

    BSTNode(int k)
    {
        key = k;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class BST
{

    public:
        BST();
        ~BST();
        void printBST();
        int countBSTNodes();
        void addBSTNode(int key);

        void deleteRootAndReplaceLeftMin();

    protected:

    private:
        void DeleteAll(BSTNode * node); //use this for the post-order traversal deletion of the tree
        void printBST(BSTNode * node);
        void countBSTNodes(BSTNode *node, int *c);
        BSTNode* search(int key);
        BSTNode* searchRecursive(BSTNode *node, int key);
        BSTNode *root;

        BSTNode* findMin(BSTNode *n);
};

#endif // MOVIETREE_H
