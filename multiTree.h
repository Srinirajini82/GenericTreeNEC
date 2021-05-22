#include <cstddef>
#include <vector>

using namespace std;

namespace multiTree{
    class Node{
        public:
            Node(int val, multiTree::Node *parent=NULL);
            void addChildren(int);
            int getNumberOfChilder();
            multiTree::Node* getChilderen(int idx);
            int getValue();
            bool isRoot();
            bool isLeaf();
            void listNode();
            int getLevels();
            void setRightPointer();
            void listNodeByLevel();

        
            vector<multiTree::Node *> m_childeren;
            Node *m_Right;
            Node *m_parent;
            int m_value;
            static int Levels;
    };
}
