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
    chainNode<T> *tailNode;

public:
    chainList();
    ~chainList();
    bool empty();
    int get_size() const;
    void push_back(T &theElement);
    void insert(int theIndex, T &theElement);
    void erase(int theIndex);
    void output(std::ostream &out);
    void bin_sort(int max_score);
};

template <class T>
chainList<T>::chainList()
{
    headNode = nullptr;
    tailNode = headNode;
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
    {
        headNode = new chainNode<T>(theElement);
        tailNode = headNode;
    }
    tailNode->next = new chainNode<T>(theElement);
    tailNode = tailNode->next;
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
        chainNode<T> *targetNode = preNode->next;
        preNode->next = targetNode->next;
        if (tailNode == targetNode)
        {
            tailNode = preNode;
            tailNode->next = nullptr;
        }
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
void chainList<T>::bin_sort(int max_score)
{
    chainNode<T> **bottom = new chainNode<T> *[max_score + 1];
    chainNode<T> **top = new chainNode<T> *[max_score + 1];
    for (int i = 0; !(i > max_score); i++)
    {
        bottom[i] = nullptr;
        top[i] = bottom[i];
    }
    for (chainNode<T> *ptr = headNode->next; ptr != tailNode->next && ptr != nullptr; ptr = ptr->next)
    {
        int theBin = int(ptr->element);
        if (bottom[theBin] == nullptr)
        {
            bottom[theBin] = ptr;
            top[theBin] = bottom[theBin];
        }
        else
        {
            top[theBin]->next = ptr;
            top[theBin] = top[theBin]->next;
        }
    }
    tailNode = headNode;
    for (int i = 0; !(i > max_score); i++)
    {
        if (bottom[i] != nullptr)
        {
            tailNode->next = bottom[i];
            tailNode = top[i];
        }
    }
    tailNode->next = nullptr;
    delete[] bottom;
    delete[] top;
}

template <class T>
std::ostream &operator<<(std::ostream &out, chainList<T> &x)
{
    x.output(out);
    return out;
}

#endif