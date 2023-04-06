#include <iostream>
using namespace std;

struct Impl;
typedef Impl* List;

class Timeserie
{
    public:
        Timeserie();
        //Timeserie(const Timeserie&);
        //~Timeserie();
        void add(unsigned long, long);
        void print();
        void read();
        Timeserie& operator=(const Timeserie&);
        Timeserie operator+(const Timeserie&) const;

    private:
        List pimpl;
};

struct Impl {
    unsigned long timestamp;
    long value;
    Impl* next;
    void destroy(List&);
    void append(List&, unsigned long, long);
    List copy(List&, List&);
};

Timeserie::Timeserie()
{
    pimpl = new Impl;
    pimpl = nullptr;
}

/*Timeserie::~Timeserie()
{
    pimpl->destroy(pimpl);
    delete pimpl;
}*/

void Impl::destroy(List& s)
{
    if(s)
    {
        destroy(s->next);
        delete s;
    }
    s = nullptr;
}



void Timeserie::add(unsigned long timestamp, long value){
    
    
    pimpl->append(pimpl, timestamp, value);
    
    /*Impl *l = new Impl();
    l->timestamp = timestamp;
    l->value = value;

    if(pimpl){
        if (timestamp < pimpl->timestamp){
            l->next = pimpl;
            pimpl = l;
            return;
        }
        while(pimpl->next){
            if(timestamp < pimpl->next->timestamp){
                l->next = pimpl->next;
                pimpl = l;
                return;
            }
            pimpl = pimpl->next;
        }
        pimpl->next = l;

    }
    else{
        pimpl = new Impl();
        pimpl = l; //Creo la testa
    }*/
}

/*List Impl::copy(List& source, List& dest)
{
    if(!source) dest = nullptr;
    else 
    {
        dest = new Impl {source->timestamp, source->value, nullptr};
        List s = source;
        List d = dest;
        s = s->next;
        while(s)
        {
            append(dest, s->timestamp, s->value);
            s = s->next;
            d = d->next;
        }
    }
    return dest;
}*/

void Impl::append(List& s, unsigned long timestamp, long value)
{
    if(!s)
    {
        s = new Impl {timestamp, value, nullptr}; //caso inserimento primo elemento
    }
    else 
    {
        if(timestamp < s->timestamp)
        {
            s = new Impl {timestamp, value, s}; //Caso di inserimento in testa
        }
        else
        {
            List t = s;
            while(t->next and t->timestamp < timestamp and t->next->timestamp < timestamp)
            {
                t = t->next;
            }
            t->next = new Impl {timestamp, value, t->next};
        }
    }
}
        

        /*if(timestamp < s->timestamp)
        {
            List nuova = new Impl {timestamp, value, s};
            s = nuova;
        }
        else append(s->next, timestamp, value);*/

void Timeserie::read()
{
    int elem;
    unsigned long el;
    long e;
    cin >> elem;
    for(int i = 0; i < elem; i++)
    {
        cin >> el;
        cin >> e;
        add(el, e);
    }
}

void Timeserie::print()
{
    List s = pimpl;
    while(s)
    {
        cout << "( " << s->timestamp << ", " << s->value << " )" << endl; 
        s = s->next;
    }
}

Timeserie Timeserie::operator+(const Timeserie& u) const
{
    Timeserie result;
    List s = pimpl;
    List t = u.pimpl;
    while(s or t)
    {
        if(s and !t)
        {
            result.add(s->timestamp, s->value);
            s = s->next;
        }

        else if(!s and t)
        {
            result.add(t->timestamp, t->value);
            t = t->next;
        }

        else if(s and t)
        {
            if(s->timestamp < t->timestamp)
            {
                result.add(s->timestamp, s->value);
                s = s->next;
            }
            else 
            {
                result.add(t->timestamp, t->value);
                t = t->next;
            }
        }
    }
    return result;
}

int main()
{
    Timeserie r, s;
    r.read();
    cout << endl;
    s.read();
    cout << endl;
    Timeserie a = r + s;
    a.print();
}