#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
int n;
int a[100000][3];
cin >> n;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    int max_res = 0;
    for (int i = 0; i< n; ++i) {
       if(max_res < 3*a[i][0] + 1* a[i][1]){
           max_res = 3*a[i][0] + 1*a[i][1];
       }
    }
    cout << max_res;
}
