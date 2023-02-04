#ifndef chainList_hpp
#define chainList_hpp

#include "linearList.hpp"
#include "chainNode.hpp"
#include <ostream>

template <class T>
class chainList : public linearList<T>
{
private:
    int size;
    chainNode<T> *firstNode;
    chainNode<T> *tailNode;

public:
    chainList();
    ~chainList();
    int get_size();
    chainNode<T> &get_head();
    chainNode<T> &get_tail();
    bool empty() const;
    void insert(int theIndex, T &theElement);
    void erase(int theIndex);
    void push_back(T &theElement);
    void output(std::ostream &out) const;
    void bin_sort(int max_score);
};

template <class T>
chainList<T>::chainList()
{
    firstNode = nullptr;
    tailNode = firstNode;
    size = 0;
}

template <class T>
chainList<T>::~chainList()
{
    chainNode<T> *newHead = firstNode;
    chainNode<T> *post;
    while (newHead != nullptr)
    {
        post = newHead->next;
        newHead->next = nullptr;
        delete newHead;
        newHead = post;
    }
    delete newHead;
    delete post;
}

template <class T>
inline int chainList<T>::get_size()
{
    return size;
}

template <class T>
chainNode<T> &chainList<T>::get_head()
{
    return *firstNode;
}

template <class T>
chainNode<T> &chainList<T>::get_tail()
{
    return *tailNode;
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
        if (firstNode == nullptr)
        {
            firstNode = new chainNode<T>(theElement);
            tailNode = firstNode;
        }
        chainNode<T> *pre = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            pre = pre->next;
        }
        chainNode<T> *newNode = new chainNode<T>(theElement, pre->next);
        tailNode = tailNode->next;
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
        chainNode<T> *targetNode = pre->next;
        if (targetNode == tailNode)
            tailNode = pre;
        pre->next = targetNode->next;
        delete targetNode;
        size--;
    }
}

template <class T>
void chainList<T>::push_back(T &theElement)
{
    if (firstNode == nullptr)
    {
        firstNode = new chainNode<T>(theElement);
        tailNode = firstNode;
    }
    chainNode<T> *newNode = new chainNode<T>(theElement);
    tailNode->next = newNode;
    tailNode = tailNode->next;
    size++;
}

template <class T>
void chainList<T>::output(std::ostream &out) const
{
    chainNode<T> *currentNode = firstNode->next;
    while (currentNode != nullptr)
    {
        out << currentNode->element << std::endl;
        currentNode = currentNode->next;
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
    for (chainNode<T> *ptr = firstNode->next; ptr != tailNode && ptr != nullptr; ptr = ptr->next)
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
            top[theBin] = ptr;
        }
    }
    tailNode = firstNode;
    for (int i = 0; !(i > max_score); i++)
    {
        if (bottom[i] != nullptr)
        {
            tailNode->next = bottom[i];
            tailNode = top[i];
        }
    }
    tailNode->next = nullptr;
    delete[] top;
    delete[] bottom;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const chainList<T> &x)
{
    x.output(out);
    return out;
}

#endif
