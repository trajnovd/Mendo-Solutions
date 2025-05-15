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
int p,n;
cin >> p >> n;
int a[11];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int res =2e9;
    for (int i = 0; i <= 99999; i++) {
        bool t = true;
        int broj  = i;
        int cifri = 0;
        while(broj >0){
            int digit = broj%10;
            cifri++;
            for (int j = 0; j < n; j++) {
                if(digit == a[j]){
                    t = false;
                    break;
                }
            }
            broj /= 10;
        }
        if(t){
            res = min(res,cifri+ abs(p-i));
        }
    }
    cout << min(res, abs(p-100));
}
