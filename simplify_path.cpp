/* - string s; ==> s.find('x', 3) to find char 'c' in string s starting from index 3
 *   it returns string::npos (-1) if not found
 * - queue<int> q; ==> q.push(3) pushes 3 to back; q.pop() pops the front element (FIFO)
 *                     q.front() peeks the front element
 *                     q.empty() to check if queue is empty
 *                     queue has no iterator, i.e. (X) queue<int>::iterator
 *                     instead, use while(!q.empty()) { cout << q.front() << endl; q.pop(); } to traverse
 * - stack<int> s; ==> s.push(3) pushes 3 to top(back); s.pop() pops the top(back) element (LIFO)
 *                     s.top() peeks the top(back) element
 *                     s.empty() to check if stack is empty
 *                     stack has no iterator, i.e. (X) stack<int>::iterator
 *                     instead, use while(!s.empty()) { cout << s.top() << endl; q.pop(); } to traverse
 */
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        queue<int> separators = getSeparators(path);
        stack<string> folders = getFolders(path, separators);
        return getSimplifiedPath(folders);
    }
private:
    queue<int> getSeparators(const string &path) {
        queue<int> results;
        int found = -1;
        while (true) {
            found = path.find('/', found + 1);
            if (found != string::npos) results.push(found);
            else break;
        }
        results.push(path.size());
        return results;
    }
    stack<string> getFolders(const string &path, queue<int> &sep) {
        stack<string> results;
        int start = -1, end = -1;
        while (!sep.empty()) {
            start = sep.front();
            sep.pop();
            if (sep.empty()) break;
            else end = sep.front();
            string folder = path.substr(start + 1, end - start - 1);
            if (folder == "." || folder == "") { }
            else if (folder == ".." && !results.empty()) { results.pop(); }
            else { results.push(folder); }
        }
        return results;
    }
    string getSimplifiedPath(stack<string> &folders) {
        string results = "";
        while (!folders.empty()) {
            results = ("/" + folders.top()) + results;
            folders.pop();
        }
        return ((results != "")? results: "/");
    }
};

int main() {
    Solution solution;
    cout << solution.simplifyPath("/a/./b/../../c/") << endl;
    cout << solution.simplifyPath("/home/") << endl;
    cout << solution.simplifyPath("/../") << endl;
    cout << solution.simplifyPath("/home//foo/") << endl;
    cout << solution.simplifyPath("/...") << endl;
    cout << solution.simplifyPath("/abc/...") << endl;
    return 0;
}
