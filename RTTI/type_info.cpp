#include <typeinfo>
#include <iostream>

class B {

};

class D : public B {

};

class VirtualBase {
public:
    VirtualBase () {}
    // virtual ~VirtualBase() {std::cout<<"calling BaseDestructor"<<std::endl; }
    virtual void do_nothing() { std::cout<<"calling Base do_nothing"<<std::endl; }
};

class VirtualDerived : public VirtualBase{
    VirtualDerived () {}
    // virtual ~VirtualDerived() {}
    virtual void do_nothing() {}
};

int main () {
    // typeid(typename C) return type_info object
    // type_info object for Exception Handeling && dynamic_cast
    std::cout<<"class B typeid(B).name : "<<typeid(B).name()<<std::endl;
    std::cout<<"class D typeid(D).name : "<<typeid(D).name()<<std::endl;

    std::cout<<"class Base typeid(B).name : "<<typeid(VirtualBase).name()<<std::endl;
    std::cout<<"class Derived typeid(D).name : "<<typeid(VirtualDerived).name()<<std::endl;
    VirtualBase* p = new VirtualBase ();
    long* vptr = reinterpret_cast<long* >(p);
    long* vtavle = reinterpret_cast<long* >(p);
    std::cout<<*vptr;
    // ((void*) vptr[1])();
}