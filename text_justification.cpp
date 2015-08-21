#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 1, length = words[0].size();
        vector<string> q;
        q.push_back(words[0]);
        while (i < words.size()) {
            if (length + words[i].size() < maxWidth) {
                length += (words[i].size() + 1);
            } else {
                int total = findTotalLength(q);
                string line = "";
                for (int i = 0; i < q.size() - 1; i++) {
                    if (q.size() == 1) line += q[i] + getSpace(maxWidth - total);
                    else {
                        line += (q[i] + getSpace((maxWidth - total)/(q.size() - 1) + 
                            (i < (maxWidth - total) % (q.size() - 1))));
                    }
                }
                line += q.back();
                result.push_back(line + getSpace(maxWidth - line.size()));
                q.clear();
                length = words[i].size();
            }
            q.push_back(words[i]);
            i++;
        }
        string line = "";
        for (int i = 0; i < q.size() - 1; i++)
            line += q[i] + " ";
        line += q.back();
        result.push_back(line + getSpace(maxWidth - line.size()));
        return result;
    }
    int findTotalLength(vector<string> &q) {
        int sum = 0;
        for (int i = 0; i < q.size(); i++)
            sum += q[i].size();
        return sum;
    }
    string getSpace(int num) {
        string result = "";
        for (int i = 0; i < num; i++)
            result += " ";
        return result;
    }
};

int main() {
    string a[] = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> words(a, a + 7);
    Solution solution;
    vector<string> result = solution.fullJustify(words, 16);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
