#include "stdio.h"
#include <iostream>
#include "multiTree.h"

using namespace std;

/*
To demonstrate the creation of the generic tree and accessing nodes using the right pointer
*/
int main()
{
    multiTree::Node rtm = multiTree::Node(4); //rtm is the root node of the Generic Tree
    rtm.addChildren(8);
    rtm.addChildren(20);
    rtm.addChildren(40);
    multiTree::Node *child1 = rtm.getChilderen(0);
    child1->addChildren(30);
    child1->addChildren(50);
    multiTree::Node *childN = rtm.getChilderen(2);
    childN->addChildren(70);

    cout
        << "================ BEFORE SETTING RIGHT POINTER ====================" << endl;
    rtm.listNode(); //Listing all the nodes before setting the right pointer

    rtm.setRightPointer(); //setting the right pointer

    cout << "================ AFTER SETTING RIGHT POINTER ====================" << endl;
    rtm.listNodeByLevel(); //Listing all the nodes after setting the right pointer

    cout << "Total no.of levels in the tree is : " << rtm.getTotalLevels() << endl;

    return 0;
}
