/* - 2 types of callbacks:
 #   different in how they control data flow at run-time
 *   a) synchronous callbacks:
 *      i.e. blocking callbacks (invoke immediately, before a function returns)
 *   b) asynchronous callbacks: 
 *      i.e. deferred callbacks (invoke at later time, sometimes after a function returns)
 *      ex. I/O operations and event handling (called by interrupts or multiple threads)
 *          in windows, the application supplies a reference to a specific custom callback funtion
 *          for the operating system to call (ex. in response to mouse clicks or key presses)
 */
#include <iostream>

using namespace std;

typedef void (*CALLBACK) (int);

class MyClass {
    // a class with a callback function pointer and provides a setter method for the callback
    // function and a template method that uses the passed-in callback function

public:
    MyClass() : funcPtr(NULL) { }
    void setCallback(CALLBACK fp) { funcPtr = fp; }
    void run() {
        // a template method that uses the callback function
        if (funcPtr != NULL) (*funcPtr)(0);
    }

private:
    CALLBACK funcPtr;
};

void func(int i) {
    cout << "user-defined callback function: " << i << endl;
}

int main() {
    MyClass myClass;
    myClass.setCallback(func);
    myClass.run(); // synchronous callback: invoke immediately and wait for the execution
    return 0;
}
