#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
 
int main() {
string s;
cin >>s;
int k;
cin >> k;
int n = s.size();
string ans = "";
    for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
        string tmp = "";
        for (int i = 0; i < n; ++i) {
            if(bitmask & (1<<i)){
                tmp+=s[i];
            }
        }
        if(tmp.size() == n-k){
            ans = max(ans,tmp);
        }
    }
cout << ans << endl ;
}
