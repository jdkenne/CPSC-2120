#include "minHeap.h"


minHeap::minHeap(vector<int> data)
{
    heap = data;
    int length = data.size();
    for(int i=length-1; i>=0; --i)
    {
        siftDown(i);
    }
}

void minHeap::siftDown(int pos)
{
    int parent = pos;
    int cOne = 2*parent + 1;
    int cTwo = 2*parent + 2;
    int swappedChild = -1;
    
    if(cOne < (int)heap.size() && heap[cOne] < heap[parent]) {
        swappedChild = cOne;
    }
    
    if(cTwo < (int)heap.size() && heap[cTwo] < heap[parent]) {
        if(swappedChild == -1) {
            swappedChild = cTwo;
        } else {
            if(heap[cTwo] < heap[cOne]) {
                swappedChild = cTwo;
            }
        }
    }
    if(swappedChild == -1) {
        return;
    }
    int temp = heap[parent];
    heap[parent] = heap[swappedChild];
    heap[swappedChild] = temp;
    siftDown(swappedChild);
}

void minHeap::siftUp(int pos)
{
    int parent = (pos-1)/2;
    int child = pos;
    
    while(child != 0 && heap[parent] > heap[child]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = (parent-1)/2;
    }
}

void minHeap::insert(int value)
{
    heap.push_back(value);
    int length = heap.size()-1;
    siftUp(length);
}


int minHeap::removeMin()
{
    if(heap.size() == 0) {
        return -1;
    }
    int temp = heap[0];
    heap[0] = heap[heap.size()-1];
    heap[heap.size()-1] = temp;
    heap.pop_back();
    siftDown(0);
    return temp;
}