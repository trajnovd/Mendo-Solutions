#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }

    int bribes = 0;
    while (true) {
        int best = 0, idx = -1;
        for (int i = 1; i < N; i++) {
            if (G[i] > best) {
                best = G[i];
                idx = i;
            }
        }
        if (G[0] > best) break;
        G[0]++;
        G[idx]--;
        bribes++;
    }

    cout << bribes << "\n";
    return 0;
}
