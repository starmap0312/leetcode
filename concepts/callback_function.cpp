/* - two types of callbacks:
 *   different in how they control data flow at run-time
 *   a) synchronous callbacks: (i.e. blocking callbacks)
 *      invoke immediately, before a function returns
 *      i.e. while the API receives the callback, it remains on the stack
 *      ex. list.foreach(callback);
 *          when foreach() returns, the callback has been invoked on each element
 *   b) asynchronous callbacks: (i.e. deferred callbacks) 
 *      invoke at later time, after a function returns
 *      i.e. the callback is on another thread's stack
 *      ex. socket.connect(callback); // I/O related APIs
 *          when connect() returns, the callback may not have been called, since
 *          it is waiting for the connection to complete 
 *      ex. I/O operations and event handling, called by interrupts or multiple threads
 *      ex. in windows, an application may supply a reference to a specific custom
 *          callback funtion for the operating system to call, in response to mouse
 *          clicks or key presses)
 * - an async callback should be invoked by a main loop or central dispatch mechanism
 *   directly, i.e. there should not be unnecessary frames on the callback-invoking
 *   thread's stack, especially if those frames might hold locks
 */
#include <iostream>

using namespace std;

typedef void (*CALLBACK) (int);

class MyClass {
    // a class with a callback function pointer
    // the class provides a setter method to register any callback function and 
    // provides a template method to use the callback function

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
    cout << "a user-defined callback function: " << i << endl;
}

int main() {
    MyClass myClass;
    myClass.setCallback(func);
    myClass.run(); // synchronous callback: invoke immediately and wait for the execution
    return 0;
}
