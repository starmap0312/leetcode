#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() : permute_string("") { }
    string getPermutation(int n, int k) {
        vector<int> rest;
        for(int i = 1; i <= n; i++) rest.push_back(i);
        downward(rest, k);
        return permute_string;
    }

    void downward(vector<int> &rest, int k) {
        if (rest.size() == 0) return;
        int denominator = factorial(rest.size() - 1);
        int index = (k - 1) / denominator;
        permute_string += to_string(rest[index]);
        rest.erase(rest.begin() + index);
        downward(rest, k - denominator * index);
    }

    int factorial(int num) {
        int result = 1;
        for(int i = 1; i <= num; i++) result *= i;
        return result;
    }

private:
    string permute_string;
};

int main() {
    Solution solution;
    cout << solution.getPermutation(4, 10) << endl;
    return 0;
}
