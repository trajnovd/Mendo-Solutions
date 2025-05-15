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
    cin >> n >>k;
    int r;
    int res =2e9;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if(i*3 + j*5 <= n && (i*5 + j*9>0)){
                r =  k/(i*5 + j*9);
                if(k%(i*5 + j*9) > 0){
                    r++;
                }
                res = min(res,r);
            }
        }
    }
    cout << res;
 
}
