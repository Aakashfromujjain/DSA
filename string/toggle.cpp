#include <iostream>
#include <cctype>
using namespace std;

string toggleChar(string& str) {
    string result = "";
    
    // Iterate over the original string
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        // Check the case of the character and
        // toggle accordingly
        if (isupper(ch))
            result += tolower(ch);
        else
            result += toupper(ch);
    }
    return result;
}

int main() {
    string str = "GeEkSfOrGeEkS";
    string x = toggleChar(str);
    cout << x << endl;
    return 0;
}
