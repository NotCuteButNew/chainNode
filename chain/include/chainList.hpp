﻿#ifndef chainList_hpp
#define chainList_hpp

#include "linearList.hpp"
#include "chainNode.hpp"

template <class T>
class chainList : public linearList
{
private:
    int size;
    chainNode<T> firstNode;

public:
    chainList();
    ~chainList();
    bool empty() const;
    void insert(int theIndex, T &theElement);
    void erase(int theIndex);
    void push_back(T &theElement);
    void output(std::ostream out) const;
};

template <class T>
chainList<T>::chainList()
{
    firstNode->next = nullptr;
    int size = 1;
}

template <class T>
chainList<T>::~chainList()
{
}

template <class T>
bool chainList<T>::empty() const
{
    if (firstNode->next == nullptr)
        return true;
    else
        return false;
}

template <class T>
void chainList<T>::insert(int theIndex, T &theElement)
{
    if (theIndex < 0 || theIndex > size)
        throw "chainList::insert::theIndex must be between 0 and chaiList::size";
    else
    {
        chainNode<T> *pre = firstNode;
        for (int i = 0; !(i > theIndex); i++)
        {
            pre = pre->next;
        }
        chainNode<T> *newNode = new chainNode<T>(theElement, pre->next);
        pre->next = newNode;
        size++;
    }
}

template <class T>
void chainList<T>::erase(int theIndex)
{
    if (theIndex < 0 || theIndex > size)
        throw "chainList::insert::theIndex must be between 0 and chaiList::size";
    else
    {
        chainNode<T> *pre = firstNode;
        for (int i = 0; !(i > theIndex); i++)
        {
            pre = pre->next;
        }
        chainNode<T> *targetNode = *pre->next;
        pre->next = targetNode->next;
        delete[] targetNode;
        size--;
    }
}

template <class T>
void chainList<T>::push_back(T &theElement)
{
    chainNode<T> *tailNode = firstNode;
    while (tailNode->next != nullptr)
    {
        tailNode = tailNode->next;
    }
    chainNode<T> *newNode = new chainNode<T>(theElement);
    tailNode->next = newNode;
    tailNode = tailNode->next;
    size++;
}

template <class T>
void chainList<T>::output(std::ostream out) const
{
    chainNode<T> *currentNode = firstNode->next;
    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
        out << currentNode->element << std::endl;
    }
}

template <class T>
std::ostream operator<<(std::ostream out, const chainList<T> &x)
{
    x.output(out);
    return out;
}

#endif
