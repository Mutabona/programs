#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;
    map<int, vector<int>> edg;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        edg[a].push_back(c);
    }
    for (auto i: edg) {
        int count = 0, sum = 0;
        for (auto j = i.second.begin(); j != i.second.end(); j++) {
            count++;
            sum+=*j;
        }
        cout<<i.first<<' '<<count<<' '<<sum<<'\n';
    }
    return 0;
}