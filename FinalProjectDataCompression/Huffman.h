//
// Created by Sam Feig on 12/3/18.
//

#ifndef FINALPROJECTDATACOMPRESSION_HUFFMAN_H
#define FINALPROJECTDATACOMPRESSION_HUFFMAN_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

template<typename T>
class Node;

typedef Node<char> Symbol;
typedef shared_ptr<Symbol> SymbolPtr;

template<typename T>
class Node {
public:
    Node(const T v) {
        left = right = nullptr;
        count = 1;
        value = v;
    }

    Node(const int c, const shared_ptr<Node> &l, const shared_ptr<Node> &r) {
        left = l;
        right = r;
        count = c;
    }

    int getCount() {
        return count;
    }

    T getValue() {
        return value;
    }

    bool hasLeft() {
        return left != nullptr;
    }

    bool hasRight() {
        return right != nullptr;
    }

    const shared_ptr<Node<T>> &getLeft() {
        return left;
    }

    const shared_ptr<Node<T>> &getRight() {
        return right;
    }

    Node<T> &operator++() {
        count++;
        return *this;
    }

private:
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;
    int count;
    T value;
};

class Huffman {
public:
    Huffman(const string&);

    string encode(const string&) const;
    string decode(const string& binary_data_str) const;

private:
    void init(const string& data);
    void createBinaryTree(vector<SymbolPtr>&);
    void createHashTable(map<char, SymbolPtr>);

    map<char, SymbolPtr> createDictionary(const string& data) const;
    vector<SymbolPtr> moveToVector(map<char, SymbolPtr>& dictionary) const;
    string findPath(Symbol& node, const char& c, bool& flag, const string& path = "");
    char findSymbol(Symbol& node, const char* path, unsigned long& i) const;

    SymbolPtr binary_tree;
    map<char, string> hash_table;
};

#endif //FINALPROJECTDATACOMPRESSION_HUFFMAN_H