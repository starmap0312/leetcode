/* - implement stack using two queues: tracking the top number whenever push a value into 
 *   the stack; when calling pop() method, move all elements (except the lastest one) of 
 *   the active queue to the second queue, update the top number accordingly, and re-assign the
 *   second queue as the active queue
 * - a pop() operation costs O(n) time
 */
#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q[index].push(x);
        top_num = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        while (!q[index].empty()) {
            int num = q[index].front();
            q[index].pop();
            if(!q[index].empty()) {
                q[abs(1 - index)].push(num);
                top_num = num;
            }
        }
        index = abs(1 - index);
    }

    // Get the top element.
    int top() {
        return top_num;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[index].empty();
    }
    Stack() : index(0), top_num(0) { }
private:
    queue<int> q[2];
    int index, top_num;
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
