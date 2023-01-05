#include <iostream>
#include "chainNode.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int *nums = new int[argc];
        for (int i = 1; i < argc; i++)
        {
            nums[i - 1] = std::stoi(argv[i]);
        }
        chainNode<int> *headNode = new chainNode<int>(nums[0]);
        for (int i = 1; i < argc - 1; i++)
        {
            headNode = new chainNode<int>(nums[i], headNode);
        }
        while (headNode->next != nullptr)
        {
            std::cout << headNode->element << " -> ";
            headNode = headNode->next;
        }
        std::cout << headNode->element;
    }
    return 0;
}
