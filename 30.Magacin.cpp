#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> weight(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> weight[i];
    }

    int D;
    cin >> D;
    vector<pair<int,int>> constraints(D);
    for (int i = 0; i < D; i++){
        int A, B;
        cin >> A >> B;
        constraints[i] = {A, B};
    }

    vector<int> perm;
    for (int i = 1; i <= N; i++){
        perm.push_back(i);
    }

    long long bestCost = numeric_limits<long long>::max();
    vector<int> bestPerm;

    do {
        vector<int> pos(N + 1);
        for (int i = 0; i < N; i++){
            pos[perm[i]] = i;
        }

        bool valid = true;
        for (auto &con : constraints){
            int A = con.first, B = con.second;
            if (pos[A] <= pos[B]){
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;

        long long cost = 0;
        for (int i = 1; i < N; i++){
            cost += (long long)weight[perm[i]] * i;
        }

        if (cost < bestCost){
            bestCost = cost;
            bestPerm = perm;
        } else if (cost == bestCost && perm < bestPerm){
            bestPerm = perm;
        }

    } while(next_permutation(perm.begin(), perm.end()));

    for (int i = 0; i < N; i++){
        cout << bestPerm[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
