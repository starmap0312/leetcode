/* - #include <cmath> ==> use sqrt(2) == 1.41421, sqrt(3) == 1.73205 to
 *                        get the square root of a number
 * - to determine if a number n is a prime, check if it can be divided
 *   by 1. numbers between 2 to n - 1
 *      2. numbers between 2 to sqrt(n)
 *      3. prime numbers between 2 to sqrt(n)
 *   
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> primes;
        int count = 1;
        for (int i = 3; i < n; i++)
            if (isPrime(i, primes)) count++;
        return count;
    }

    bool isPrime(int n, vector<int> &primes) {
        if (n % 2 == 0) return false;
        for (int i = 0; i < primes.size() && 
            primes[i] * primes[i] <= n; i++) {
            if (n % primes[i] == 0) return false;
        }
        primes.push_back(n);
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.countPrimes(9) << endl;
    cout << sqrt(2) << endl;
    cout << sqrt(3) << endl;
    cout << sqrt(4) << endl;
    return 0;
}
