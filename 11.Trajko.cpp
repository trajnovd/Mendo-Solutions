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
int n,m;
cin >> n >> m;
vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    for (int i = 0; i < n;) {
        if(i+m<n){
            res = v[i]*2+res;
            i = i+m;
        }
        else{
            res = res + v[i]*2;
            i = i+(n-i);
        }
 
    }
    cout << res;
}
