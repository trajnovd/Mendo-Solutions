#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
int p,k;
cin >> p >> k;
int max = 0;
 
int broj =1 ;
    for (int i = p; i <= k ; ++i) {
        int deliteli = 0;
        for (int j = 1; j <= (int)i/2; ++j) {
            if(i%j == 0){
                deliteli++;
            }
            if(max<deliteli){
                max = deliteli;
                broj =i;
            }
        }
    }
    cout << broj << " " << max+1;
}
