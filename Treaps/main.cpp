#include <iostream>
#include "treap.cpp"

int main() {
    treap t;
    treap::TreapNode *root = nullptr;
    root = t.insert(root, 50);
    root = t.insert(root, 30);
    root = t.insert(root, 20);
    root = t.insert(root, 40);
    root = t.insert(root, 70);
    root = t.insert(root, 60);
    root = t.insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    t.inorder(root);

    cout << "\nDelete 20\n";
    root = t.deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    t.inorder(root);

    cout << "\nDelete 30\n";
    root = t.deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    t.inorder(root);

    cout << "\nDelete 50\n";
    root = t.deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    t.inorder(root);

    (t.search(root, 50) == nullptr)? cout << "\n50 Not Found ": cout << "\n50 found";

    return 0;
}