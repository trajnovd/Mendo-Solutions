#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> prva_runda;
    vector<int> vtora_runda;
    int prva[1000],vtora[1000];
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        prva[i]= a;
        vtora[i] =b;
        prva_runda.push_back(a);
        vtora_runda.push_back(b);
    }
    sort(prva_runda.rbegin(),prva_runda.rend());
    int pominati[1000];
    for (int j = 0; j < k; ++j) {
        pominati[j] = prva_runda[j];
    }
    int res= -1;
    int index ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if(pominati[j] == prva[i]) {
                if (res < vtora[i]) {
                    res = vtora[i];
                    index = i;
                }
            }
        }
    }
    cout << index+1;
}
