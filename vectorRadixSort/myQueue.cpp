#include "myQueue.h"
#include <iostream>
using namespace std;

myQueue::myQueue() {
    // No need to initialize elements in a vector
}

void myQueue::append(int element) {
    arr.push_back(element); // Use push_back to add element to the end
}

void myQueue::dequeue() {
    if (isEmpty()) {
        return;
    }
    arr.erase(arr.begin()); // Use erase to remove element from the beginning
}

bool myQueue::isEmpty() {
    return arr.empty(); // Use empty() to check if vector is empty
}

int myQueue::peekHead() {
    if (isEmpty()) {
        return -1;
    }
    return arr.front(); // Use front() to get the first element
}

int myQueue::peekTail() {
    if (isEmpty()) {
        return -1;
    }
    return arr.back(); // Use back() to get the last element
}

void myQueue::displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Head: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ",";
        }
    }
    cout << " : Tail" << endl;
}
