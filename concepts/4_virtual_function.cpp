/* virtual method enables polymorphism
 *   when use a Base class reference to call a virtual method, the concrete implementation of the method will be called
 * - override method: function is re-defined in derived classes
 * 1) normal method:
 *    early binding/static binding: which function to be called is determined at compile time
 *    i.e. if the function is not declared as virtual, the program invokes the base class's implementation
 * 2) virtual method:
 *    late binding/dynamic binding, which function to call is determined at run time
 *    (a class with virtual functions is called a polymorphic class, as it embodies polymorphism)
 *    i.e. you can use a Base pointer/reference that points to a Derived instance to invokes the Derived implementation at run time
 * 3) pure virtual method:
 *    i)  no implementation in base class, i.e. the base class is an abstract class and cannot be instantiated
 *    ii) the pure virtual function must be implemented in the derived classes
 *    (disobeying the above two rules will lead to compile error)
 */
#include <iostream>

using namespace std;

class Base {
public:
    void show() {                         // without virtual keyword, base class implementation is called when using Base class reference
        cout << "    Base's show" << endl;
    }
    virtual void virtual_show() {         // virtual method: concrete implementation in subclass is called when using Base class reference 
        cout << "    Base's virtual show" << endl;
    }
    virtual void pure_virtual_show() = 0; // pure virtual method: the class is an abstract class
};

class Derived : public Base {
public:
    void show() {
        cout << "    Derived's show" << endl;
    }
    virtual void virtual_show() {         // a concrete implementation of virtual method
        cout << "    Derived's virtual show" << endl;
    }
    virtual void pure_virtual_show() {    // a concrete implementation of pure virtual method
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
    cout << "Call by reference of Base class" << endl;
    Base &base = derived;
    base.show(); base.virtual_show(); base.pure_virtual_show();
    cout << "Call by reference in method" << endl;
    callByReference(derived);
    return 0;
}
