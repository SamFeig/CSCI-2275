//
// Created by Sam Feig on 10/10/18.
//
#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;

template<class Key, class Value>
struct node {
    Key key = NULL;           // sorted by key
    Value val = NULL;         // associated data
    node<Key, Value> *left = NULL;
    node<Key, Value> *right = NULL;  // left and right subtrees
    int size = 0;          // number of nodes in subtree

    node(Key k, Value v, int s) {
        key = k;
        val = v;
        size = s;
    }
};

template<class Key, class Value>
class BST {
private:
    node<Key, Value> *root = NULL;

    int size(node<Key, Value> *x) {
        if (x == NULL) return 0;
        else return x->size;
    }

    int cmp(Key k1, Key k2) {
        if(k1 == k2) {
            return 0;
        }
        else if(k1 > k2) {
            return 1;
        }
        else {
            return -1;
        }
    }

    Value get(node<Key, Value> *x, Key key) {
        if (key == NULL) throw "Calls get() with a NULL key";
        if (x == NULL) return NULL;
//        int cmp = key==(x->key);
        if      (key < x->key) return get(x->left, key);
        else if (key > x->key) return get(x->right, key);
        else              return x->val;
    }

    node<Key, Value>* insert(node<Key, Value> *x, Key key, Value val) {
        if (x == NULL) return new node<Key, Value>(key, val, 1);
//        int cmp = (key==(x->key));
        if      (key < x->key) x->left  = insert(x->left,  key, val);
        else if (key > x->key) x->right = insert(x->right, key, val);
        else              x->val   = val;
        x->size = 1 + size(x->left) + size(x->right);
        return x;
    }

    node<Key, Value>* deleteMin(node<Key, Value> *x) {
        if (x->left == NULL) return x->right;
        x->left = deleteMin(x->left);
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    node<Key, Value>* deleteMax(node<Key, Value> *x) {
        if (x->right == NULL) return x->left;
        x->right = deleteMax(x->right);
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    node<Key, Value>* remove(node<Key, Value> *x, Key key) {
        if (x == NULL) return NULL;

//        int cmp = key==(x->key);
        if      (key < x->key) x->left  = remove(x->left,  key);
        else if (key > x->key) x->right = remove(x->right, key);
        else {
            if (x->right == NULL) return x->left;
            if (x->left  == NULL) return x->right;
            node<Key, Value> *t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    node<Key, Value>* min(node<Key, Value> *x) {
        if (x->left == NULL) return x;
        else                return min(x->left);
    }

    node<Key, Value>* max(node<Key, Value> *x) {
        if (x->right == NULL) return x;
        else                 return max(x->right);
    }

    node<Key, Value>* floor(node<Key, Value> *x, Key key) {
        if (x == NULL) return NULL;
//        int cmp = key==(x->key);
        if (key == x->key) return x;
        if (key < x->key) return floor(x->left, key);
        node<Key, Value> *t = floor(x->right, key);
        if (t != NULL) return t;
        else return x;
    }

    Key floor2(node<Key, Value> *x, Key key, Key best) {
        if (x == NULL) return best;
//        int cmp = key==(x->key);
        if      (key < x->key) return floor2(x->left, key, best);
        else if (key > x->key) return floor2(x->right, key, x->key);
        else               return x->key;
    }

    node<Key, Value>* ceiling(node<Key, Value> *x, Key key) {
        if (x == NULL) return NULL;
//        int cmp = key==(x->key);
        if (key == x->key) return x;
        if (key < x->key) {
            node<Key, Value> t = ceiling(x->left, key);
            if (t != NULL) return t;
            else return x;
        }
        return ceiling(x->right, key);
    }

    // Return key of rank k.
    node<Key, Value>* select(node<Key, Value> *x, int k) {
        if (x == NULL) return NULL;
        int t = size(x->left);
        if      (t > k) return select(x->left,  k);
        else if (t < k) return select(x->right, k-t-1);
        else            return x;
    }

    // Number of keys in the subtree less than key.
    int rank(Key key, node<Key, Value> *x) {
        if (x == NULL) return 0;
//        int cmp = key==(x->key);
        if      (key < x->key) return rank(key, x->left);
        else if (key > x->key) return 1 + size(x->left) + rank(key, x->right);
        else              return size(x->left);
    }

    void keys(node<Key, Value> *x, queue<Key> queue, Key lo, Key hi) {
        if (x == NULL) return;
        int cmplo = lo==(x->key);
        int cmphi = hi==(x->key);
        if (cmplo < 0) keys(x->left, queue, lo, hi);
        if (cmplo <= 0 && cmphi >= 0) queue.enqueue(x->key);
        if (cmphi > 0) keys(x->right, queue, lo, hi);
    }

    int height(node<Key, Value> *x) {
        if (x == NULL) return -1;
        return 1 + std::max(height(x->left), height(x->right));
    }

    /*************************************************************************
      *  Check integrity of BST data structure.
      ***************************************************************************/
    bool check() {
        if (!isBST())            cout<<"Not in symmetric order";
        if (!isSizeConsistent()) cout<<"Subtree counts not consistent";
        if (!isRankConsistent()) cout<<"Ranks not consistent";
        return isBST() && isSizeConsistent() && isRankConsistent();
    }

    // does this binary tree satisfy symmetric order?
    // Note: this test also ensures that data structure is a binary tree since order is strict
    bool isBST() {
        return isBST(root, NULL, NULL);
    }

    // is the tree rooted at x a BST with all keys strictly between min and max
    // (if min or max is NULL, treat as empty constraint)
    // Credit: Bob Dondero's elegant solution
    bool isBST(node<Key, Value> *x, Key min, Key max) {
        if (x == NULL) return true;
        if (min != NULL && x->key==(min) <= 0) return false;
        if (max != NULL && x->key==(max) >= 0) return false;
        return isBST(x->left, min, x->key) && isBST(x->right, x->key, max);
    }

    // are the size fields correct?
    bool isSizeConsistent() { return isSizeConsistent(root); }
    bool isSizeConsistent(node<Key, Value> x) {
        if (x == NULL) return true;
        if (x.size != size(x.left) + size(x.right) + 1) return false;
        return isSizeConsistent(x.left) && isSizeConsistent(x.right);
    }

    // check that ranks are consistent
    bool isRankConsistent() {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i))) return false;
        for (Key key : keys())
            if (key==(select(rank(key))) != 0) return false;
        return true;
    }

public:
    BST() {}

    ~BST() {
        destroyTree(root);
    }
    void destroyTree(node<Key, Value> *n){
        if(n == NULL) {
            return;
        }
        else {
            if (n->right != NULL) {
                destroyTree(n->right);
            } else if (n->left != NULL) {
                destroyTree(n->left);
            }
        }
        delete n;
    }

    bool isEmpty() {
        return size() == 0;
    }

    int size() {
        return size(root);
    }

    bool contains(Key key) {
        if (key == NULL) throw "Argument to contains() is NULL";
        return get(key) != NULL;
    }

    Value get(Key key) {
        return get(root, key);
    }

    void insert(Key key, Value val) {
        if (key == NULL) throw invalid_argument("Calls insert() with a NULL key");//"Calls put() with a NULL key";
        if (root == NULL) {
            root = insert(root, key, val);
        }
        insert(root, key, val);
    }

    /**
     * Removes the smallest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */
    void deleteMin() {
        if (isEmpty()) throw "Symbol table underflow";
        root = deleteMin(root);
//        assert check();
    }

    /**
     * Removes the largest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */
    void deleteMax() {
        if (isEmpty()) throw "Symbol table underflow";
        root = deleteMax(root);
//        assert check();
    }

    /**
     * Removes the specified key and its associated value from this symbol table
     * (if the key is in this symbol table).
     *
     * @param  key the key
     * @throws IllegalArgumentException if {@code key} is {@code NULL}
     */
    void remove(Key key) {
        if (key == NULL) throw "calls delete() with a NULL key";
        root = remove(root, key);
//        assert check();
    }

    /**
     * Returns the smallest key in the symbol table.
     *
     * @return the smallest key in the symbol table
     * @throws NoSuchElementException if the symbol table is empty
     */
    Key min() {
        if (isEmpty()) throw "Calls min() with empty symbol table";
        return min(root).key;
    }

    /**
     * Returns the largest key in the symbol table.
     *
     * @return the largest key in the symbol table
     * @throws NoSuchElementException if the symbol table is empty
     */
    Key max() {
        if (isEmpty()) throw "Calls max() with empty symbol table";
        return max(root).key;
    }

    /**
     * Returns the largest key in the symbol table less than or equal to {@code key}.
     *
     * @param  key the key
     * @return the largest key in the symbol table less than or equal to {@code key}
     * @throws NoSuchElementException if there is no such key
     * @throws IllegalArgumentException if {@code key} is {@code NULL}
     */
    Key floor(Key key) {
        if (key == NULL) throw "Argument to floor() is NULL";
        if (isEmpty()) throw "Calls floor() with empty symbol table";
        node<Key, Value> x = floor(root, key);
        if (x == NULL) return NULL;
        else return x.key;
    }

    Key floor2(Key key) {
        return floor2(root, key, NULL);
    }

    /**
     * Returns the smallest key in the symbol table greater than or equal to {@code key}.
     *
     * @param  key the key
     * @return the smallest key in the symbol table greater than or equal to {@code key}
     * @throws NoSuchElementException if there is no such key
     * @throws IllegalArgumentException if {@code key} is {@code NULL}
     */
    Key ceiling(Key key) {
        if (key == NULL) throw "Argument to ceiling() is NULL";
        if (isEmpty()) throw "Calls ceiling() with empty symbol table";
        node<Key, Value> x = ceiling(root, key);
        if (x == NULL) return NULL;
        else return x.key;
    }

    /**
     * Return the kth smallest key in the symbol table.
     *
     * @param  k the order statistic
     * @return the {@code k}th smallest key in the symbol table
     * @throws IllegalArgumentException unless {@code k} is between 0 and
     *        <em>n</em>–1
     */
    Key select(int k) {
        if (k < 0 || k >= size()) {
            throw "Argument to select() is invalid: " + std::to_string(k);
        }
        node<Key, Value> x = select(root, k);
        return x.key;
    }

    /**
     * Return the number of keys in the symbol table strictly less than {@code key}.
     *
     * @param  key the key
     * @return the number of keys in the symbol table strictly less than {@code key}
     * @throws IllegalArgumentException if {@code key} is {@code NULL}
     */
    int rank(Key key) {
        if (key == NULL) throw "Argument to rank() is NULL";
        return rank(key, root);
    }

//    /**
//     * Returns all keys in the symbol table as an {@code Iterable}.
//     * To iterate over all of the keys in the symbol table named {@code st},
//     * use the foreach notation: {@code for (Key key : st.keys())}.
//     *
//     * @return all keys in the symbol table
//     */
//    Iterable<Key> keys() {
//        if (isEmpty()) return new Queue<Key>();
//        return keys(min(), max());
//    }
//
//    /**
//     * Returns all keys in the symbol table in the given range,
//     * as an {@code Iterable}.
//     *
//     * @param  lo minimum endpoint
//     * @param  hi maximum endpoint
//     * @return all keys in the symbol table between {@code lo}
//     *         (inclusive) and {@code hi} (inclusive)
//     * @throws IllegalArgumentException if either {@code lo} or {@code hi}
//     *         is {@code NULL}
//     */
//    Iterable<Key> keys(Key lo, Key hi) {
//        if (lo == NULL) throw new IllegalArgumentException("first argument to keys() is NULL");
//        if (hi == NULL) throw new IllegalArgumentException("second argument to keys() is NULL");
//
//        Queue<Key> queue = new Queue<Key>();
//        keys(root, queue, lo, hi);
//        return queue;
//    }
//        iterator<std::forward_iterator_tag, Key> keys(Key lo, Key hi) {
//        if (lo == NULL) throw "First argument to keys() is NULL";
//        if (hi == NULL) throw "Second argument to keys() is NULL";
//
//        queue<Key> queue = new std::queue<Key>();
//        keys(root, queue, lo, hi);
//        return queue;
//    }
//
//    class Iterator: public std::iterator<std::forward_iterator_tag, Key> {
//        node<Key, Value> current = root;
//
//        Iterator begin() {
//            return (Iterator(root));
//        }
//        Iterator end() {
//            return (Iterator(NULL));
//        }
//        bool hasNext() { return current != NULL; }
//
//        Key next() {
//            if (!hasNext()) throw std::runtime_error("No Next Value");
//            Key item = current.item;
//            current = current.next;
//            return item;
//        }
//    };

    /**
     * Returns the number of keys in the symbol table in the given range.
     *
     * @param  lo minimum endpoint
     * @param  hi maximum endpoint
     * @return the number of keys in the symbol table between {@code lo}
     *         (inclusive) and {@code hi} (inclusive)
     * @throws IllegalArgumentException if either {@code lo} or {@code hi}
     *         is {@code NULL}
     */
    int size(Key lo, Key hi) {
        if (lo == NULL) throw "First argument to size() is NULL";
        if (hi == NULL) throw "Second argument to size() is NULL";

        if (lo==(hi) > 0) return 0;
        if (contains(hi)) return rank(hi) - rank(lo) + 1;
        else              return rank(hi) - rank(lo);
    }

    /**
     * Returns the height of the BST (for debugging).
     *
     * @return the height of the BST (a 1-node tree has height 0)
     */
    int height() {
        return height(root);
    }

//    void levelOrderTraversal() {
//        // create an empty queue and enqueue root node
//        queue<node<Key, Value>*> queue;
//        queue.push(root);
//
//        // pointer to store current node
//        node<Key, Value> *curr = NULL;
//
//        // run till queue is not empty
//        while(queue.size()) {
//            // process each node in queue and enqueue their
//            // non-empty left and right child to queue
//            curr = queue.front();
//            queue.pop();
//
//            cout << curr->key << " ";
//
//            if (curr->left)
//                queue.push(curr->left);
//
//            if (curr->right)
//                queue.push(curr->right);
//        }
//        cout<<endl;
//    }
//


//    void printInorder(node<Key, Value> *node) {
//        if (node == NULL)
//            return;
//        /* first recur on left child */
//        printInorder(node->left);
//
//        /* then print the data of node */
//        cout << node->val << " ";
//
//        /* now recur on right child */
//        printInorder(node->right);
//    }

    void printPostorder() {
        if (root == NULL)
            return;

        /* first recur on left child */
        printPostorder(root->left);

        /* now recur on right child */
        printPostorder(root->right);

        /* then print the data of node */
        cout << root->val << " ";
    }

    void printPostorder(node<Key, Value>* node) {
        if (node == NULL)
            return;

        // first recur on left subtree
        printPostorder(node->left);

        // then recur on right subtree
        printPostorder(node->right);

        // now deal with the node
        cout << node->val << " ";
    }

    void printInorder() {
//        node<Key, Value> *node = root;
        if (root == NULL)
            return;

        /* first recur on left child */
        printInorder(root->left);

        /* then print the data of node */
        cout << root->val << " ";

        /* now recur on right child */
        printInorder(root->right);
    }

/* Given a binary tree, print its nodes in inorder*/
    void printInorder(node<Key, Value>* node) {
        if (node == NULL)
            return;

        /* first recur on left child */
        printInorder(node->left);

        /* then print the data of node */
        cout << node->val << " ";

        /* now recur on right child */
        printInorder(node->right);
    }

    void printPreorder() {
//        node<Key, Value> *node = root;
        if (root == NULL)
            return;

        /* then print the data of node */
        cout << root->val << " ";

        /* first recur on left child */
        printPreorder(root->left);

        /* now recur on right child */
        printInorder(root->right);
    }

/* Given a binary tree, print its nodes in preorder*/
    void printPreorder(node<Key, Value>* node) {
        if (node == NULL)
            return;

        /* first print data of node */
        cout << node->val << " ";

        /* then recur on left sutree */
        printPreorder(node->left);

        /* now recur on right subtree */
        printPreorder(node->right);
    }
};