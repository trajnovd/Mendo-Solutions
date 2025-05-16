#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#include <set>
#define ll long long
using namespace std;
int f(int x){
    int a = x;
    while(a>0){
        x += a%10;
        a/=10;
    }
    return x;
}
int main() {
    int n;
    cin >> n;
    set<int> s1;
    set<int> s3;
    set<int> s9;
    s1.insert(1);
    s3.insert(3);
    s9.insert(9);
    for(int i =0;i<16385;i++){
        s1.insert(f(*s1.rbegin()));
        s3.insert(f(*s3.rbegin()));
        s9.insert(f(*s9.rbegin()));
    }
 
    while(true){
        if(s1.count(n)){
            cout << 1 << " " << n;
            break;
        }
        else if(s3.count(n)){
            cout << 3 << " " << n;
            break;
        }
        else if(s9.count(n)){
            cout << 9 << " " << n;
            break;
        }
        else{
            n = f(n);
        }
    }
}
