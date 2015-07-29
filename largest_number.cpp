/* - vector<int> v; ==> sort(v.begin(), v.end()) and sort(v.begin(), v.end(), greater<int>()) to reverse sort
 * - permute(vector<int> selected, vector<int> remaining);
 * - void func(const vector<int> &nums); ==> makes vector nums immutable
 * - to_string(num) converts int num into string
 * - sizeof() returns number of bytes ==> sizeof(array)/sizeof(array[0]) returns number of elements of array
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums);
private:
    void permute(vector<int> &selected, vector<int> &remaining);
    string convert(const vector<int> &nums);
    int compare(const string &s1, const string &s2);
    vector<int> max_nums;
};

string Solution::largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> selected, remaining = nums;
    permute(selected, remaining);
    return convert(max_nums);
}

string Solution::convert(const vector<int> &nums) {
    string results = "";
    for(int i = 0; i < nums.size() ; i++) {
        results += to_string(nums[i]);
    }
    return results;
}

int Solution::compare(const string &s1, const string &s2) {
    for(int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
        if(s1[i] > s2[j]) return 1;
        else if(s1[i] < s2[j]) return -1;
    }
    return 0;
}

void Solution::permute(vector<int> &selected, vector<int> &remaining) {
    if(compare(convert(max_nums), convert(selected)) > 0) return;
    if(remaining.size() == 0) {
        if(max_nums.size() == 0 || compare(convert(max_nums), convert(selected)) < 0)
            max_nums = selected;
    } else {
        int prev_num = -1;
        for(vector<int>::iterator itr = remaining.begin(); itr != remaining.end() ; itr++) {
            if(*itr == prev_num) continue;
            else prev_num = *itr;
            vector<int> new_selected = selected;
            vector<int> new_remaining = remaining;
            new_selected.push_back(*itr);
            new_remaining.erase(new_remaining.begin() + (itr - remaining.begin()));
            permute(new_selected, new_remaining);
        }
    }
}

int main() {
    Solution solution;
    const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> nums(a, a + 10);
    cout << solution.largestNumber(nums) << endl;
    return 0;
}
