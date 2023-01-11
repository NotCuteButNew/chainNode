#include <iostream>
#include "chainNode.hpp"
#include "chainList.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        student s;
        chainList<student> list;
        int *scores = new int[argc];
        for (int i = 1; i < argc; i += 2)
        {
            scores[i/2] = std::stoi(argv[i + 1]);
        }
        for (int i = 1; i < argc; i += 2)
        {
            s.name = argv[i];
            s.score = scores[i / 2];
            list.push_back(s);
        }
        std::cout << list;
    }
    return 0;
}
