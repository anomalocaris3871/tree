#include "BinaryTree.h"
#include "BinSrchTree.h"
#include "ThreadedBinTree.h"

int main(void)
{
    BinaryTree tree;

    //BinaryNode *j = new BinaryNode('J', nullptr, nullptr);
    BinaryNode *i = new BinaryNode('I', nullptr, nullptr);
    //BinaryNode *h = new BinaryNode('H', nullptr, nullptr);
    //BinaryNode *g = new BinaryNode('G', nullptr, nullptr);
    BinaryNode *d = new BinaryNode('D', nullptr, i);
    BinaryNode *e = new BinaryNode('E', nullptr, nullptr);
    BinaryNode *b = new BinaryNode('B', d, e);
    BinaryNode *f = new BinaryNode('F', nullptr, nullptr);
    BinaryNode *c = new BinaryNode('C', f, nullptr);
    BinaryNode *a = new BinaryNode('A', b, c);

    printf("BinaryTree\n");
    tree.setRoot(a);
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    printf("the number of node = %d\n", tree.getCount());
    printf("the number of leaf = %d\n", tree.getLeafCount());
    printf("the number of height = %d\n", tree.getHeight());

    printf("This tree is ");
    if(tree.isFull())
        printf("full binary tree\n");
    else
        printf("not full binary tree\n");

    printf("node %c\'s level is %d\n",'b', tree.level(a,b,1));

    if(tree.isBalanced())
        printf("this tree is balnced\n");
    else
        printf("this tree is unbalanced\n");
    printf("\n");

    printf("the path length of tree : %d\n", tree.pathLength());

    tree.reverse();


    printf("BinaryTree\n");
    tree.setRoot(a);
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();


    printf("================================================================\n");

    printf("ThreadBinaryTree\n\n");

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

    printf("================================================================\n");

    BinSrchTree bintree;

    bintree.insert(new BinaryNode(35));
    bintree.insert(new BinaryNode(18));
    bintree.insert(new BinaryNode(7));
    bintree.insert(new BinaryNode(26));
    bintree.insert(new BinaryNode(12));
    bintree.insert(new BinaryNode(3));
    bintree.insert(new BinaryNode(68));
    bintree.insert(new BinaryNode(22));
    bintree.insert(new BinaryNode(30));
    bintree.insert(new BinaryNode(99));

    printf("BinarySearchTree\n\n");
    printf("the number of node : %d\n", bintree.getCount());
    printf("the number of leaf : %d\n", bintree.getLeafCount());
    printf("the height of tree : %d\n", bintree.getHeight());

    bintree.inorder();
    bintree.preorder();
    bintree.postorder();
    bintree.levelorder();

    bintree.search(26);
    bintree.search(25);

    printf("\ncase 1 ==> delete of node 3\n");
    bintree.remove(3);
    bintree.levelorder();

    printf("\ncase 2 ==> delete of node 68\n");
    bintree.remove(68);
    bintree.levelorder();

    printf("\ncase 3 ==> delete of node 18\n");
    bintree.remove(18);
    bintree.levelorder();

    printf("\ncase 3 ==> delete of node 35(delete of root node)\n");
    bintree.remove(35);
    bintree.levelorder();

    printf("the number of node : %d\n", bintree.getCount());
    printf("the number of leaf : %d\n", bintree.getLeafCount());
    printf("the height of tree : %d\n", bintree.getHeight());
    return 0;
}
