#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Range-based loop
  	for (char i : v)
        cout << i << " ";
    return 0;
}
