/* - implement queue using two stacks:
 *   1) elements are pushed to push_stack
 *   2) when calling peek() or pop(), the program checks if pop_stack is empty, if yes, pop elements of
 *      push_stack and push to pop_stack before calling the top() or pop() function of pop_stack
 */
#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        push_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (pop_stack.empty()) {
            move_elements();
        }
        if (!pop_stack.empty()) {
            pop_stack.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (pop_stack.empty()) {
            move_elements();
        }
        return (pop_stack.empty()? 0: pop_stack.top());
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (push_stack.empty() && pop_stack.empty());
    }
private:
    void move_elements() {
        while (!push_stack.empty()) {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
    }
    stack<int> push_stack, pop_stack;
};

int main() {
    Queue q;
    q.push(1), q.push(2), q.push(3);
    cout << q.peek() << endl;
    q.pop();
    q.push(4);
    while (!q.empty()) {
        cout << q.peek() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
