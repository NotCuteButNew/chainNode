#ifndef binsort_hpp
#define binsort_hpp

#include "chainList.hpp"

template <class T>
chainList<T> bin_sort(chainList<T> &theChain, int maxScore)
{
    chainList<T> *bin = new chainList<T>[maxScore + 1];
    chainNode<T> *currentNode = theChain.get_head()->next;
    while (currentNode != nullptr)
    {
        bin[currentNode->element].push_back(currentNode);
        currentNode = currentNode->next;
    }
    return bin;
}

#endif