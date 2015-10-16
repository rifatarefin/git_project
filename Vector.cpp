#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Element {
private:
    int value;
public:
    void setValue(int v) {
        value = v;
    }
    int getValue() {
        return value;
    }
};

class VectorBase {
private:
    int capacity;
protected:
    int size;
    Element * elements;
public:
    VectorBase() {
        capacity = 100;
        elements = new Element[capacity];
        size = 0;

    }
    int getSize() {
        return size;
    }
    int getCapacity() {
        return capacity;
    }
    ~VectorBase() {
        delete elements;
    }
};

class Vector: public VectorBase {
public:
    void add (Element e);
    void add(int index, Element element);
    int capacity();
    void clear();
    bool contains(Element e);
    Element elementAt(int index);
    Element firstElement();
    Element get(int index);
    int indexOf(Element e);
    void insertElementAt(Element obj, int index);
    bool isEmpty();
    Element lastElement();
    int lastIndexOf(Element o);
    Element remove(int index);
    bool remove(Element o);
    void removeAllElements();
    void removeElementAt(int index);
    Element set(int index, Element element);
    //int size();
    string toString();
};


void Vector::add(Element e)
{
    if(size<getCapacity ())this->elements[size++].setValue (e.getValue ());

}

void Vector::add(int index, Element element)
{
    if(index>=0&&index<=size && size<getCapacity ())
    {
        for(int i=size;i>index;i--)elements[i].setValue (elements[i-1].getValue ());

        this->elements[index].setValue (element.getValue ());
        size++;
    }
}

int Vector::capacity()
{
    return getCapacity ();
}

void Vector::clear()
{
    delete elements;
    size=0;
}

bool Vector::contains(Element e)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(elements[i].getValue ()==e.getValue ())return true;
    }
    return false;
}

Element Vector::elementAt(int index)
{
    return  elements[index];
}

Element Vector::firstElement()
{
    return  elements[0];
}

Element Vector::get(int index)
{
    return elementAt (index);
}

int Vector::indexOf(Element e)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(elements[i].getValue ()==e.getValue ())return i;
    }
    return  -1;
}

void Vector::insertElementAt(Element obj, int index)
{
    add(index,obj);
}

bool Vector::isEmpty()
{
    return size==0;
}

Element Vector::lastElement()
{
    return elementAt (size-1);
}

int Vector::lastIndexOf(Element o)
{
    int i;
    for(i=size-1;i>=0;i--)
    {
        if(elements[i].getValue ()==o.getValue ())return i;
    }
    return -1;
}

Element Vector::remove(int index)
{
    if(index>=0 && index<size-1)
    {
        for(int i=index;i<size-1;i++)
        {
            elements[i].setValue (elements[i+1].getValue ());
        }
        size--;
    }

}

bool Vector::remove(Element o)
{
    int index=indexOf (o);
    if(index!=-1)
    {
        remove(index);
        return true;
    }
    return false;
}

void Vector::removeAllElements()
{
    delete elements;
    size=0;
}

void Vector::removeElementAt(int index)
{
    remove (index);
}

Element Vector::set(int index, Element element)
{
    elements[index].setValue (element.getValue ());
}

string Vector::toString()
{
    string s;
    if(size>0)
    {
        char ch[100000];
        itoa (elements[0].getValue (),ch,10);
        s=string(ch);
        for(int i=1;i<size;i++)
        {
            itoa (elements[i].getValue (),ch,10);
            s=s+", "+string(ch);
        }
        return s;
    }
    return s;

}

//int Vector::size()
//{
//    return getSize ();
//}

// a very simple main
int main() {
    Vector v;
    Element e[10];
    for(int i=0;i<10;i++)
    {
        e[i].setValue (i+11);
        v.add(e[i]);
    }

    cout<<v.toString ()<<endl;
    v.insertElementAt (e[3],8);
    v.set (8,e[9]);
    cout<<v.toString ()<<endl;
    return 0;
}

