/* - example 1: gray code sequences 
 *   gray code sequences of length n can be obtained using gray code sequences of length n - 1
 *   ex. 
 *     gray code sequences of length 1
 *       0
 *       1
 *     gray code sequences of length 2:
 *      (0) 0  <------ prepend 0 in order of the sequence
 *      (0) 1
 *      (1) 1  <------ prepend 1 and reverse the order of the sequence
 *      (1) 0
 *
 * - example 2: permutations
 *   permutations of i numbers can be obtained using permutations of i - 1 numbers
 *   ex.
 *     permutations of 2 numbers
 *       1 (2)    <------ insert 2 into (1)
 *      (2) 1
 *     permutations of 3 numbers
 *      (3) 1  2  <------ insert 3 into (1 2)
 *       1 (3) 2
 *       1  2 (3)
 *      (3) 2  1  <------ insert 3 into (2 1)
 *       2 (3) 1
 *       2  1 (3)
 * - example 3: number of unique BSTs 
 *   number of unique BSTs of size k can be obtained using number of unique BSTs of size 0, 1, ..., k - 1
 *   ex.
 *     number of unique BSTs of size 1
 *       1
 *     number of unique BSTs of size 2
 *      (1)       <------ root
 *     *   2      <------ (number of unique BSTs of size 0) * (number of unique BSTs of size 1) = 1 * 1
 *
 *      (2)       <------ root
 *     1   *      <------ (number of unique BSTs of size 1) * (number of unique BSTs of size 0) = 1 * 1
 */

#include <iostream>
#include <vector>

using namespace std;

class GrayCode {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for (int i = 0; i < n; i++) {
             vector<int> next_seq;
             for (int j = 0; j < result.size(); j++)
                 next_seq.push_back(result[j]);
             for (int j = result.size() - 1; j >= 0; j--)
                 next_seq.push_back(result[j] + (1 << i));
             result = next_seq;
        }
        return result;
    }
};

// initially:
//    0 == 0
// iteration 1:
//    0 == 0
//    1 == 1
// iteration 2:
//   00 == 0
//   01 == 1
//   11 == 3
//   10 == 2
// iteration 3:
//  000 == 0
//  001 == 1
//  011 == 3
//  010 == 2
//  110 == 6
//  111 == 7
//  101 == 5
//  100 == 4

class Permutations {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.size() == 0) return result;
        result.push_back(vector<int>(1, nums[0]));
        for (int i = 1; i < nums.size(); i++) {               // insert num[i] into all permutations
            vector<vector<int> > next;
            for (int j = 0; j < result.size(); j++) {         // for each previously computed permutation: result[j]
                for (int k = 0; k <= result[j].size(); k++) { // insert num[i] to each position k
                    vector<int> new_permutation = result[j];
                    new_permutation.insert(new_permutation.begin() + k, nums[i]);
                    next.push_back(new_permutation);
                }
            }
            result = next;
        }
        return result;
    }
};

class UniqueBSTs {
public:
    int numTrees(int n) {
        vector<int> answers(1, 1);        // let answers[i] be number of unique BSTs of size i
        for (int i = 1; i <= n; i++) {    // compute answers[i] for i = 1, 2, ..., n 
            int numTrees = 0;
            for (int j = 0; j < i; j++) { // let j be the size of its left subtree
                numTrees += (answers[j] * answers[i - j - 1]);
            }
            answers.push_back(numTrees);
        }
        return answers[n];
    }
};

int main() {
    cout << "example 1: gray code sequences" << endl;
    GrayCode gray;
    vector<int> rc = gray.grayCode(3);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;

    cout << "example 2: permutations" << endl;
    int a[] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    Permutations permutations;
    vector<vector<int> > rc2 = permutations.permute(nums);
    for (int i = 0; i < rc2.size(); i++) {
        for (int j = 0; j < rc2[i].size(); j++)
            cout << rc2[i][j] << " ";
        cout << endl;
    }

    cout << "example 3: number of unique BSTs" << endl;
    UniqueBSTs bst;
    cout << bst.numTrees(3) << endl;
    return 0;
}
