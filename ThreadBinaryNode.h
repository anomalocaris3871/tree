#ifndef THREADBINARYNODE_H_INCLUDED
#define THREADBINARYNODE_H_INCLUDED

class ThreadedBinNode {
    int data;
    ThreadedBinNode *left;
    ThreadedBinNode *right;
public:
    bool bThread;
    ThreadedBinNode(int val, ThreadedBinNode *l, ThreadedBinNode *r, bool bTh)
        : data(val), left(l), right(r), bThread(bTh) { }
    int getData() { return data; }
    void setRight(ThreadedBinNode *r) { right = r; }
    ThreadedBinNode *getLeft() const { return left; }
    ThreadedBinNode *getRight() const { return right; }
};

#endif // THREADBINARYNODE_H_INCLUDED
