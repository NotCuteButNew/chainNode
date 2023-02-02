#ifndef chainList_hpp
#define chainList_hpp

#include "chainNode.hpp"
#include <ostream>

template <class T>
class chainList
{
private:
    int size;
    chainNode<T> *headNode;

public:
    chainList();
    ~chainList();
    bool empty();
    int get_size() const;
    void push_back(T &theElement);
    void insert(int theIndex, T &theElement);
    void erase(int theIndex);
    void output(std::ostream &out);
};

template <class T>
chainList<T>::chainList()
{
    headNode = nullptr;
    size = 0;
}

template <class T>
chainList<T>::~chainList()
{
    chainNode<T> *preNode = headNode;
    while (preNode != nullptr)
    {
        preNode = headNode;
        headNode = headNode->next;
        delete preNode;
    }
}

template <class T>
bool chainList<T>::empty()
{
    if (headNode != nullptr)
        return false;
    else
        return true;
}

template <class T>
int chainList<T>::get_size() const
{
    return size;
}

template <class T>
void chainList<T>::push_back(T &theElement)
{
    if (headNode == nullptr)
        headNode = new chainNode<T>(theElement);
    chainNode<T> *tailNode = headNode;
    while (tailNode->next != nullptr)
    {
        tailNode = tailNode->next;
    }
    tailNode->next = new chainNode<T>(theElement);
    size++;
}

template <class T>
void chainList<T>::insert(int theIndex, T &theElement)
{
    if (theIndex < 1 || theIndex > size)
        throw "The theIndex must be between the 0 and size";
    else
    {
        chainNode<T> *preNode = headNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            preNode = preNode->next;
        }
        chainNode<T> *newNode = new chainNode<T>(theElement, preNode->next);
        preNode->next = newNode;
        size++;
    }
}

template <class T>
void chainList<T>::erase(int theIndex)
{
    if (theIndex < 1 || theIndex > size)
        throw "The theIndex must be between the 0 and size";
    else
    {
        chainNode<T> *preNode = headNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            preNode = preNode->next;
        }
        chainNode<T> *targetNode = preNode;
        preNode->next = targetNode->next;
        delete targetNode;
        size--;
    }
}

template <class T>
void chainList<T>::output(std::ostream &out)
{
    chainNode<T> *ptr = headNode->next;
    while (ptr != nullptr)
    {
        out << ptr->element << std::endl;
        ptr = ptr->next;
    }
}

template <class T>
std::ostream &operator<<(std::ostream &out, chainList<T> &x)
{
    x.output(out);
    return out;
}

#endif