//
// Created by Sam Feig on 10/6/18.
//

#include <iostream>
#include <fstream>
#include "CommunicationsNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork(char* argv[]) {
    readFile(argv[1]);

    string input, name, prev, word;
    bool quit = false;
    while(!quit) {
        cout<<endl;
        printMenu();
        cin >> input;
        switch(stoi(input)) {
            case 1: //Build Network
                network.clearNetwork();
                network.buildNetwork();
                network.printNetwork();
                break;
            case 2: //Print Path
                network.printNetwork();
                break;
            case 3: //Enqueue
                if(!(wordLoc == msg.size())) {
                    queue.enqueue(*(msg.begin() + wordLoc));
                    wordLoc++;
                }
                else {
                    cout<<"Message already fully transmitted" <<endl;
                }
                break;
            case 4: //Dequeue
                if(network.head == NULL) {
                    cout<<"Build a network before attempting to transmit a message" <<endl;
                    break;
                }

                if(!queue.isEmpty()) {
                    word = queue.dequeue();
                    network.transmitMsg(word);
                }
                else {
                    cout<<"Queue is empty" <<endl;
                }
                break;
            case 5: //Print Queue
                queue.displayQueue();
                break;
            case 6: //Send Entire Message
                if(network.head == NULL) {
                    cout<<"Build a network before attempting to transmit a message" <<endl;
                    break;
                }
                transmitBufferedMsg();
                break;
            case 7: //Quit
                cout<<"Quitting!" <<endl;
                quit = true;
                break;
            default:
                cout<<"That was not a valid input. Please try again."<<endl;
        }
    }
}

CommunicationNetwork::~CommunicationNetwork(){
    network.clearNetwork();
}

void CommunicationNetwork::readFile(string filename) {
    ifstream file(filename);
    string line;
    while(file >> line) {
        msg.push_back(line);
    }
//    for(auto i: msg) {
//        cout << i << " ";
//    }
}

void CommunicationNetwork::transmitBufferedMsg() {
    while(wordLoc < msg.size()) {
        if(queue.isFull()) {
            queue.displayQueue();
            while(!queue.isEmpty()) {
                network.transmitMsg(queue.dequeue());
            }
        }
            queue.enqueue(*(msg.begin() + wordLoc));
            wordLoc++;
    }
    if(wordLoc == msg.size()) {
        while(!queue.isEmpty()) {
            network.transmitMsg(queue.dequeue());
        }
    }
}

void CommunicationNetwork::printMenu() {
    cout<<"======Main Menu====== " <<endl;
    cout<<"1. Build Network" <<endl;
    cout<<"2. Print Network Path" <<endl;
    cout<<"3. Enqueue" <<endl;
    cout<<"4. Dequeue" <<endl;
    cout<<"5. Print Queue" <<endl;
    cout<<"6. Send Entire Message" <<endl;
    cout<<"7. Quit" <<endl;
}

///**Insert a new city into the linked list after the previousCity. The name of the new
//city is in the argument newCity. */
//void CommunicationNetwork::addCity(string previousCity, string newCity) {
//    if(previousCity == "First") {
//        City* newNode = new City(newCity, head,  NULL, "");
//        if(head == NULL) {
//            head = newNode;
//        }
//        else {
//            newNode->next->previous = newNode;
//            head = newNode;
//        }
//    }
//    else if(previousCity == "Last") {
//        City* newNode = new City(newCity, NULL,  tail, "");
//        if(tail == NULL) {
//            tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//    else {
//        City *prev = search(previousCity);
//        City* newNode = new City(newCity, NULL, NULL, "");
//        if(prev == NULL) {
//             if(head == NULL) {
//                 head = newNode;
//             }
//           newNode->next = head;
//           head->previous = newNode;
//           head = newNode;
//        }
//        else if(prev->next == NULL) {
//            prev->next = newNode;
//            newNode->previous = prev;
//            tail = newNode;
//        }
//        else {
//            prev->next->previous = newNode;
//            newNode->previous = prev;
//            newNode->next = prev->next;
//            prev->next = newNode;
//        }
//    }
//}
//
///**Open the file and transmit the message between all cities in the network word by
//word. A word needs to be received at the end of the network before sending the next
//word. Only one city can hold the message at a time; as soon as it is passed to the next
//city, it needs to be deleted from the sender city. Once the message reaches the end of
//the network, it needs to be transmitted back the other direction to the beginning of
//the network. */
//void CommunicationNetwork::transmitMsg(string word) {
//    City* current;
//    if(head == NULL) {
//        cout<<"Network Not Initialized." <<endl;
//        return;
//    }
//    current = head;
//    while(current != NULL) {
//        current->message = word;
//        cout << current->cityName << " recieved " << current->message << endl;
//
//        current->message = "";
//        current = current->next;
//    }
//    current = tail->previous;
//    while(current != NULL) {
//        current->message = word;
//        cout << current->cityName << " recieved " << current->message << endl;
//
//        current->message = "";
//        current = current->previous;
//    }
//}
//
///**Start at the head of the linked list and print the name of each city in order to the
//end of the list. */
//void CommunicationNetwork::printNetwork() {
//    City *tmp = head;
//    cout<<"NULL <- ";
//    while(tmp != NULL) {
//        cout<<tmp->cityName;
//        tmp = tmp->next;
//        if(tmp != NULL) {
//            cout<<" <-> ";
//        }
//    }
//    cout<<" -> NULL";
//    cout<<endl;
//}
//
///**Build the initial network from the cities given in this writeup. The cities can be
//fixed in the function, you do not need to write the function to work with any list of
//cities. */
//void CommunicationNetwork::buildNetwork() {
//   // head = new City("Los Angeles", NULL, NULL, "");
//    addCity("First", "Los Angeles");
//    addCity("Los Angeles", "Phoenix");
//    addCity("Phoenix", "Denver");
//    addCity("Denver", "Dallas");
//    addCity("Dallas", "St. Louis");
//    addCity("St. Louis", "Chicago");
//    addCity("Chicago", "Atlanta");
//    addCity("Atlanta", "Washington, D.C.");
//    addCity("Washington, D.C.", "New York");
//    addCity("New York", "Boston");
////    tail = new City("Boston", search("New York"), NULL, "");
//}
//
///**Find the city in the network where city name matches cityNameDelete. Change the
//next and previous pointers for the surrounding cities and free the memory. */
//void CommunicationNetwork::deleteCity(string cityNameDelete) {
//    City* node = search(cityNameDelete);
//    if(node == NULL) {
//        cout<<"City not found." <<endl;
//    }
//    else if(node == head) {
//        head = head->next;
//        head->previous = NULL;
//        delete node;
//    }
//    else if(node == tail) {
//        tail = tail->previous;
//        tail->next = NULL;
//        delete node;
//    }
//    else {
//        node->previous->next = node->next;
//        node->next->previous = node->previous;
//        delete node;
//    }
//}
//
///**Delete all cities in the network, starting at the head city. */
//void CommunicationNetwork::clearNetwork() {
//    City* current = head;
//    City* next = NULL;
//    while(current != NULL) {
//        next = current->next;
//        cout<<"deleting "<<current->cityName <<endl;
//        delete current;
//        current = next;
//    }
//    head = tail = NULL;
//}
//
///** search the network for a specific city name. */
//City* CommunicationNetwork::search(std::string key) {
//    City* current = head;
//    while(current != NULL) {
//        if(current->cityName == key) {
//            return current;
//        }
//        current = current->next;
//    }
//    return NULL;
//}
