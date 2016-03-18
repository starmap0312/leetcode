/* - convert int to string
 *     string s = to_string(123);
 * - convert C-style string to int
 *     char str[] = "123";
 *     int num = atoi(str);
 * - convert C++-style string to C-style string
 *     string str = "123";
 *     int num = atoi(str.c_str());
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = to_string(123);
    cout << s << endl;
    char str[] = "123";
    int num = atoi(str);
    cout << num << endl;
    string str2 = "123";
    int num2 = atoi(str2.c_str());
    cout << num2 << endl;
    return 0;
}
