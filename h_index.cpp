/* - vecotr<int> v; ==> sort(v.begin(), v.end(), greater<int>()); ==> sort in descending order
 * - the problem can be solved via sorting
 *   ex. 3  0  6  1  5  ==> input array
 *       6  5 (3) 1  0  ==> sorted array (descending)
 *       >  >  >  <  <  ==> comparison
 *       1  2 (3) 4  5  ==> h values
 *   return the h-index as 3
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (; h < citations.size() && (citations[h] >= h + 1); h++) { }
        return h;
    }
};

int main() {
    int a[] = { 3, 0, 6, 1, 5 };
    vector<int> citations(a, a + 5);
    Solution solution;
    cout << solution.hIndex(citations) << endl;
    return 0;
}
