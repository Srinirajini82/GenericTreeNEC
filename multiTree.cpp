#include <iostream>
#include <cstddef>
#include <vector>
#include "multiTree.h"

using namespace std;

namespace multiTree
{
    int32_t Node::Levels = 0;

    multiTree::Node::Node(int val, multiTree::Node *parent)
    {
        m_value = val;
        m_Right = NULL;
        m_parent = parent;
    }

    void multiTree::Node::addChildren(int val)
    {
        m_childeren.push_back(new Node(val, this));
    }

    int multiTree::Node::getNumberOfChilder()
    {
        return m_childeren.size();
    }

    multiTree::Node *multiTree::Node::getChilderen(int idx)
    {
        return m_childeren[idx];
    }

    int multiTree::Node::getValue()
    {
        return m_value;
    }

    bool multiTree::Node::isRoot()
    {
        return m_parent == NULL ? true : false;
    }

    bool multiTree::Node::isLeaf()
    {
        return m_childeren.empty();
    }

    void multiTree::Node::setRightPointer(multiTree::Node *sib)
    {
        if (m_childeren.size() > 0)
        {
            for (int i = 0; i < (m_childeren.size() - 1); i++)
            {
                m_childeren[i]->m_Right = m_childeren[i + 1];
            }
            if ((sib != 0) && sib->m_childeren.size() > 0)
            {
                sib->m_childeren[sib->m_childeren.size() - 1]->m_Right = m_childeren[0];
            }

            for (int i = 0; i < m_childeren.size(); i++)
            {
                // multiTree::Node cousSibl = getSiblingWithChildren(i == 0 ? NULL : m_childeren[i - 1]);
                m_childeren[i]->setRightPointer(getSiblingWithChildren(i == 0 ? NULL : m_childeren[i]));
            }
        }
    }

    multiTree::Node *multiTree::Node::getSiblingWithChildren(multiTree::Node *sibling)
    {
        if (!sibling)
            return NULL;
        if (sibling->m_parent->m_childeren.size() == 1)
            return NULL;

        multiTree::Node *prt = sibling->m_parent;
        multiTree::Node *chldWithChild = prt->m_childeren[0];
        multiTree::Node *tmp = chldWithChild;
        for (int i = 0; i < sibling->m_parent->m_childeren.size(); i++)
        {
            if ((tmp != sibling) && (tmp->m_childeren.size()))
                chldWithChild = tmp;
            if (tmp == sibling)
                break;
            else
                tmp = prt->m_childeren[i];
        }
        return chldWithChild;
    }

    void multiTree::Node::listNode()
    {
        if (isRoot())
            cout << "value : " << this->m_value << endl;
        if (isLeaf())
            return; // No descendants for Root node and hence level of the tree is 0

        for (int i = 0; i < m_childeren.size(); i++)
        {
            multiTree::Node *tmp = m_childeren[i];
            cout << "value : " << tmp->m_value << endl;
            tmp->listNode();
        }
    }

    void multiTree::Node::listNodeByLevel()
    {
        if (isRoot())
        {
            cout << this->m_value << " " << endl;
            multiTree::Node::Levels++;
        }

        if (m_childeren.size() > 0)
            multiTree::Node::Levels++;

        if (m_childeren.empty())
            return;
        multiTree::Node *tmp = m_childeren[0];
        while (tmp)
        {
            cout << tmp->m_value << " ";
            tmp = tmp->m_Right;
        }

        cout << endl;
        m_childeren[0]->listNodeByLevel();
    }

    int multiTree::Node::getTotalLevels()
    {
        return multiTree::Node::Levels;
    }
}
