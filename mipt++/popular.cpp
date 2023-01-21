#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string s;
    int n;
    cin>>n;
    map<string, int> pop;
    for (int i = 0; i < n; i++) {
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        pop.emplace(s, 0);
        pop[s]++;
    }
    auto max = pop.begin();
    for (auto i = pop.begin(); i != pop.end(); i++) {
        if(i->second > max->second) {
            max = i;
        }
    }
    cout<<max->first<<' '<<max->second;
    return 0;
}