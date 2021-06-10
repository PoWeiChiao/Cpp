template<class T>
class Vector 
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;

private:
    iterator _start;
    iterator _finish;
    iterator _endOfStorage;
};

