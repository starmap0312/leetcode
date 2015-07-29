#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            if(isOperator(tokens[i])) {
                int n1 = nums.top(); nums.pop();
                int n2 = nums.top(); nums.pop();
                nums.push(Operate(n2, n1, tokens[i]));
            } else {
                nums.push(atoi(tokens[i].c_str()));
            }
        }
        return nums.top();
    }

    int Operate(int n1, int n2, string &oper) {
        if (oper == "+") return n1 + n2;
        else if (oper == "-") return n1 - n2;
        else if (oper == "*") return n1 * n2;
        else return n1 / n2;
    }

    bool isOperator(const string &s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        return false;
    }
private:
    stack<int> nums;
};

int main() {
    vector<string> tokens;
    tokens.push_back("0"); 
    tokens.push_back("3"); 
    tokens.push_back("/");
    Solution solution;
    cout << solution.evalRPN(tokens) << endl;
    return 0;
}
