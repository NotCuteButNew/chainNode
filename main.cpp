#include <iostream>
#include "chainNode.hpp"
#include "chainList.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        student s;
        chainList<student> list;
        for (int i = 1; i < argc; i += 2)
        {
            s.name = argv[i];
            s.score = std::stoi(argv[i + 1]);
            list.push_back(s);
        }
        std::cout << list;
        s.name = "abc";
        s.score = 2;
        list.insert(1, s);
        std::cout << list;
    }
    return 0;
}
