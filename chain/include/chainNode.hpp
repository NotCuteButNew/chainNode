#ifndef CHAINNODE_HPP
#define CHAINNODE_HPP

template <class T>
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode(const T &theElement)
    {
        element = theElement;
        this->next = nullptr;
    }
    chainNode(const T &theElement, chainNode<T> *next)
    {
        element = theElement;
        this->next = next;
    }
};

#endif