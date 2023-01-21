#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    set<string> stroki;
    string temp;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        stroki.emplace(temp);
    }
    for (auto i = stroki.rbegin(); i != stroki.rend(); i++)
        cout<<*i<<' ';
    return 0;
}