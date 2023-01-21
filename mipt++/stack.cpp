#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    int n;
    cin>>n;
    for(; n != 0; cin>>n) {
        if (n > 0) {
            st.push(n);
        }
        else if(n < 0 && st.empty()) {
            continue;
        }
        else if(n < 0 && abs(n) < st.top()) {
            st.top()+=n;
        }
        else {
            st.pop();
        }
    }
    if (!st.empty())
        cout<<st.size()<<' '<<st.top();
    else
        cout<<st.size()<<' '<<-1;
    return 0;
}