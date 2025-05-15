#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
   int n;
   cin >> n;
   int a[1500];
   int zbir = 0;
   for(int i = 0;i<n;i++){
       cin >> a[i];
       zbir = zbir + a[i];
   }
   double arr = (zbir*1.0)/n;
   double min = 1000000000;
   int elem = 0;
   for (int i = 0; i < n; i++) {
        if(min>abs( arr - a[i])){
            min = abs(arr-a[i]);
            elem = a[i];
        }
 
 
    }
   cout << elem;
}
