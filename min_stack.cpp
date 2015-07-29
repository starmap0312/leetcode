/* - vector<int> v; ==> v.push_back(3), void v.pop_back(), int v.back() segmentation fault if empty
 *                      v.empty(), v.size()
 * - stack<int> s; ==> s.push(3), void s.pop(), int s.top() segmentation fault if empty
 *                      s.empty(), s.size()
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    void push(int x) {
        if (values.empty() || values[min_index.top()] > x)
            min_index.push(values.size());
        values.push_back(x); 
    }

    void pop() {
        if (!values.empty()) {
            if (values.size() - 1 == min_index.top()) min_index.pop();
            values.pop_back();
        }
    }

    int top() {
        if (!values.empty()) return values[values.size() - 1];
        else return 0;
    }

    int getMin() {
        if (!values.empty()) {
            return values[min_index.top()];
        } else return 0;
    }
private:
    vector<int> values;
    stack<int> min_index;
};

int main() {
    return 0;
}
