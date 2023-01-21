#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin>>n;
    set<int> povtor;
    int d;
    for (int i = 0; i < n; i++) {
        cin>>d;
        povtor.emplace(d);
    }
    cout<<povtor.size();
    return 0;
}