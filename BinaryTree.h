#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "CircularQueue.h"

class BinaryTree {
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
            printf(" [%c] ", node->getData());
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
            printf(" [%c] ", node->getData());
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
            printf(" [%c] ", node->getData());
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
                    printf(" [%c] ", n->getData());
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
            printf("\n");
        }
    }

    int getCount() {}
    int getHeight() {}
    int getLeafCount() {}
};


#endif // BINARYTREE_H_INCLUDED
