#ifndef student_hpp
#define student_hpp

#include <string>
#include <ostream>

struct student
{
    std::string name;
    int score;
    operator int() const
    {
        return score;
    }
};

std::ostream &operator<<(std::ostream &out, student &x)
{
    out << x.name << "\t" << x.score;
    return out;
}
#endif