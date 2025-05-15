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
    int n,k;
    cin >> n >> k;
    int a[20];
    for (int i = 0; i < k; i++) {
        cin >>a[i];
    }
    int res = 2e9;
    for (int mask = 0; mask < (1 << k); mask++) {
        int suma = 0;
        int max1 = -1;
        if(__builtin_popcount(mask) == n-1){
            for (int i = 0; i < k; i++) {
                if(mask & (1 << i)){
                    max1 = max(max1, suma);
                    suma = a[i];
                }
                else{
                    suma += a[i];
                }
                max1 = max(max1, suma);
            }
            res = min(res,max1);
        }
    }
    cout << res;
}
