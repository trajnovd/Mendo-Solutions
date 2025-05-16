#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main()
{
int p,k;
cin >> p >> k;
int arr[30];
arr[1] = 1;
arr[2] = 1;
for(int i =3;i<30;i++){
    arr[i] = arr[i-1]+arr[i-2];
}
int res = 0;
for(int i = 1;i<30;i++){
  if(arr[i]>=p and arr[i]<=k){
    res++;
  }
 
}
cout << res;
}
