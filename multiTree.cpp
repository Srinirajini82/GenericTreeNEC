#include <iostream>
#include <cstddef>
#include <vector>
#include "multiTree.h"

using namespace std;

namespace multiTree{
    int32_t Node::Levels = 0;

    multiTree::Node::Node(int val,  multiTree::Node *parent){
        m_value = val;
        m_Right = NULL;
        m_parent = parent;
    }

    void multiTree::Node::addChildren(int val){
        m_childeren.push_back(new Node(val, this));
    }

    int multiTree::Node::getNumberOfChilder(){
        return m_childeren.size();
    }

    multiTree::Node* multiTree::Node::getChilderen(int idx){
            return m_childeren[idx];
    }

    int multiTree::Node::getValue(){
        return m_value;
    }

    bool multiTree::Node::isRoot(){
        return m_parent == NULL ? true : false;
    }

    bool multiTree::Node::isLeaf(){
        return m_childeren.empty();
    }

    void multiTree::Node::setRightPointer(){
        if(m_childeren.size() > 0){
            for(int i = 0; i < m_childeren.size(); i++){
                m_childeren[i]->m_Right = m_childeren[i+1];
            }
            for(int i = 0; i < m_childeren.size(); i++)
                m_childeren[i]->setRightPointer();
        }
    }

    void multiTree::Node::listNode(){
        if(isLeaf()) return; // No descendants for Root node and hence level of the tree is 0

        if(m_childeren.size() > 0) 
            multiTree::Node::Levels++;

        for(int i =0; i < m_childeren.size(); i++){
            multiTree::Node* tmp = m_childeren[i];
            cout << "value : " << tmp->m_value << endl;
            tmp->listNode();
        }
    }

    void multiTree::Node::listNodeByLevel(){
        if(m_childeren.empty()) return;
        multiTree::Node * tmp = m_childeren[0];
        while(tmp){
            cout << tmp->m_value << " ";
            tmp = tmp->m_Right;
        }

        cout << endl;
        for(int i = 0; i < m_childeren.size(); i++){
            if(m_childeren[i]->m_parent != m_parent)
                m_childeren[i]->listNodeByLevel();
        }
    }
}
