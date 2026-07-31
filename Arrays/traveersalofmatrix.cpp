#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initializing a 2-D vector with values
    vector<vector<int>> arr = { { 1, 2, 3, 4 },
                                { 5, 6, 7, 8 },
                                { 9, 10, 11, 12 } };

    // Traversing over all the rows
    for (int i = 0; i < arr.size(); i++) {
      
        // Traversing over all the columns of each row
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
