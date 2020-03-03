#ifndef BINSRCHTREE_H_INCLUDED
#define BINSRCHTREE_H_INCLUDED

#include "BinaryTree.h"

class BinSrchTree : public BinaryTree {
public:
    BinSrchTree(void) {}
    ~BinSrchTree(void) {}

    BinaryNode *search(int key) {
        BinaryNode *node = searchRecur(root, key);
        if(node != nullptr)
            printf("search success : the node with key value of %d = 0x%x\n", node->getData(), node);
        else
            printf("search fail : No node with key value of %d\n", key);
        return node;
    }
    BinaryNode *searchRecur(BinaryNode *n, int key) {
        if(n == nullptr) return nullptr;
        if(key == n->getData())
            return n;
        else if(key < n->getData())
            return searchRecur(n->getLeft(), key);
        else
            return searchRecur(n->getRight(), key);
    }

    void insert(BinaryNode *n) {
        if(n== nullptr) return;
        if(isEmpty()) root = n;
        else insertRecur(root, n);
    }

    void insertRecur(BinaryNode *r, BinaryNode *n) {
        if(n->getData() == r->getData())
            return;
        else if(n->getData() < r->getData()) {
            if(r->getLeft() == nullptr)
                r->setLeft(n);
            else
                insertRecur(r->getLeft(), n);
        }
        else {
            if(r->getRight() == nullptr)
                r->setRight(n);
            else
                insertRecur(r->getRight(), n);
        }

    }

    void remove(int key) {
        if(isEmpty()) return;

        BinaryNode *parent = nullptr;   // Parents of Nodes to be Deleted
        BinaryNode *node = root;        // the node to be Deleted
        while(node != nullptr && node->getData() != key) {
            parent = node;
            node = (key < node->getData())
                ? node->getLeft() : node->getRight();
        }

        if(node == nullptr) {
            printf(" Error : key is not in the tree!\n");
            return;
        }
        else {
            remove(parent, node);
        }
    }
    void remove(BinaryNode *parent, BinaryNode *node) {
        //The node you want to delete is a leaf node.
        if(node -> isLeaf()) {
            if(parent == nullptr)
                root = nullptr;
            else {
                if(parent->getLeft() == node)
                    parent->setLeft(nullptr);
                else
                    parent->setRight(nullptr);
            }

        }
        //The node you want to delete has only the left or right child.
        else if(node->getLeft() == nullptr || node->getRight() == nullptr) {
            BinaryNode *child = (node->getLeft() != nullptr)
                ? node->getLeft() : node->getRight();
            if(node == root)
                root = child;
            else {
                if(parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);
            }
        }
        //The node you want to delete has both children.
        else {
            //succp -> Parents of the succeeding Nodes
            //succ -> Successor node: Explore the smallest node in the right subtree

            BinaryNode *succp = node;
            BinaryNode *succ = node->getRight();
            while(succ->getLeft() != nullptr) {
                succp = succ;
                succ = node->getLeft();
            }

            if(succp->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());

            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }

};

#endif // BINSRCHTREE_H_INCLUDED
