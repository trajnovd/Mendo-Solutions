#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[10000];
    string s[10000];
    int min =100000000;
    int max = 0;
    for (int i = 0; i<n; i++){
        cin >> a[i];
        cin >> s[i];
        if(s[i] == "DA"){
            if(min>a[i]){
                min = a[i];
            }
        }
        if(s[i] == "NE"){
            if(max<a[i]){
                max = a[i];
            }
        }
    }
 
    if (min - max >= 2){
        cout << max +1 << " " << min -1;
    }
}
