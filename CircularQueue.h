#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED

#include "BinaryNode.h"
#include <string>

using namespace std;

inline void error( string str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

#define MAX_QUEUE_SIZE 100

class CircularQueue {
    int front;
    int rear;
    BinaryNode *data[MAX_QUEUE_SIZE];
public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; }
    void enqueue(BinaryNode *n) {
        if(isFull())
            error(" Error: queue is full\n");
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }
    BinaryNode *dequeue() {
        if(isEmpty())
            error(" Error: queue is empty\n");
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};

#endif // CIRCULARQUEUE_H_INCLUDED
