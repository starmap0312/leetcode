/* - to_string(): convert int to string
 *     string s = to_string(123);
 * - atoi(): convert C-style string to int
 *     char str[] = "123";
 *     int num = atoi(str);
 * - c_str(): convert C++-style string to C-style string
 *     string str = "123";
 *     int num = atoi(str.c_str());
 * - rand(): generate a random integer between [0, RAND_MAX], i.e. [0, INT_MAX]
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // to_string(): convert int to string
    string s = to_string(123);
    cout << s << endl;
    // atoi(): convert C-style string to int
    char str[] = "123";
    int num = atoi(str);
    cout << num << endl;
    // c_str(): convert C++ string to C-style string
    string str2 = "123";
    int num2 = atoi(str2.c_str());
    cout << num2 << endl;
    // rand(): generate random integers
    srand((unsigned) time(NULL));                    // set a time seed
    cout << rand() << endl;                          // a random integer between 0 and RAND_MAX (INT_MAX)
    const int lower_bound = 3, upper_bound = 17; 
    cout << rand() % (upper_bound - lower_bound + 1) + lower_bound << endl; // generate a random integer between [lower_bound, upper_bound]
    return 0;
}
