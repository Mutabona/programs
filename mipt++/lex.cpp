#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    string s;
    cin>>n;
    set<string> lex;
    for (int i = 0; i < n; i++) {
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        lex.emplace(s);
    }
    set<string>::reverse_iterator rit;
    for (rit = lex.rbegin(); rit != lex.rend(); rit++)
        cout<<(*rit)<<' ';
    return 0;
}