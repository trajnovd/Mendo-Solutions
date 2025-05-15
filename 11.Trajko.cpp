#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
 
using namespace std;
 
int main(){
  string s;
  cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]>= 'A' && s[i]<='Z'){
            s[i] = s[i]+ ('a' - 'A');
        }
    }
    long long res = 1;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='t'){
            res *= 3;
            i = i+7;
        }
        else if(s[i] == 'd'){
            res *= 2;
            i = i+4;
        }
        else if(s[i] == 'm'){
            res -= 1;
            i = i+4;
        }
    }
    cout << res;
}
