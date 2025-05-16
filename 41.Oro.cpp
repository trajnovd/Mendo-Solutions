#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace  std;
int p,m;
int n;
int a[1005];
int memo[1005][55];
int f(int k,int i){
    if(k<0 || k>m){
        return -1;
    }
    if(i == n ){
        return k;
    }
    if(memo[k][i] != -1){
        return memo[k][i];
    }
    int left= -1;
    int right= -1;
    left = f(k-a[i],i+1);
    right = f(k+a[i],i+1);
    int res = -1;
    res = max(left,right);
    return memo[k][i]= res;
}
int main() {
    cin >> p >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof memo);
    cout << f(p,0);
}
