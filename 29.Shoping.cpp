#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
  
int main() {
    int n,d;
    cin >> n >> d;
    double popust = (double)(100 -d)/100;
    double arr[1000];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    double sum =0;
    int p = n-(n/3);
    for (int i = 0; i < n; i++) {
        if(p>i) {
            sum += arr[i];
        }
  
        if(i>=p){
            sum+= arr[i]*popust;
        }
    }
   cout  << fixed << setprecision(2) << sum;
}
