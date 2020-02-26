#include "BinaryTree.h"
#include "ThreadedBinTree.h"

int main(void)
{
    BinaryTree tree;

    BinaryNode *i = new BinaryNode('I', nullptr, nullptr);
    BinaryNode *h = new BinaryNode('H', nullptr, nullptr);
    BinaryNode *g = new BinaryNode('G', nullptr, nullptr);
    BinaryNode *d = new BinaryNode('D', h, i);
    BinaryNode *e = new BinaryNode('E', nullptr, nullptr);
    BinaryNode *b = new BinaryNode('B', d, e);
    BinaryNode *f = new BinaryNode('F', nullptr, nullptr);
    BinaryNode *c = new BinaryNode('C', f, g);
    BinaryNode *a = new BinaryNode('A', b, c);


    tree.setRoot(a);
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();
    printf("\n");
    printf("the number of node = %d\n", tree.getCount());
    printf("the number of leaf = %d\n", tree.getLeafCount());
    printf("the number of height = %d\n", tree.getHeight());

    if(tree.isFull())
        printf("full binary tree\n");
    else
        printf("not full binary tree\n");

    printf("\n");







    ThreadedBinTree Thtree;

    ThreadedBinNode *n1 = new ThreadedBinNode('A', nullptr, nullptr, true);
    ThreadedBinNode *n2 = new ThreadedBinNode('B', nullptr, nullptr, true);
    ThreadedBinNode *n3 = new ThreadedBinNode('C', n1, n2, false);
    ThreadedBinNode *n4 = new ThreadedBinNode('D', nullptr, nullptr, true);
    ThreadedBinNode *n5 = new ThreadedBinNode('E', nullptr, nullptr, false);
    ThreadedBinNode *n6 = new ThreadedBinNode('F', n4, n5, false);
    ThreadedBinNode *n7 = new ThreadedBinNode('G', n3, n6, false);

    Thtree.setRoot(n7);

    n1->setRight(n3);
    n2->setRight(n7);
    n4->setRight(n6);

    Thtree.threadedInorder();
    return 0;
}
