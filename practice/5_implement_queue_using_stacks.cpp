/* - implement queue using two stacks:
 *   1) push elements to push_stack
 *   2) pop elements from pop_stack, and if pop_stack is empty, push all elements in push_stack to pop_stack
 *   ex.
 *       (1 2)              <== push_stack
 *       ( )   --> pop      <== pop_stack
 *       
 *       ( )                <== push_stack
 *       (2 1) --> pop 1    <== pop_stack
 *
 *       ( )                <== push_stack
 *       (2)   --> pop 2    <== pop_stack
 *
 * - time
 *     push():       O(1) time
 *     pop()/peek(): amortized O(1) time per operation
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
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        pop_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        return pop_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pop_stack.empty() && push_stack.empty();        
    }

private:
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
