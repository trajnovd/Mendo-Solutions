#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;
string s;
int memo[5005];
 
int f(int x) {
    if (x >= s.length()) {
        return 1;
    }
    if (memo[x] != -1) {
        return memo[x];
    }
    int ways = 0;
    if (s[x] != '0') {
        ways += f(x + 1);
    }
    if (s[x] != '0' && x + 1 < s.length()) {
        int number = (s[x] - '0') * 10 + (s[x + 1] - '0');
        if (number <= 26) {
            ways += f(x + 2);
        }
    }
    return memo[x] = ways;
}
 
int main() {
    
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            memo[i] = -1;
        }
        cout << f(0) << endl;
     
}
