#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Create a copy
    stack<int> temp(st);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
