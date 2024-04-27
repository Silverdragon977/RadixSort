#include "myQueue.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <random>
#include <ctime>
using namespace std;



void generateRandNums(myQueue& vectorq, int sizeOfVector) {
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < sizeOfVector; i++) {
        int randomNum = rand() % 900000000 + 100000000; // Generate random number from 100,000,000 to 999,999,999
        vectorq.append(randomNum);
    }
}

myQueue radixSort(myQueue mainBin, int n) {
    myQueue sortedObject = mainBin; // Copy the mainBin to sortedObject

    for (int digit = 0; digit < n; digit++) {
        myQueue queues[10];

        while (!sortedObject.isEmpty()) {
            int num = sortedObject.peekHead();
            sortedObject.dequeue();
            int digitValue = (num / static_cast<int>(pow(10, digit))) % 10;
            queues[digitValue].append(num);
        }

        for (int i = 0; i < 10; i++) {
            while (!queues[i].isEmpty()) {
                int num = queues[i].peekHead();
                queues[i].dequeue();
                sortedObject.append(num);
            }
        }
        //cout << "Step " << digit+1 << endl;
        //sortedObject.displayQueue();
    }

    return sortedObject;
}

// This function will time the radix sorting algorithm
void timeRadixSort(myQueue& mainBin, int sizeOfVector) {
    generateRandNums(mainBin, sizeOfVector);

    //cout << "Unsorted Numbers: " << endl;
    //mainBin.displayQueue();
    
    //cout << "\n\n Now we implement Radix Sort: " << endl;
    clock_t start = clock(); // Record start time
    myQueue sortedObject = radixSort(mainBin, 9);
    clock_t end = clock();   // Record end time

    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << elapsed_secs << " seconds. Number Of items in queue: " << sizeOfVector << endl;

    //cout << "\nSorted numbers: " << endl;
    //sortedObject.displayQueue();
}


int main() 
{
//============================================================================//
////////////////////////////////////
//                                //
// Testing Queue class for errors //
//                                //
////////////////////////////////////
    myQueue queue1; // Test queue

    // Test append method
    queue1.append(10);
    queue1.append(20);
    assert(queue1.peekHead() == 10);
    assert(queue1.peekTail() == 20);

    // Test dequeue method
    queue1.dequeue();
    assert(queue1.peekHead() == 20);
    assert(queue1.peekTail() == 20);
    queue1.dequeue(); // Now the queue should be empty
    assert(queue1.isEmpty());

    // Test isEmpty method
    assert(queue1.isEmpty());

    // Test peekHead and peekTail methods on an empty queue
    assert(queue1.peekHead() == -1);
    assert(queue1.peekTail() == -1);
//============================================================================//

//============================================================================//
      //  Now we are using the myQueue class to replicate Radix Sort  //

    std::vector<int> vectorSizes = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    for (int i = 0; i < vectorSizes.size(); i++) {
        int size = vectorSizes[i];
        std::cout << "\nTiming with size " << size << "..." << std::endl;

        myQueue mainBin; // Assuming you have a myQueue object
        generateRandNums(mainBin, size); // Generate random 9-digit numbers and enqueue them

        timeRadixSort(mainBin, size); // Assuming timeRadixSort function accepts a myQueue object

        std::cout << "===================================" << std::endl;
    } 

    return 0;

}




