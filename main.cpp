#include "BinaryTree.h"

int main(void)
{
    BinaryTree tree;
    BinaryNode *d = new BinaryNode('D', nullptr, nullptr);
    BinaryNode *e = new BinaryNode('E', nullptr, nullptr);
    BinaryNode *b = new BinaryNode('B', d, e);
    BinaryNode *f = new BinaryNode('F', nullptr, nullptr);
    BinaryNode *c = new BinaryNode('C', f, nullptr);
    BinaryNode *a = new BinaryNode('A', b, c);

    tree.setRoot(a);
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();
    printf("\n");
    return 0;
}
