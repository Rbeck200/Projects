
#include <iostream>
#include <stack>


using namespace std;


class LinkedList
{
public:
    int value;
    LinkedList* next;
};


class BinaryNode
{
public:
    int value = -1;
    BinaryNode* left = nullptr;

    BinaryNode* right = nullptr;

};

LinkedList* NextNode;
LinkedList* TopNode;
LinkedList* current;
LinkedList* root;
stack<LinkedList*> nodes;

LinkedList* reverseLinkedList(LinkedList* root)
{
    // Reverse Linked List
    while (current != nullptr)
    {
        nodes.push(current);
        current = current->next;

    }
    if (nodes.empty() == false)
    {
        TopNode = nodes.top();
        nodes.pop();
    }

    int i = 0;

    while (nodes.empty() == false)
    {
        current = nodes.top();
        nodes.pop();
        TopNode->next = current;

        if (i == 0)
        {
            root = TopNode;
        }
        TopNode = current;
        i++;
    }

    return root;
}



LinkedList* mergedSortedLinkedLists(LinkedList* first, LinkedList* second)
{
    LinkedList* NewList;
    LinkedList* OldList;
    int i = 0;
    while (first->next != nullptr || second->next != nullptr)
    {
        LinkedList* ListNode;

        if (first->value < second->value)
        {
            NewList->value = first->value;
            first = first->next;

        }
        if (second->value >= first->value)
        {
            NewList->value = second->value;
            second = second->next;
        }

        if (i == 0)
        {
            ListNode = NewList;
        }
        OldList->next = NewList;
        // NewList = NewList->next;
        OldList = NewList;
        i++;
    }
}
    
    bool exists_iter(BinaryNode * root, int value)
    {
        while (root->right != nullptr || root->left != nullptr)
        {
            if (root->value == value)
            {
                return true;
            }
            else
            {
                if (value < root->value)
                {
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return false;
    }

bool exists_rec(BinaryNode* root, int value)
{
    if (root->value == value)
    {
        return true;
    }
    else
    {
        if (value < root->value)
        {
            if (exists_rec(root->left, value))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (exists_rec(root->right, value))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}




int main()
{

   

}
