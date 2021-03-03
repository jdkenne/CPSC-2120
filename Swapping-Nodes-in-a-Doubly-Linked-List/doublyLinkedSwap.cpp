#include "doublyLinkedSwap.h"

void swapWithNext(Node * p) {
    //this if statement checks end cases
    if (p == nullptr || p->next == nullptr || p->next->next == nullptr || p->prev == nullptr) {    
       return;
    }
    //this part swaps the nodes
    Node * afterP = p->next;
    Node * beforeP = p->prev;
    afterP->prev = beforeP;
    beforeP->next = afterP;
    p->prev = afterP;
    p->next = afterP->next;
    afterP->next->prev = p;
    afterP->next = p;
}