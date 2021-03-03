#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    if(front != (back+2)%size) {
        back = (back+1)%size;
        array[back] = value;
        return true;
    } else {
        return false;
    }
    
}

int IntegerArrayQueue::dequeue() {
    int rValue = 0;
    if(front == (back+1)%size) {
        return 0;
    } else {
        rValue = array[front];
        array[front] = 0;
        front++;
        return rValue;
    }
}