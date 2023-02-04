#ifndef student_hpp
#define student_hpp

#include <string>
#include <ostream>

struct student
{
    std::string name;
    int score;
    int operator!=(const student &x) const
    {
        return (score != x.score);
    }
    operator int() const
    {
        return score;
    }
};

std::ostream &operator<<(std::ostream &out, const student &x)
{
    out << x.name << " " << x.score;
    return out;
}
#endif
