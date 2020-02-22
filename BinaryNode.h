#ifndef BINARYNODE_H_INCLUDED
#define BINARYNODE_H_INCLUDED

#include <cstdio>

class BinaryNode {
protected:
    int data;
    BinaryNode *left;
    BinaryNode *right;
public:

    BinaryNode(int val = 0, BinaryNode *l = nullptr, BinaryNode *r = nullptr)
        : data(val), left(l), right(r) { }
    void setData(int val) {
        data = val;
    }
    void setLeft(BinaryNode *l) {
        left = l;
    }
    void setRight(BinaryNode *r) {
        right = r;
    }
    int getData() { return data; }
    BinaryNode *getLeft() const { return left; }
    BinaryNode *getRight() const { return right; }
    bool isLeaf() { return left == nullptr && right == nullptr; }
};

#endif // BINARYNODE_H_INCLUDED
