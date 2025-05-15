#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
int n;
cin >>n;
int a[10005];
int perioda = 2;
int brojac = 2;
    for (int i = 1; i <=10000 ; i++) {
        a[i] = 0;
    }
    for (int i = 1; i <= 141; i++) {
        a[1] = 1;
        a[2] = 1;
 
        perioda = perioda + brojac;
        a[perioda] = 1;
        brojac++;
 
    }
    cout << a[n] << " " << a[n+1] ;
}
