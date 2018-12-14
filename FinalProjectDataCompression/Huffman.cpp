//
// Created by Sam Feig on 12/3/18.
//

#include "Huffman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>
#include <stdexcept>
using namespace std;

Huffman::Huffman(const string& data) {
    init(data);
}

void Huffman::init(const string& data) {
    auto symbols_dictionary = createDictionary(data);
    auto symbols_vec = moveToVector(symbols_dictionary);

    createBinaryTree(symbols_vec);
    createHashTable(symbols_dictionary);
}

map<char, SymbolPtr> Huffman::createDictionary(const string& data) const {
    map<char, SymbolPtr> symbols_dict;
    for (const auto& c: data)
    {
        auto pos = symbols_dict.find(c);
        if (pos != symbols_dict.end())
        {
            ++(*pos->second);
            continue;
        }
        symbols_dict.insert(make_pair(c, static_pointer_cast<Symbol>(make_shared<Symbol>(c))));
    }
    return symbols_dict;
}

vector<SymbolPtr> Huffman::moveToVector(map<char, SymbolPtr>& dictionary) const {
    vector<SymbolPtr> symbols;
    symbols.reserve(dictionary.size());
    for_each(dictionary.begin(), dictionary.end(), [&symbols](pair<const char, SymbolPtr>& symbol) {
        symbols.push_back(move(symbol.second));
    });
    return symbols;
}

void Huffman::createBinaryTree(vector<SymbolPtr>& vec) {
    auto symbol_comparator = [](const SymbolPtr a, const SymbolPtr b) {
        return a->getCount() < b->getCount();
    };

    while (vec.size() > 1) {
        std::sort(vec.begin(), vec.end(), symbol_comparator);

        auto left = vec.front(), right = (*++vec.begin());
        auto node = new Node<char>(left->getCount() + right->getCount(), left, right);

        vec.erase(vec.begin(), vec.begin() + 2);
        vec.push_back(SymbolPtr(node));
    }
    binary_tree = vec.front();
}

void Huffman::createHashTable(map<char, SymbolPtr> dictionary) {
    for (const auto& sym: dictionary) {
        auto exists = false;
        auto path = findPath(*binary_tree, sym.first, exists);

        if (!exists) throw runtime_error("Exception: Invalid dictionary for given data.");

        hash_table.insert(pair<char, string>(sym.first, path));
    }
}

string Huffman::findPath(Symbol& node, const char& c, bool& flag, const string& path) {
    if(flag) {
        return path;
    }

    auto result(path);
    if(node.hasLeft()){
        result = findPath(*node.getLeft(), c, flag, path + "0");
    }
    if(node.hasRight() && !flag) {
        result = findPath(*node.getRight(), c, flag, path + "1");
    }
    if(!node.hasLeft() && !node.hasRight() && node.getValue() == c) {
        flag = true;
    }
    return result;
}

string Huffman::encode(const string& data) const {
    const short byte_size = 8;
    stringstream encoded_stream;
    for (const auto& c : data)
        encoded_stream << hash_table.at(c);

    auto result_str = encoded_stream.str();
    for (auto i = 0; i < result_str.size() % byte_size; i++)
        result_str += "0";

    return result_str;
}

string Huffman::decode(const string& binary_data_str) const {
    stringstream decoded_data;
    const char * const binary_str = binary_data_str.c_str();
    unsigned long i = 0;
    while (strstr(binary_str + i, "1")) {
        decoded_data << findSymbol(*binary_tree, binary_str + i, i);
    }
    return decoded_data.str();
}

char Huffman::findSymbol(Symbol& node, const char* const path, unsigned long& i) const {
    if (!node.hasLeft() && !node.hasRight()) {
        return node.getValue();
    }
    if (*path == '0' && node.hasLeft()) {
        return findSymbol(*node.getLeft(), path + 1, ++i);
    }
    if (*path == '1' && node.hasRight()) {
        return findSymbol(*node.getRight(), path + 1, ++i);
    }
    return 0;
}
