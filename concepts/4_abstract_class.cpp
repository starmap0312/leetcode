/* pure viritual method
 *   by defining a pure virtual method, we declare the class as an abstract class, which cannot be instantiated
 */
#include <iostream>

using namespace std;

class AbstractClass { // an abstract class with pure virtual method that cannot be instantiated
public:
    virtual void func1() {   // virtual method: with implementation
       cout << "func1 in AbstractClass" << endl;
    }
    virtual int func2() = 0; // pure virtual method (unimplemented and the class cannot be instantiated)
};

class Implementation : public AbstractClass {
public:
    void func1() {           // override func1
        cout << "func1 in Implementation" << endl;
    }

    int func2() {            // implement func2
        cout << "func2 in Implementation" << endl;
        return 0;
    }
};

int main() {
    Implementation impl;
    impl.func1();
    impl.func2();
    AbstractClass abs;
    return 0;
}
