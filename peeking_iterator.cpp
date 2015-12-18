/* - virtual desctructor: when calls a virutal function from a base class pointer, the compiler
 *   will call the corresponding function in the derived class of that instance 
 *   therefore, virtual destructor is useful when you use base class pointer to manipulate the
 *   instance but the desctruction of the derived class is also important (prevent resource leak)
 *   ex. Base *ptr = new Derived();  <== creation of a derived class instance but use 
 *                                       a base pointer to manipulate the instance
 *       // do some work with the base pointer: ptr
 *       delete b;                      <== delete the derived class instance
 * - how to call a base class method?      
 *   ex. class Base {
 *       public:
 *           void func() { ... }
 *       };
 *
 *       class Derived : public Base {
 *       public:
 *           void func() {
 *               Base::func();          <== call the base class method func()
 *           }
 *       };
 * - observe that in the peek() method of the derived class, the first time you peek an element, 
 *   you must advance the base Iterator to get the next element, which is stored in a variable 
 *   nextElement, set flag peeked to be true so that the next time you peek, you do not need to 
 *   advance the base Iterator again
 *   i.e.  if (!peeked) {
 *             peeked = true;
 *             nextElement = Iterator::next();
 *         }
 *         return nextElement;
 * - observe that in the next() method of the derived class, if the peeked flag is set, you need
 *   not to advance the base Iterator, as the value of the next element is stored in nextElement
 *   moreover, the peeked flag must now be set to false, as the derived Iterator advances and
 *   the next element has not been peeked yet
 *   i.e.  if (peeked) {
 *             peeked = false;
 *             return nextElement;
 *         } else {
 *             return Iterator::next();
 *         }
 */
#include <iostream>
#include <vector>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    // virtual destructor: used when one deletes the instance through the base class pointer
    virtual ~Iterator(); 
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// there is no peek() method in base class. in the derived class we try to implement a new
// functionality, i.e. peek() method, that returns then next element without advancing the iterator
class PeekingIterator : public Iterator {
public:
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        peeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!peeked) {
            if (!Iterator::hasNext()) return 0;
            nextElement = Iterator::next();
            peeked = true;
        }
        return nextElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (peeked) {
            peeked = false;
            return nextElement;
        } else {
            if (!Iterator::hasNext())
                return 0;
            else
                return Iterator::next();
        }
    }

    bool hasNext() const {
        if (peeked) return true;
        else return Iterator::hasNext();
    }

private:
    bool peeked;
    int nextElement;
};

int main() {
    int a[] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    PeekingIterator iterator(nums);
    cout << iterator.next() << endl;
    cout << iterator.peek() << endl;
    cout << iterator.next() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    return 0;
}
