#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;
 
int main() {
    int n;
    int paketi;
    int cifra;
    int seski = 0;
    int devetki = 0;
    int broj = 0;
    vector <int> cifri (20);
    cin >> n;
    int k =0;
    while (n > 0){
        cifra = n%10;
        cifri[k] = cifra;
        n = n/10;
        k++;
    }
    int maxcifra = 0;
    int max = 0;
    for(int j = 0;j<10;j++){
        broj = 0;
        if(cifri[j] == 6){
            seski++;
        }
        if(cifri[j] == 9){
            devetki++;
        }
        for(int i = 0; i<k; i++){
            if(cifri[i] == j)
                broj++;
        }
 
        if(broj> max){
            max = broj;
            maxcifra = j;
        }
    }
    if ( maxcifra == 6 || maxcifra == 9 ){
        int sum69 = seski + devetki;
        paketi = (sum69+1)/2;
 
    }
    else paketi = max;
    cout << paketi;
}
