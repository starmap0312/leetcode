#include <iostream>

using namespace std;

class MyInterface {
public:
    virtual void func1() { // virtual function
       cout << "func1 (at interface)" << endl;
    }
    virtual int func2() = 0; // pure virtual function
};

class Implementation : public MyInterface {
public:
    void func1() {
        cout << "func1" << endl;
    }

    int func2() {
        cout << "func2" << endl;
        return 0;
    }
};

int main() {
    Implementation impl;
    impl.func1();
    impl.func2();
    return 0;
}
