/* - to count the number of A's, scan secret and guess strings simultaneously from left to right
 *   if two characters at the same position are identical, increment the number of A's
 * - to count the number of B's, use two hashmaps to record the occurrences of non-matched
 *   characters in both strings, respectively
 *   use the the hashmap information to compare the occurrences of each character in the secret
 *   string with the occurrences of the same character in the guess string, so that the number
 *   of B's can be deduced
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size()) return "";
        unordered_map<char, int> mp1, mp2;
        int numA = 0, numB = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) numA++;
            else {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for (unordered_map<char, int>::iterator itr1 = mp1.begin(); itr1 != mp1.end(); itr1++) {
            unordered_map<char, int>::iterator itr2 = mp2.find((*itr1).first);
            if (itr2 != mp2.end()) numB += min(itr1 -> second, itr2 -> second);
        }
        return (to_string(numA) + "A" + to_string(numB) + "B");
    }
};

int main() {
    Solution solution;
    cout << solution.getHint("1807", "7810") << endl;
    cout << solution.getHint("1123", "0111") << endl;
    return 0;
}
