//
// Created by Sam Feig on 11/28/18.
//

#include <iostream>
using namespace std;
class trie {
    const static int ALPHABET_SIZE = 26;
public:
    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];
        bool isEndOfWord;
        int occurrences = 0;
    };

    struct TrieNode *getNode() {
        TrieNode *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for(int i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = nullptr;
        }

        return pNode;
    }

    void insert(TrieNode *root, string key) {
        if(root == nullptr) {
            return;
        }
        TrieNode *crawl = root;

        if(search(root, key)) {
            TrieNode* tmp = searchNode(root, key);
            tmp->occurrences++;
            return;
        }

        for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = getNode();
            }
            crawl = crawl->children[index];

        }
        crawl->isEndOfWord = true;
        crawl->occurrences = 1;
    }

    bool search(TrieNode *root, string key) {
        TrieNode *crawl = root;

        for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                return false;
            }
            crawl = crawl->children[index];
        }

        return (crawl != nullptr && crawl->isEndOfWord);
    }

    TrieNode* searchNode(TrieNode *root, string key) {
        TrieNode *crawl = root;

        for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                return nullptr;
            }
            crawl = crawl->children[index];
        }

        if((crawl != nullptr && crawl->isEndOfWord)) {
            return crawl;
        }
        return nullptr;
    }
};