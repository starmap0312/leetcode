/* 
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> once, twice;
        for (int i = 0; i < nums.size(); i++) {
            set<int>::iterator itr = once.find(nums[i]);
            set<int>::iterator itr2 = twice.find(nums[i]);
            if (itr != once.end()) {
                once.erase(itr);
                twice.insert(nums[i]);
            } else if (itr2 != twice.end()) {
                twice.erase(itr2);
            } else {
                once.insert(nums[i]);
            }
        }
        return (!once.empty()? *once.begin(): *twice.begin());
    }
};

int main() {

    return 0;
}
