#ifndef linearList_hpp
#define linearList_hpp

#include <ostream>
template <class T>
class linearList
{
private:
public:
    virtual ~linearList();
    virtual bool empty() const = 0;
    virtual void insert(int theIndex, T &theElement) = 0;
    virtual void erase(int theIndex) = 0;
    virtual void push_back(T &theElement) = 0;
    virtual void output(std::ostream out) const = 0;
};

#endif