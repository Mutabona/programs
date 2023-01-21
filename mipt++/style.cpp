#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;  getline(cin, s);
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }
    bool isUnar = 1;
    for(int i = 0; i <= s.length(); i++) {
        if (s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '=') {
            if (s[i+1] != ' ')
                s.insert(i+1, " ");               
            if (s[i-1] != ' ') {
                s.insert(i, " ");
                i++;
            }
            isUnar = 1;
        }
        else if (s[i] == ',') {
            if (s[i+1] != ' ')
                s.insert(i+1, " ");
            if (s[i-1] == ' ') {
                s.erase(i-1, 1);
                i--;
            }
            isUnar = 1;
        }
        else if (s[i] == '+' || s[i] == '-') {
            if(!isUnar) {
                if (s[i+1] != ' ')
                    s.insert(i+1, " ");
                if (s[i-1] != ' ') {
                    s.insert(i, " ");
                    i++;
                }
                isUnar = 1;
            }
            else {
                if (s[i+1] == ' ')
                    s.erase(i+1, 1);
            }
        }
        else if(s[i] == ' ' || s[i] == '(' || s[i] == ')') {
            if(s[i] == '(') {
                if(s[i+1] == ' ')
                    s.erase(i+1, 1);
                isUnar = 1;
            }
            if(s[i] == ')') {
                if(s[i-1] == ' ') {
                    s.erase(i-1, 1);
                    i--;
                }
                isUnar = 0;
            }
            continue;
        }
        else {
            isUnar = 0;
        }
    }
    cout<<s;
}