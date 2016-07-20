/* - convert int to string
 *     string s = to_string(123);
 * - convert C-style string to int
 *     char str[] = "123";
 *     int num = atoi(str);
 * - convert C++-style string to C-style string
 *     string str = "123";
 *     int num = atoi(str.c_str());
 * - generate a random integer between 0 and RAND_MAX (INT_MAX)
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // convert int to string
    string s = to_string(123);
    cout << s << endl;
    // convert C-style string to int
    char str[] = "123";
    int num = atoi(str);
    cout << num << endl;
    // convert C++-style string to int
    string str2 = "123";
    int num2 = atoi(str2.c_str());
    cout << num2 << endl;
    // generate random integers
    srand((unsigned) time(NULL));                    // set a time seed
    cout << rand() << endl;                          // a random integer between 0 and RAND_MAX (INT_MAX)
    const int LOW = 3, HIGH = 17; 
    cout << rand() % (HIGH - LOW + 1) + LOW << endl; // a random integer between LOW and HIGH
    return 0;
}
