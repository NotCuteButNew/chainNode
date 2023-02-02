#include <iostream>
#include "chainNode.hpp"
#include "student.hpp"
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
        std::cout << "****test insert****" << std::endl;
        s.name = "D";
        s.score = 4;
        list.insert(2, s);
        std::cout << list;
    }
    return 0;
}
