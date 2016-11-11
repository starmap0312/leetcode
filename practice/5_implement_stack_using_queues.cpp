/* - implement stack using two queues:
 *   use an extra queue to simulate push element to the front of the (active) queue
 *   ex.
 *   1) push to the inactive queue
 *     (1)                        ==> active queue
 *     (2) <- push                ==> inactive queue
 *
 *   2) pop and append all active queue's elements to the back of the inactive queue, make inactive queue active
 *     ( ) ------                 ==> inactive queue
 *     (2)(1) <-| append          ==> active queue
 *
 *   the above two steps simulate pushing element to the front of the active queue
 *   ex.
 *     (3) <- push                ==> inactive queue
 *     (2  1)                     ==> active queue
 *
 *     (3)(2  1) <-| append       ==> active queue
 *     ( ) ---------              ==> inactive queue
 * - time
 *     push():       O(n) time per operation
 *     pop()/peek(): O(1) time
 */
#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    Stack() : active(0) { }
    // Push element x onto stack.
    void push(int x) {
        int inactive = abs(1 - active);
        q[inactive].push(x);
        while (!q[active].empty()) {
            q[inactive].push(q[active].front());
            q[active].pop();
        }
        active = abs(1 - active);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!q[active].empty()) {
            q[active].pop();
        }
    }

    // Get the top element.
    int top() {
        if (!q[active].empty()) {
            return q[active].front();
        }
        return 0;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[active].empty();
    }

private:
    queue<int> q[2];
    int active;
};

int main() {
    Stack s;
    s.push(1), s.push(2), s.push(3);
    cout << s.top() << endl;
    s.pop();
    s.push(4);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
