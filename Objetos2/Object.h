#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class Object{
    virtual void Print(ostream & os) = 0;
    virtual Object * clone () = 0;

};
#endif // OBJECT_H_INCLUDED
