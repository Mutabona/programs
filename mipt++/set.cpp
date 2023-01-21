#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
    size_t m, k, n;
    char s[30];
    scanf("%zu %zu %zu", &n, &m, &k);
    vector<set<size_t>*> set_to_int(m + 1);
    map<size_t, set<size_t>> data;
    for (int i = 0; i < k; i++) {
        scanf("%s", s);
        if (!strcmp(s, "ADD")) {
            scanf("%zu %zu", &n, &m);
            data[m].insert(n);
            set_to_int[m] = &data[m];
        }
        else if (!strcmp(s, "DELETE")) {
            scanf("%zu %zu", &n, &m);
            data[m].erase(n);
        }
        else if (!strcmp(s, "CLEAR")) {
            scanf("%zu", &m);
            data[m].clear();
        }
        else if (!strcmp(s, "LISTSET")) {
            scanf("%zu", &m);
            if (set_to_int[m] == NULL || (*set_to_int[m]).empty()) {
                printf("-1 ");
            }
            else {
                for (auto i = (*set_to_int[m]).begin(); i != (*set_to_int[m]).end(); i++)
                    printf("%zu ", *i);
            }
        }
        else if (!strcmp(s, "LISTSETSOF")) {
            bool f = 0;
            scanf("%zu", &n);
            for(auto i = data.begin(); i != data.end(); i++) {
                if (i->second.find(n) == i->second.end())
                    continue;
                f = 1;
                printf("%zu ", i->first);
            }
            if(!f)
                printf("-1 ");
        }
    }
    return 0;
}