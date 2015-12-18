/* - time of the previous approach can be further improved by scanning the input string from
 *   left to right only once, provided that the hashmap of the occurrences of each symbol is
 *   given in advance
 * - this approach utilizes a stack and is not that straightforward at first glance
 *   a symbol in the stack may be popped out by a later symbol with smaller lexicographical order
 *   if there are still occurrences of that symbol in the suffix string
 *   ex.  c  b  a  c  d  c  b  c  ==> input string
 *        -                           mp['a'] = 1, mp['b'] = 2, mp['c'] = 4, mp['d'] = 1
 *                                    stack: []               (empty)
 *        c  b  a  c  d  c  b  c
 *           -                        mp['a'] = 1, mp['b'] = 2, mp['c'] = 3, mp['d'] = 1
 *                                    stack: ['c']            (push 'c')
 *        c  b  a  c  d  c  b  c
 *              -                     mp['a'] = 1, mp['b'] = 1, mp['c'] = 3, mp['d'] = 1
 *                                    stack: ['a']            (pop 'c' and push 'a')
 *        c  b  a  c  d  c  b  c
 *                 -                  mp['a'] = 0, mp['b'] = 1, mp['c'] = 3, mp['d'] = 1
 *                                    stack: ['a', 'c']       (push 'c')
 *        c  b  a  c  d  c  b  c
 *                    -               mp['a'] = 0, mp['b'] = 1, mp['c'] = 2, mp['d'] = 1
 *                                    stack: ['a', 'c', 'd']  (push 'd')
 *        c  b  a  c  d  c  b  c
 *                       -            mp['a'] = 0, mp['b'] = 1, mp['c'] = 2, mp['d'] = 0
 *                                    stack: ['a', 'c', 'd']  ('c' already in stack and is skipped)
 *        c  b  a  c  d  c  b  c
 *                          -         mp['a'] = 0, mp['b'] = 1, mp['c'] = 1, mp['d'] = 0
 *                                    stack: ['a', 'c', 'd', 'b']  (push 'b')
 *        c  b  a  c  d  c  b  c
 *                             -      mp['a'] = 0, mp['b'] = 0, mp['c'] = 1, mp['d'] = 0
 *                                    stack: ['a', 'c', 'd', 'b']  ('c' is skipped)
 *        c  b  a  c  d  c  b  c
 *                                -   mp['a'] = 0, mp['b'] = 0, mp['c'] = 0, mp['d'] = 0
 *                                    stack: ['a', 'c', 'd', 'b']  (finished)
 *   output the symbols in the stack as the answer: i.e. "acdb"
 * - the time of the above approach is O(n)
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }
        unordered_set<char> instack;
        stack<char> q;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]--;
            if (instack.find(s[i]) != instack.end()) continue;
            while (!q.empty() && s[i] < q.top() && count[q.top()] > 0) {
                instack.erase(q.top());
                q.pop();
            }
            q.push(s[i]);
            instack.insert(s[i]);
        }
        while (!q.empty()) {
            result = q.top() + result;
            q.pop();
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.removeDuplicateLetters("bcabc") << endl;
    cout << solution.removeDuplicateLetters("cbacdcbc") << endl;
    return 0;
}
