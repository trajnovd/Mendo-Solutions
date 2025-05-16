#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> reci(n);
    for(int i = 0; i < n; i++) cin >> reci[i];
    for(int i = 0; i < n; i++){
        for(int k = 1; k <= (int)reci[i].size(); k++){
            bool ok = true;
            string pref = reci[i].substr(0, k);
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                if((int)reci[j].size() >= k && reci[j].substr(0, k) == pref){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << pref << "\n";
                break;
            }
        }
    }
    return 0;
}
