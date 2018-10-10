//
// Created by Sam Feig on 10/1/18.
//
#include <iostream>
#include <exception>

template <class T> class Stack {
    struct Node {
        T item;
        Node* next;
    };
    int N;          // size of the stack
    Node first;     // top of stack
public:
/**
  * Create an empty stack.
  */
    Stack() {
        first = NULL;
        N = 0;
    }

/**
  * Is the stack empty?
  */
    bool isEmpty() {
        return first == NULL;
    }

/**
  * Return the number of items in the stack.
  */
    int size() {
        return N;
    }

/**
  * Add the item to the stack.
  */
    void push(T item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;
    }

/**
  * Delete and return the item most recently added to the stack.
  * Throw an exception if no such item exists because the stack is empty.
  */
T pop() {
      if (isEmpty()) throw std::runtime_error("Stack underflow");
        T item = first.item;        // save item to return
        first = first.next;            // delete first node
        N--;
        return item;
        // return the saved item
}


/**
  * Return the item most recently added to the stack.
  * Throw an exception if no such item exists because the stack is empty.
  */
    T peek() {
        if (isEmpty()) throw std::runtime_error("Stack underflow");
            return first.item;
    }

/**
  * Return string representation.
  */
//    std::string toString() {
//        StringBuilder s = new StringBuilder();
//        for (T item : this)
//            s.append(item + " ");
//        return s.toString();
//    }


/**
  * Return an iterator to the stack that iterates through the items in LIFO order.
  */
class Iterator: public std::iterator<std::forward_iterator_tag, T> {
    Node current = first;

    Iterator begin() {
        return (Iterator(first));
    }
    Iterator end() {
        return (Iterator(NULL));
    }
    bool hasNext() { return current != NULL; }

    T next() {
        if (!hasNext()) throw std::runtime_error("No Next Value");
        T item = current.item;
        current = current.next;
        return item;
    }
};
};