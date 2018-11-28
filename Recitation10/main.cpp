#include <iostream>
#include <chrono>
#include "trie.cpp"
using namespace std;

int main() {
    trie t;
    string keys[] = {"the", "the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their", "therefore"};

    int n = sizeof(keys)/sizeof(keys[0]);

    trie::TrieNode *root = t.getNode();

    for (int i = 0; i < n; i++) {
        t.insert(root, keys[i]);
    }

    t.search(root, "the")? cout<< "Yes " <<t.searchNode(root, "the")->occurrences <<endl : cout<< "No 0\n";
    t.search(root, "these")? cout<< "Yes " <<t.searchNode(root, "these")->occurrences <<endl : cout<< "No 0\n";
    t.search(root, "therefore")? cout<< "Yes " <<t.searchNode(root, "therefore")->occurrences <<endl : cout<< "No 0\n";
    return 0;
}