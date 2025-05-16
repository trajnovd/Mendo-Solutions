#include <bits/stdc++.h>
using namespace std;

long long flips_to_target(const vector<int>& a, int k, int target) {
    int n = a.size();
    vector<int> diff(n+1, 0);
    int curr_flip = 0;
    long long moves = 0;
    for (int i = 0; i < n; i++) {
        curr_flip ^= diff[i];
        int cur = a[i] ^ curr_flip;
        if (cur != target) {
            if (i + k > n) 
                return LLONG_MAX/2;
            moves++;
            curr_flip ^= 1;
            diff[i+k] ^= 1;
        }
    }
    return moves;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long to0 = flips_to_target(a, k, 0);
    long long to1 = flips_to_target(a, k, 1);
    long long ans = min(to0, to1);
    if (ans >= LLONG_MAX/4) 
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
