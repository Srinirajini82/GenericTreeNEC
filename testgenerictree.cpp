#include "stdio.h"
#include <iostream>
#include "multiTree.h"

using namespace std;

/*
To demonstrate the creation of the generic tree and accessing nodes using the right pointer
*/
int main(){
    multiTree::Node rtm = multiTree::Node(4);  //rtm is the root node of the Generic Tree
    rtm.addChildren(8);
    rtm.addChildren(20); // Children at Level-1
    multiTree::Node *chld = rtm.getChilderen(0);
    chld->addChildren(30);
    chld->addChildren(40); //children at level-2
    multiTree::Node *chld1 = chld->getChilderen(0);
    chld1->addChildren(4);
    chld1->addChildren(15); //children at level-3
    multiTree::Node *chld2 = chld1->getChilderen(0);
    chld2->addChildren(9); //children at level-4 with no sibllings
    multiTree::Node *chld3 = chld2->getChilderen(0);
    chld3->addChildren(8);
    chld3->addChildren(18);
    chld3->addChildren(28); //Children at level-5 with three sibllings

    cout << "================ BEFORE SETTING RIGHT POINTER ====================" << endl;
    rtm.listNode(); //Listing all the nodes before setting the right pointer

    rtm.setRightPointer(); //setting the right pointer

    cout << "================ AFTER SETTING RIGHT POINTER ====================" << endl;
    rtm.listNodeByLevel(); //Listing all the nodes after setting the right pointer

    return 0;
}
