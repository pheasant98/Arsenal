#ifndef DPTR_H
#define DPTR_H
template <class T>
class DPtr
{
private:
    T* dp;
public:
    DPtr(T* =nullptr);
    DPtr(const DPtr&);
    DPtr& operator=(const DPtr&);
    T* operator->() const;
    T& operator*() const;
    ~DPtr();
};

template <class T>
DPtr<T>::DPtr(T* p): dp(p!=nullptr?p->clone():nullptr){}

template <class T>
DPtr<T>::DPtr(const DPtr & p): dp(p.dp!=nullptr?(p.dp)->clone():nullptr){}

template<class T>
DPtr<T>& DPtr<T>::operator=(const DPtr& p)
{
    if(this!=&p)
    {
        if(dp)
        {
            delete dp;
        }
        dp=(p.dp)->clone();
    }
    return *this;
}

template<class T>
T& DPtr<T>::operator*() const{
    return *dp;
}

template<class T>
T* DPtr<T>::operator->() const{
    return dp;
}

template<class T>
DPtr<T>::~DPtr()
{
    if(dp)
    {
        delete dp;
    }
}
#endif // DPTR_H
