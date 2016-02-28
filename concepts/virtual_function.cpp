/* - overload function: early binding/static binding, which function to call is 
 *   determined at compile time
 * - override function: function is re-defined in derived classes
 * - virtual function: late binding/dynamic binding, which function to call is
 *   determined at run time
 * - a class with virtual functions is called a polymorphic class, as it embodies
 *   polymorphism, i.e. you can use a Base pointer/reference that points to a
 *   Derived instance to invokes the Derived instance's function at run time
 * - when a base pointer points to a derived object, using the base pointer to invoke
 *   a virtual function the program knows which function to call only at run time
 *   i.e. invokes the derived class's implementation of the virtual function, not
 *   the base class's implementation
 *   on the other hand, if the function is not declared as virtual, the program
 *   invokes the base class's implementation
 * - pure virtual function: a virtual function without implementation in base class
 *   therefore, the base class is an abstract class and cannot be instantiated
 *   moreover, the pure virtual function must be implemented in the derived classes
 *   disobeying the above two rules will lead to compile error
 */
#include <iostream>

using namespace std;

class Base {
public:
    void show() {
        cout << "    Base's show" << endl;
    }
    virtual void virtual_show() {
        cout << "    Base's virtual show" << endl;
    }
    virtual void pure_virtual_show() = 0;
};

class Derived : public Base {
public:
    void show() {
        cout << "    Derived's show" << endl;
    }
    virtual void virtual_show() {
        cout << "    Derived's virtual show" << endl;
    }
    virtual void pure_virtual_show() {
        cout << "    Derived's pure virtual show" << endl;
    }
};

void callByReference(Base &base) {
    base.show();
    base.virtual_show();
    base.pure_virtual_show();
}

int main() {
    Derived derived;
    cout << "Call by instance of Derived class" << endl;
    derived.show(); derived.virtual_show(); derived.pure_virtual_show();
    Base *ptr = &derived;
    cout << "Call by pointer of Base class" << endl;
    ptr -> show(); ptr -> virtual_show(); ptr -> pure_virtual_show();
    cout << "Call by reference of Base class" << endl;
    callByReference(derived);
    return 0;
}
