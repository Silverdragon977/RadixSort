#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
using namespace std;

class myQueue {
private:
    vector<int> arr; // Change from array to vector

public:
    myQueue();  
    void append(int element);
    void dequeue();
    bool isEmpty();
    int peekTail();
    int peekHead();
    void displayQueue();
};

#endif // MYQUEUE_H
