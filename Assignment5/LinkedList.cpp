//
// Created by Sam Feig on 10/6/18.
//

#include <iostream>
using namespace std;

class LinkedList{
public:
    struct City {
        std::string cityName;
        std::string message;
        City *next;
        City *previous;

        City() {}; // default constructor

        City(std::string
        initName, City * initNext, City * initPrevious, std::string
        initMessage) {
            cityName = initName;
            next = initNext;
            previous = initPrevious;
            message = initMessage;
        }
    };

    City *head;
    City *tail;

    LinkedList() {}

    /**Build the initial network from the cities given in this writeup. The cities can be
fixed in the function, you do not need to write the function to work with any list of
cities. */
    void buildNetwork() {
        // head = new City("Los Angeles", NULL, NULL, "");
        addCity("First", "Los Angeles");
        addCity("Los Angeles", "Phoenix");
        addCity("Phoenix", "Denver");
        addCity("Denver", "Dallas");
        addCity("Dallas", "St. Louis");
        addCity("St. Louis", "Chicago");
        addCity("Chicago", "Atlanta");
        addCity("Atlanta", "Washington, D.C.");
        addCity("Washington, D.C.", "New York");
        addCity("New York", "Boston");
//    tail = new City("Boston", search("New York"), NULL, "");
    }

    void addCity(string previousCity, string newCity) {
        if(previousCity == "First") {
            City* newNode = new City(newCity, head,  NULL, "");
            if(head == NULL) {
                head = newNode;
            }
            else {
                newNode->next->previous = newNode;
                head = newNode;
            }
        }
        else if(previousCity == "Last") {
            City* newNode = new City(newCity, NULL,  tail, "");
            if(tail == NULL) {
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        else {
            City *prev = search(previousCity);
            City* newNode = new City(newCity, NULL, NULL, "");
            if(prev == NULL) {
                if(head == NULL) {
                    head = newNode;
                }
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            else if(prev->next == NULL) {
                prev->next = newNode;
                newNode->previous = prev;
                tail = newNode;
            }
            else {
                prev->next->previous = newNode;
                newNode->previous = prev;
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }

    /**Delete all cities in the network, starting at the head city. */
    void clearNetwork() {
        City* current = head;
        City* next = NULL;
        while(current != NULL) {
            next = current->next;
            cout<<"deleting "<<current->cityName <<endl;
            delete current;
            current = next;
        }
        head = tail = NULL;
    }

    /**Find the city in the network where city name matches cityNameDelete. Change the
next and previous pointers for the surrounding cities and free the memory. */
    void deleteCity(string cityNameDelete) {
        City* node = search(cityNameDelete);
        if(node == NULL) {
            cout<<"City not found." <<endl;
        }
        else if(node == head) {
            head = head->next;
            head->previous = NULL;
            delete node;
        }
        else if(node == tail) {
            tail = tail->previous;
            tail->next = NULL;
            delete node;
        }
        else {
            node->previous->next = node->next;
            node->next->previous = node->previous;
            delete node;
        }
    }

    /** search the network for a specific city name. */
    City* search(std::string key) {
        City* current = head;
        while(current != NULL) {
            if(current->cityName == key) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    /**Start at the head of the linked list and print the name of each city in order to the
end of the list. */
    void printNetwork() {
        City *tmp = head;
        cout<<"NULL <- ";
        while(tmp != NULL) {
            cout<<tmp->cityName;
            tmp = tmp->next;
            if(tmp != NULL) {
                cout<<" <-> ";
            }
        }
        cout<<" -> NULL";
        cout<<endl;
    }

    /**Transmit the message between all cities in the network word by
word. A word needs to be received at the end of the network before sending the next
word. Only one city can hold the message at a time; as soon as it is passed to the next
city, it needs to be deleted from the sender city. Once the message reaches the end of
the network, it needs to be transmitted back the other direction to the beginning of
the network. */
    void transmitMsg(string word) {
        City* current;
        if(head == NULL) {
            cout<<"Network Not Initialized." <<endl;
            return;
        }
        current = head;
        while(current != NULL) {
            current->message = word;
            cout << current->cityName << " recieved " << current->message << endl;

            current->message = "";
            current = current->next;
        }
        current = tail->previous;
        while(current != NULL) {
            current->message = word;
            cout << current->cityName << " recieved " << current->message << endl;

            current->message = "";
            current = current->previous;
        }
    }
};