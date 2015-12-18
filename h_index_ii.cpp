/* - since the input array is already sorted, the problem can be solved similarly to binary search
 *   search for the largest index i such that citations[i] >= citations.size() - i
 *   ex.  0  1  2  3  4  ==> index 
 *        0  1  2  5  6  ==> citations[0...4]: the input array
 *        <  <  <  >  >  ==> comparison with h values
 *        5  4  3 (2) 1  ==> h values
 * - the time required is O(log n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int i = 0, j = citations.size();
        while (i < j) {
            int mid = (i + j) / 2;
            if (citations[mid] < citations.size() - mid)
                i = mid + 1;
            else
                j = mid;
        }
        return (citations.size() - i);
    }
};

int main() {
    int a[] = { 0, 1, 2, 5, 6 };
    vector<int> citations(a, a + 5);
    Solution solution;
    cout << solution.hIndex(citations) << endl;
    return 0;
}
