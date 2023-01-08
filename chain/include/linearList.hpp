#ifndef linearList_hpp
#define linearList_hpp

template <class T>
class linearList
{
private:
    int size;

public:
    virtual ~linearList();
    virtual bool empty() const = 0;
    virtual int get_size() const = 0;
    virtual void inser() = 0;
    virtual void erase() = 0;
};

#endif