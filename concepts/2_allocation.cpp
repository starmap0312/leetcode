/* - allocate a two-dimensional array
 *   1) vector<vector<int> > v;
 *   2) int arr[][]; // accessing array is faster than accessing vector
 *
 *   (wrong)
 *   int **arr = new int[10][20];  ==> Compile Error !!! 
 *
 *   (correct)
 *   int **arr = new int*[10];     ==> declare an array of pointers
 *   for (int i = 0; i < 10; i++)
 *       arr[i] = new int[20];     ==> for each pointer, allocate an integer array
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // allocate int arr[10][20] dynamically
    int **arr = new int*[10];
    for (int i = 0; i < 10; i++)
        arr[i] = new int[20];
    return 0;
}
