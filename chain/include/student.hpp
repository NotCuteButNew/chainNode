#ifndef student_hpp
#define student_hpp

#include <string>
#include <ostream>

struct student
{
    std::string name;
    int score;
};

std::ostream &operator<<(std::ostream& out, const student &x)
{
    out << x.name << " " << x.score << std::endl;
    return out;
}
#endif
