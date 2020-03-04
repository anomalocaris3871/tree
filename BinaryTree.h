#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "CircularQueue.h"
#include "math.h"
#include <bits/stdc++.h>

class BinaryTree {
protected :
    BinaryNode *root;
public:
    BinaryTree(): root(nullptr) {}
    void setRoot(BinaryNode *node) { root = node; }
    BinaryNode *getRoot();
    bool isEmpty() { return root==nullptr; }

    void inorder() {
        printf("\ninorder:      ");
        inorder(root);
    }

    void inorder(BinaryNode *node) const {
        if(node != nullptr) {
            if(node->getLeft() != nullptr)
                inorder(node->getLeft());
            printf(" [%d] ", node->getData());
            if(node->getRight() !=nullptr)
                inorder(node->getRight());
        }
    }

    void preorder() {
        printf("\npreorder:     ");
        preorder(root);
    }

    void preorder(BinaryNode *node) const {
        if(node != nullptr) {
            printf(" [%d] ", node->getData());
            if(node->getLeft() != nullptr)
                preorder(node->getLeft());
            if(node->getRight() != nullptr)
                preorder(node->getRight());
        }
    }

    void postorder() {
        printf("\npostorder:    ");
        postorder(root);
    }

    void postorder(BinaryNode* node) const {
        if(node != nullptr) {
            if(node->getLeft() != nullptr)
                postorder(node->getLeft());
            if(node->getRight() != nullptr)
                postorder(node->getRight());
            printf(" [%d] ", node->getData());
        }
    }
    void levelorder() {
        printf("\nlevelorder:   ");
        if(!isEmpty()) {
            CircularQueue q;
            q.enqueue(root);
            while( !q.isEmpty()) {
                BinaryNode *n = q.dequeue();
                if(n!= nullptr) {
                    printf(" [%d] ", n->getData());
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
            printf("\n");
        }
    }

    int getCount() {
        return isEmpty() ? 0 : getCount(root);
    }

    int getCount(const BinaryNode *node) {
        if(node == nullptr)
            return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getHeight() { return isEmpty() ? 0 : getHeight(root); }

    int getHeight(const BinaryNode *node) {
        if(node == nullptr)
            return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return ((hLeft>hRight) ? hLeft : hRight) + 1;
    }

    int getLeafCount() {return isEmpty() ? 0 : getLeafCount(root); }
    int getLeafCount(BinaryNode *node) {
        if(node == nullptr)
            return 0;
        if(node->isLeaf())
            return 1;
        else
            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    bool isFull() {
        if(!isEmpty()) {
            CircularQueue q;
            q.enqueue(root);
            while(!q.isEmpty()) {
                BinaryNode *n = q.dequeue();
                if(n->getLeft() == nullptr && n->getRight() != nullptr)
                    return false;
                else if(n->getLeft() != nullptr && n->getRight() == nullptr)
                    return false;

                if(n->getLeft())
                    q.enqueue(n->getLeft());
                if(n->getRight())
                    q.enqueue(n->getRight());

            }

            if(pow(2,getHeight())-1 == double(getCount()))
                return true;

            else
                false;

        } else
             return true;
    }

    int level(BinaryNode *root, BinaryNode *node, int lev)
    {
        if(root == nullptr)
            return 0;
        if(root == node)
            return lev;

        int left = level(root->getLeft(), node, lev + 1);
        int right = level(root->getRight(), node, lev + 1);

        if(left == 0)
            return right;
        else
            return left;
    }

    bool isBalanced() {
        vector<int> leafNodes;
        vector<int> &refLeafNode = leafNodes;
        getLeafLevel(root, refLeafNode);
        for(int i=0;i<leafNodes.size()-1;++i) {
            for(int j=1;j<leafNodes.size();++j)
            if((leafNodes[i] - leafNodes[j]) >= 2 || (leafNodes[j] - leafNodes[i]) >= 2)
                return false;
        }
        return true;
    }

    void getLeafLevel(BinaryNode *node, vector<int> &refLeafNode) {
        if(node == nullptr)
            return;

        if(node->isLeaf()){
            refLeafNode.push_back(level(root, node, 1));
        }

        else {
            getLeafLevel(node->getLeft(), refLeafNode);
            getLeafLevel(node->getRight(),refLeafNode);
        }
    }

    int pathLength() {
        int result = pathLength(root, 0);
        return result;
    }

    int pathLength(BinaryNode *node, int length) {
        if(node == nullptr)
            return 0;
        if(node->isLeaf())
            return length;

        return length + pathLength(node->getLeft(), length+1) + pathLength(node->getRight(), length+1);
    }

    void reverse() {
        reverse(root);
    }

    void reverse(BinaryNode *node) {
        if(node == nullptr)
            return;
        if(node->isLeaf())
            return;

        BinaryNode *temp = node->getLeft();
        node->setLeft(node->getRight());
        node->setRight(temp);

        reverse(node->getLeft());
        reverse(node->getRight());

    }
};


#endif // BINARYTREE_H_INCLUDED
