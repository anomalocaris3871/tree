#ifndef THREADEDBINNODE_H_INCLUDED
#define THREADEDBINNODE_H_INCLUDED

#include "ThreadBinaryNode.h"

class ThreadedBinTree {
    ThreadedBinNode *root;
public:
    ThreadedBinTree(): root(nullptr) {}
    void setRoot(ThreadedBinNode *node) { root = node; }
    bool isEmpty() { return root == nullptr; }

    void threadedInorder() {
        if(!isEmpty()) {
            printf("ThreadBinaryTree: ");
            ThreadedBinNode *q = root;
            while(q->getLeft())             //Go to the leftmost node
                q = q->getLeft();
            do {
                printf("%c ", q->getData());
                q = findSuccessor(q);       //Call successor function
            } while(q);
            printf("\n");

        }
    }

    ThreadedBinNode *findSuccessor(ThreadedBinNode *p) {
        ThreadedBinNode *q = p->getRight();

        if(q == nullptr || p->bThread )      //If the right pointer is null or thread, return the right pointer.
            return q;
        while(q->getLeft() != nullptr)
            q = q->getLeft();
        return q;
    }
};

#endif // THREADEDBINNODE_H_INCLUDED
