//
// Created by Sam Feig on 10/15/18.
// Assignment 7
// CSCI 2275
//
#include <iostream>
#include "MovieTree.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    MovieTree mt(argv);

//    cout<<"------------------------"<<endl;
//    cout<<"Add to root"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Add to right"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(2,"The Godfather",1972,34);
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Add to left"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(46,"Apocalypse Now",1979,5);
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Add already a node in BST"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(35,"Spirited Away",2001,10);
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Delete from right"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(2,"The Godfather",1972,34);
//        a->addMovieNode(46,"Apocalypse Now",1979,5);
//        a->deleteMovieNode("The Godfather");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Delete from left"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(2,"The Godfather",1972,34);
//        a->addMovieNode(46,"Apocalypse Now",1979,5);
//        a->deleteMovieNode("Apocalypse Now");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Delete from root"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->deleteMovieNode("Shawshank Redemption");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Delete non-existant heap node"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->deleteMovieNode("Spirited Away");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Delete non-existant BST node"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->deleteMovieNode("test");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Rent movie with quantity 1"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,1);
//        a->rentMovie("Shawshank Redemption");
//        a->printMovieInventory();
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//    cout<<"------------------------"<<endl;
//    cout<<"Rent movie with quantity 0"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,1);
//        a->rentMovie("Shawshank Redemption");
//        cout<<endl;
//        a->rentMovie("Shawshank Redemption");
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//
//    cout<<"------------------------"<<endl;
//    cout<<"Find movie"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,1);
//        a->findMovie("Shawshank Redemption");
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//
//    cout<<"------------------------"<<endl;
//    cout<<"Find move that doesnt exist"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->findMovie("Shawshank Redemption");
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//
//    cout<<"------------------------"<<endl;
//    cout<<"Print between"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(27,"Once Upon a Time in the West",1968,12);
//        a->addMovieNode(28,"Leon: The Professional",1994,31);
//        a->addMovieNode(29,"Life Is Beautiful",1997,3);
//        a->addMovieNode(30,"Casablanca",1942,5);
//
//        a->printTop10Between('A', 'M');
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//
//    cout<<"------------------------"<<endl;
//    cout<<"Print between that dont exist"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(27,"Once Upon a Time in the West",1968,12);
//        a->addMovieNode(28,"Leon: The Professional",1994,31);
//        a->addMovieNode(29,"Life Is Beautiful",1997,3);
//        a->addMovieNode(30,"Casablanca",1942,5);
//
//        a->printTop10Between('A', '#');
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
//
//    cout<<"------------------------"<<endl;
//    cout<<"Print between backwards"<<endl;
//    try {
//        MovieTree* a = new MovieTree();
//        a->addMovieNode(1,"Shawshank Redemption",1994,45);
//        a->addMovieNode(27,"Once Upon a Time in the West",1968,12);
//        a->addMovieNode(28,"Leon: The Professional",1994,31);
//        a->addMovieNode(29,"Life Is Beautiful",1997,3);
//        a->addMovieNode(30,"Casablanca",1942,5);
//
//        a->printTop10Between('M', 'A');
//    }
//    catch(exception& e){
//        cout<<e.what()<<endl;
//    }
    return 0;
}