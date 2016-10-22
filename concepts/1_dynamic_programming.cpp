/* - example 1: gray code sequence 
 *   gray code sequence of length n can be generated using gray code sequence of length n - 1
 *   ex. 
 *     gray code sequence of length 1
 *       0
 *       1
 *     gray code sequence of length 2:
 *      (0) 0  <------ prepend 0 in order of the sequence
 *      (0) 1
 *      (1) 1  <------ prepend 1 and reverse the order of the sequence
 *      (1) 0
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
int main() {
    cout << "example 1: gray code sequence" << endl;
    GrayCode gray;
    vector<int> rc = gray.grayCode(3);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
