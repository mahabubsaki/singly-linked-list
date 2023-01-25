#include <bits/stdc++.h>
using namespace std;
// a node class which have two property . one is the data in node and another is a node pointer value which will point to the next node
class node
{
public:
    int data;
    node *next;
};

class LinkedList
{
public:
    node *head;
    int size;
    // initially pointing head to null
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    // creates a new node and returns a node pointer whichs value is the given integar to the function and temporarily pointing next node as null
    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
    int IfIndexAvailable(int index)
    {
        node *current = head;
        int countIndex = 0;
        while (current != NULL)
        {
            current = current->next;
            countIndex++;
        }
        if (countIndex == index)
        {
            return -1;
        }
        else if (countIndex > index)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void InsertAtHead(int value)
    {
        // while inserting a new node to the head we are creating a node pointer with function
        node *newNode = CreateNewNode(value);
        size++;
        // if head equal null so we can say that the linkedlist is empty that's why we are pointing the head to the newly created node and returning from the function
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        // if head is not null then we can say that the list have some items. if we insert a node to the list than we can say that the newly created nodes next will be currently available head. and the head will be the new node.
        newNode->next = head;
        head = newNode;
    }
    void Traverse()
    {
        // to get all the values from the list we are creating a declaring node pointer which is equal to head
        node *current = head;
        // if head is null than we can say that list is empty
        while (current != NULL)
        {
            // if not than we are printing the data and changig the current to current elements next pointer
            cout << current->data << endl;
            current = current->next;
        }
    }
    void InsertAtLast(int value)
    {
        size++;
        node *current = head;
        node *newnode = CreateNewNode(value);
        // IF current is null than we can say the list is full empty
        if (current == NULL)
        {
            // so head will be the newnode
            head = newnode;
        }
        // else if the current's next is null than the list have two elements
        else if (current->next == NULL)
        {
            // so pointing heads next value as new node
            head->next = newnode;
        }
        else
        {
            // else list have more than two elements
            // by while loop we are checking if the currents next is null or not
            // if not null than we can say its not the ending
            while (current->next != NULL)
            {
                // so we changed current to currents next
                current = current->next;
            }
            // if its break from while loop so we can say that we have found our last element
            // then we have to change last elements next value to new node pointer
            current->next = newnode;
        }
    }
    void InsertAtPosition(int index, int value)
    {
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        else
        {
            int canIInsert = IfIndexAvailable(index);
            if (canIInsert == -1)
            {
                InsertAtLast(value);
                return;
            }
            else if (canIInsert == 0)
            {
                cout << "Index is not available" << endl;
                return;
            }
            else
            {
                size++;
                int countIndex = 1;
                node *previous = head;
                while (index > countIndex)
                {
                    previous = previous->next;
                    countIndex++;
                }
                node *next = previous->next;
                node *newnode = CreateNewNode(value);
                previous->next = newnode;
                newnode->next = next;
                return;
            }
        }
    }
    int getSize()
    {
        return size;
    }
    int getValue(int index)
    {
        node *current = head;
        int countIndex = 0;
        while (current != NULL)
        {
            if (countIndex == index)
            {
                return current->data;
            }
            current = current->next;
            countIndex++;
        }
        return -1;
    }
    void DeleteHead()
    {
        if (head == NULL)
        {
            return;
        }
        size--;
        node *current = head;
        head = current->next;
        delete current;
    }
    void DeleteLast()
    {
        if (head == NULL)
        {
            return;
        }
        size--;
        node *current = head;
        node *previos = head;
        int last_prevvious = size - 1;
        int countInedx = 0;
        if (current->next == NULL)
        {
            head = NULL;
            delete current;
            return;
        }
        while (current->next != NULL)
        {
            current = current->next;
        }
        while (countInedx != last_prevvious)
        {
            previos = previos->next;
            countInedx++;
        }
        previos->next = NULL;
        delete current;
    }
    void DeleteInIndex(int index)
    {
        if (index >= size)
        {
            return;
        }
        if (index == 0)
        {
            DeleteHead();
            return;
        }
        if (index == size - 1)
        {
            DeleteLast();
            return;
        }
        int currentIndex = 1;
        node *previos = head;
        node *current = head->next;

        while (currentIndex != index)
        {
            current = current->next;
            previos = previos->next;
            currentIndex++;
        }
        previos->next = current->next;
        size--;
        delete current;
    }
};
int main()
{
    LinkedList mylist;
    mylist.InsertAtLast(10);
    mylist.InsertAtLast(100);
    mylist.InsertAtLast(130);
    mylist.InsertAtLast(103);
    mylist.InsertAtLast(1041);
    mylist.InsertAtLast(103123);
    cout << "Size " << mylist.getSize() << endl;
    mylist.Traverse();

    mylist.DeleteInIndex(3);
    cout << "Size " << mylist.getSize() << endl;
    mylist.DeleteInIndex(3);
    cout << "Size " << mylist.getSize() << endl;
    mylist.DeleteInIndex(3);
    cout << "Size " << mylist.getSize() << endl;
    mylist.DeleteInIndex(0);
    cout << "Size " << mylist.getSize() << endl;
    mylist.DeleteInIndex(1);
    cout << "Size " << mylist.getSize() << endl;
    mylist.Traverse();
    // mylist.SearchDistinctValue(10);
    // mylist.SearchDistinctValue(5);
    // mylist.SearchAll(30);
    return 0;
}