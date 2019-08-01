#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>
#include <limits.h>
#include <algorithm>
using std::cout;
using std::endl;

template <class T>
class Qontainer
{
public:

private:
    unsigned int capacita;
    unsigned int dimensione;
    T* punt;
    T* copia(T*,unsigned int, unsigned int) const;
public:
    class const_iterator;
    class iterator
    {
        friend class Qontainer;
    private:
        T* puntI;
        iterator(T* =nullptr);
    public:
        iterator operator+(int) const;
        iterator operator-(int) const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        iterator& operator+=(int);
        iterator& operator-=(int);

        iterator& operator+=(const const_iterator&);
        iterator& operator-=(const const_iterator&);
        iterator operator+(const const_iterator&) const;
        iterator operator-(const const_iterator&) const;

        bool operator<(const const_iterator &) const;
        bool operator>(const const_iterator &) const;
        bool operator<=(const const_iterator &) const;
        bool operator>=(const const_iterator &) const;
        bool operator==(const const_iterator &) const;
        bool operator!=(const const_iterator &) const;

        T& operator*() const;
        T& operator[](unsigned int) const;
        T* operator->() const;
        operator void*() const;

    };
    class const_iterator
    {
        friend class Qontainer;
    private:
        const T* puntCI;
        const_iterator(const T* =nullptr);
    public:
        const_iterator(const iterator&);

        const_iterator operator+(int) const;
        const_iterator operator-(int) const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const_iterator& operator+=(int);
        const_iterator& operator-=(int);

        bool operator<(const const_iterator &) const;
        bool operator>(const const_iterator &) const;
        bool operator<=(const const_iterator &) const;
        bool operator>=(const const_iterator &) const;
        bool operator==(const const_iterator &) const;
        bool operator!=(const const_iterator &) const;

        const T& operator*() const;
        const T& operator[](unsigned) const;
        const T* operator->() const;
        operator void*() const;
    };

    Qontainer(unsigned int=1, unsigned int=0);
    Qontainer(unsigned int, const T&);

    Qontainer(const Qontainer&);
    Qontainer& operator=(const Qontainer&);
    ~Qontainer();

    unsigned int getDimensione() const;
    unsigned int getCapacita() const;
    bool vuoto() const;
    void pulisci();
    unsigned int allunga(int) const;

    void push_back(const T&);
    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

    bool operator==(const Qontainer&) const;
    bool operator<(const Qontainer&) const;
    bool operator>(const Qontainer&) const;
    bool operator<=(const Qontainer&) const;
    bool operator>=(const Qontainer&) const;

    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    iterator ricerca(const T&);
    const_iterator ricerca(const T&) const;

    void inserisci(iterator, const T&, int);
    iterator elimina(iterator);
    iterator elimina(iterator, iterator);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
};
// Qontainer
template<class T>
T* Qontainer<T>::copia(T* t,unsigned d, unsigned c) const{

    if(d<=c)
    {
        T* p= new T[c];
        for(unsigned int i=0; i<d && i<c; i++)
        {
            p[i]=t[i];
        }
        return p;
    }
    else
    {
        return nullptr;
    }

}
template <class T>
Qontainer<T>::Qontainer(unsigned int c, unsigned int d):capacita(c), dimensione(d), punt(new T[c]) {}
template <class T>
Qontainer<T>::Qontainer(unsigned int c, const T& t):capacita(c), dimensione(c), punt(new T[c]){
    for (int i=0;i<c;++i)
    {
        punt[i]=t;
    }
}
template <class T>
Qontainer<T>::Qontainer(const Qontainer<T>& q):capacita(q.capacita),dimensione(q.dimensione), punt(copia(q.punt, q.dimensione, q.capacita)){}
template <class T>
Qontainer<T>& Qontainer<T>::operator=(const Qontainer<T>& t){
    if(this!=&t)
    {
        if(punt)
        {
            delete[] punt;
        }
        punt = copia(t.punt, t.dimensione, t.capacita);
        capacita=t.capacita;
        dimensione=t.dimensione;

    }
    return *this;
}
template <class T>
Qontainer<T>::~Qontainer()
{
    if(punt) delete[] punt;
}
template <class T>
unsigned int Qontainer<T>::getDimensione() const{
    return dimensione;
}
template <class T>
unsigned int Qontainer<T>::getCapacita() const{
    return capacita;
}
template <class T>
bool Qontainer<T>::vuoto() const{
    if(dimensione==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Qontainer<T>::pulisci(){
    elimina(begin(), end());
}

template<class T>
unsigned int Qontainer<T>::allunga(int s) const
{
    return capacita*s;
}
template <class T>
void Qontainer<T>::push_back(const T& t){
    if(dimensione>=capacita)
    {
        capacita=allunga(2);
        T* aux = copia(punt, dimensione, capacita);
        if(punt)
        {
            delete[] punt;
        }
        punt=aux;
    }
    punt[dimensione++]=t;
}
template <class T>
void Qontainer<T>::pop_back(){
    if(dimensione>0)
    {
       dimensione--;
    }
}
template <class T>
T& Qontainer<T>::front(){
    return *punt;
}
template <class T>
T& Qontainer<T>::back(){
    return punt[dimensione-1];
}
template <class T>
const T& Qontainer<T>::front() const{
    return *punt;
}
template <class T>
const T& Qontainer<T>::back() const{
    return punt[dimensione-1];
}
template<class T>
bool Qontainer<T>::operator==(const Qontainer& t) const{
    bool flag=true;
    if(dimensione==t.dimensione)
    {
        for(unsigned int i=0;i<dimensione;i++)
        {
            if(punt[i]!=t.punt[i])
            {
                 flag=false;
            }
        }
    }
    else
    {
        return false;
    }
    return flag;
}
template<class T>
bool Qontainer<T>::operator<(const Qontainer& t) const{
    unsigned int min=dimensione;
    if(min>t.dimensione)
    {
        min=t.dimensione;
    }
    for(unsigned int i=0;i<min;i++)
    {
        if(punt[i]!=t.punt[i])
        {
            if(punt[i]<t.punt[i])
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
    if(dimensione<t.dimensione)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
bool Qontainer<T>::operator>(const Qontainer& t) const{
    unsigned int min=dimensione;
    if(min>t.dimensione)
    {
        min=t.dimensione;
    }
    for(unsigned int i=0;i<min;i++)
    {
        if(punt[i]!=t.punt[i])
        {
            if(punt[i]>t.punt[i])
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
    if(dimensione>t.dimensione)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
bool Qontainer<T>::operator<=(const Qontainer& t) const{
    return *this<t || *this==t;
}
template<class T>
bool Qontainer<T>::operator>=(const Qontainer& t) const{
    return *this>t || *this==t;
}
template <class T>
T& Qontainer<T>::operator[](unsigned int i){
    return punt[i];
}
template <class T>
const T& Qontainer<T>::operator[](unsigned int i) const{
    return punt[i];
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::ricerca(const T & t){
    bool flag=false;
    iterator it = begin();
    for(it;it!=end() && !flag; it++)
    {
        if(*it==t)
        {
            flag=true;
        }

    }
    if(it==end())
    {
        return iterator(0);
    }

    return it;
}
template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::ricerca(const T & t) const{
    bool flag=false;
    const_iterator cit = begin();
    for(cit;cit!=end() && !flag; cit++)
    {
        if(*cit==t)
        {
            flag=true;
        }

    }
    if(cit==end())
    {
        return const_iterator(0);
    }

    return cit;
}

template<class T>
void Qontainer<T>::inserisci(iterator it, const T & t, int n)
{
    if(dimensione+n>capacita)
    {
        while(dimensione+n>capacita)
        {
            capacita=allunga(2);
        }
        T* aux=copia(punt, dimensione, capacita);
        if(punt)
        {
            delete[] punt;
        }
        punt=aux;
    }
    else
    {
        dimensione=dimensione+n;
        T* app= new T[capacita];
        int i=0, y=0;
        iterator it1=it;
        for(it1; it1!=end(); it1++)
        {

            app[i]=*it1;
            i++;
        }
        for(it1=it; it1<it1+n; it1++)
        {
            *it1=t;
        }

        for(it1; y<i; it1++)
        {
            *it1=app[y];
            y++;
        }
    }
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::elimina(iterator pos){
    return elimina(pos, pos+1);
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::elimina(iterator it1, iterator it2)
{
    if(!dimensione)
    {
        return iterator(0);
    }
    if(it1<begin())
    {
        return elimina(begin(),it2);
    }
    if(it2>end())
    {
        return elimina(it1,end());
    }
    unsigned int i=0;
    for(iterator it=begin(); it!=it1 && it!=end(); it++)
    {
        i++;
    }
    unsigned int y=0;
    if(it1+1!=it2)
    {
        for(iterator it=begin(); it!=it2 && it!=end(); it++)
        {
            y++;
        }
    }
    else
    {
        y=i+1;
    }

    unsigned int app2=y;
    for(unsigned int app1=i; app2<dimensione; app1++)
    {
        punt[app1]=punt[app2];
        app2++;
    }
    dimensione=dimensione-(y-i);
    return it1;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::begin(){
    return iterator(punt);
}
template <class T>
typename Qontainer<T>::iterator Qontainer<T>::end(){
    return iterator(punt+dimensione);
}
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::begin() const{
    return const_iterator(punt);
}
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::end() const{
    return const_iterator(punt+dimensione);
}
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cbegin() const{
    return const_iterator(punt);
}
template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cend() const{
    return const_iterator(punt+dimensione);
}

//iterator
template<class T>
Qontainer<T>::iterator::iterator(T* p): puntI(p){}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator+(int n) const{
    return iterator(puntI+n);
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator-(int n) const{
    return iterator(puntI-n);
}

template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator++() {
   if(puntI)
   {
       puntI++;
   }
    return *this;
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++(int) {
    iterator aux=*this;
    if(puntI)
    {
        puntI++;
    }
    return aux;
}
template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator--() {
    if(puntI)
    {
        puntI--;
    }
    return *this;
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator--(int) {
    iterator aux=*this;
    if(puntI)
    {
        puntI--;
    }
    return aux;
}
template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator+=(int n) {
    if(puntI)
    {
        puntI+=n;
    }
    return*this;
}
template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator-=(int n) {
    if(puntI)
    {
       puntI-=n;
    }
    return *this;
}

template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator+(const const_iterator& cit) const{
    if(puntI)
    {
        return iterator(puntI+cit.puntCI);
    }
    return iterator(puntI);
}
template<class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator-(const const_iterator& cit) const{
    if(puntI-cit.puntCI)
    {
        return iterator(puntI-cit.puntCI);
    }
    return iterator(puntI);

}
template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator+=(const const_iterator& cit) {
    if(puntI)
    {
        puntI+=cit.puntCI+puntI;
    }
    return *this;
}
template<class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator-=(const const_iterator& cit) {
    if(puntI)
    {
        puntI-=cit.puntCI-puntI;
    }
    return *this;
}
template<class T>
bool Qontainer<T>::iterator::operator<(const const_iterator& it) const{
    return puntI<it.puntCI;
}
template<class T>
bool Qontainer<T>::iterator::operator>(const const_iterator& it) const{
    return puntI>it.puntCI;
}
template<class T>
bool Qontainer<T>::iterator::operator<=(const const_iterator& it) const{
    return puntI<=it.puntCI;
}
template<class T>
bool Qontainer<T>::iterator::operator>=(const const_iterator& it) const{
    return puntI>=it.puntCI;
}
template<class T>
bool Qontainer<T>::iterator::operator==(const const_iterator& it) const{
    return puntI==it.puntCI;
}
template<class T>
bool Qontainer<T>::iterator::operator!=(const const_iterator& it) const{
    return puntI!=it.puntCI;
}
template<class T>
T& Qontainer<T>::iterator::operator*() const {
    return *puntI;
}
template<class T>
T& Qontainer<T>::iterator::operator[](unsigned int n) const {
    return *(puntI+n);
}
template<class T>
T* Qontainer<T>::iterator::operator->() const {
    return puntI;
}
template<class T>
Qontainer<T>::iterator::operator void*() const {
    return puntI;
}
//const iterator
template<class T>
Qontainer<T>::const_iterator::const_iterator(const T* p): puntCI(p){}
template<class T>
Qontainer<T>::const_iterator::const_iterator(const iterator& it): puntCI(it.puntI){}
template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator+(int n) const{
    return const_iterator(puntCI+n);
}
template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator-(int n) const{
    return const_iterator(puntCI-n);
}
template<class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator++() {
    if(puntCI)
    {
        puntCI++;
    }
    return *this;
}
template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator++(int) {
    const_iterator aux=*this;
    if(puntCI)
    {
        puntCI++;
    }
    return aux;
}
template<class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator--() {
    if(puntCI)
    {
        puntCI--;
    }
    return *this;
}
template<class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator--(int) {
    const_iterator aux=*this;
    if(puntCI)
    {
        puntCI++;
    }
    return aux;
}
template<class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator+=(int n) {
    if(puntCI)
    {
        puntCI+=n;
    }
    return*this;
}
template<class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator-=(int n) {
    if(puntCI)
    {
        puntCI-=n;
    }
    return*this;
}
template<class T>
bool Qontainer<T>::const_iterator::operator<(const const_iterator& cit) const{
    return puntCI<cit.puntCI;
}
template<class T>
bool Qontainer<T>::const_iterator::operator>(const const_iterator& cit) const{
    return puntCI>cit.puntCI;
}
template<class T>
bool Qontainer<T>::const_iterator::operator<=(const const_iterator& cit) const{
    return puntCI<=cit.puntCI;
}
template<class T>
bool Qontainer<T>::const_iterator::operator>=(const const_iterator& cit) const{
    return puntCI>=cit.puntCI;
}
template<class T>
bool Qontainer<T>::const_iterator::operator==(const const_iterator& cit) const{
    return puntCI==cit.puntCI;
}
template<class T>
bool Qontainer<T>::const_iterator::operator!=(const const_iterator& cit) const{
    return puntCI!=cit.puntCI;
}
template<class T>
const T& Qontainer<T>::const_iterator::operator*() const {
    return *puntCI;
}
template<class T>
const T& Qontainer<T>::const_iterator::operator[](unsigned int n) const {
    return *(puntCI+n);
}
template<class T>
const T* Qontainer<T>::const_iterator::operator->() const {
    return puntCI;
}
template<class T>
Qontainer<T>::const_iterator::operator void*() const {
    return puntCI;
}

#endif // QONTAINER_H
