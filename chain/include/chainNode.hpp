#ifndef CHAINNODE_HPP
#define CHAINNODE_HPP

#include "student.hpp"

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

    /*     chainNode_back(const T &theElement, chainNode<T> *next)
        {
            element = theElement;
            next->next = this;
            this = this->next;
        } */
};

#endif