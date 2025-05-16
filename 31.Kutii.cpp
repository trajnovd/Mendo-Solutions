#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main()
{
int n,m;
cin >> n >> m;
int predmeti[n];
int kutii[m];
 
for(int i = 0;i<n;i++){
    cin >> predmeti[i];
}
for(int i =0;i<m;i++){
    cin >> kutii[i];
}
 
int res = 0;
 
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        if(predmeti[i]<= kutii[j]){
            res++;
            kutii[j] = -1;
            break;
        }
    }
}
cout << res;
}
