/* - vector<int> v; ==> there are no push_front memeber function for vector, i.e. no v.push_front()
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0) result.push_back(0);
        else if (n == 1) {
            result.insert(result.begin(), 0), result.push_back(1);
        }
        if (n <= 1) return result;
        vector<int> codes = grayCode(n - 1);
        for (int i = 0; i < codes.size(); i++)
            result.push_back(codes[i]);
        for (int i = codes.size() - 1; i >= 0; i--)
            result.push_back(codes[i] + (1 << (n -1)));
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> codes = solution.grayCode(2);
    for (int i = 0; i < codes.size(); i++) cout << codes[i] << " ";
    cout << endl;
    return 0;
}
