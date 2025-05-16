#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// simple struct for row/column
struct PointRC { int r, c; };

// given a point number, recover its (r,c) in the triangular numbering
PointRC get_rc_coords(int p_num) {
    int r = 0;
    while (true) {
        long long upTo = (long long)(r + 1) * (r + 2) / 2;
        if (p_num <= upTo) {
            long long first = (long long)r * (r + 1) / 2 + 1;
            return { r, int(p_num - first) };
        }
        ++r;
    }
}

// test whether (dr,dc) is a straight lattice segment and record its length,
// axis (0=horizontal,1=dir (1,0),2=dir (1,1)), and unit‐direction.
bool straight(int dr, int dc, int &len, int &axis, pair<int,int> &dir) {
    if (dr == 0 && dc != 0) {
        len = abs(dc);
        axis = 0;
        dir = { 0, dc / abs(dc) };
        return true;
    }
    if (dc == 0 && dr != 0) {
        len = abs(dr);
        axis = 1;
        dir = { dr / abs(dr), 0 };
        return true;
    }
    if (dr == dc && dr != 0) {
        len = abs(dr);
        axis = 2;
        dir = { dr / abs(dr), dc / abs(dc) };
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    while (N--) {
        int k;
        cin >> k;
        vector<int> pts(k);
        for (int i = 0; i < k; ++i) cin >> pts[i];

        // recover coords
        vector<PointRC> rc(k);
        for (int i = 0; i < k; ++i)
            rc[i] = get_rc_coords(pts[i]);

        // TRIANGLE?
        if (k == 3) {
            vector<int> idx = {0,1,2};
            do {
                auto &A = rc[idx[0]];
                auto &B = rc[idx[1]];
                auto &C = rc[idx[2]];
                int dr1 = B.r - A.r, dc1 = B.c - A.c;
                int dr2 = C.r - B.r, dc2 = C.c - B.c;
                int dr3 = A.r - C.r, dc3 = A.c - C.c;
                int L1, L2, L3, ax1, ax2, ax3;
                pair<int,int> d1, d2, d3;
                if (!straight(dr1, dc1, L1, ax1, d1)) continue;
                if (!straight(dr2, dc2, L2, ax2, d2)) continue;
                if (!straight(dr3, dc3, L3, ax3, d3)) continue;
                if (L1>0 && L1==L2 && L2==L3
                    && ax1!=ax2 && ax2!=ax3 && ax1!=ax3)
                {
                    cout << "TRIAGOLNIK\n";
                    goto next_group;
                }
            } while (next_permutation(idx.begin(), idx.end()));
        }
        // PARALLELOGRAM?
        else if (k == 4) {
            vector<int> idx = {0,1,2,3};
            do {
                auto &A = rc[idx[0]];
                auto &B = rc[idx[1]];
                auto &C = rc[idx[2]];
                auto &D = rc[idx[3]];
                int dr1=B.r-A.r, dc1=B.c-A.c;
                int dr2=C.r-B.r, dc2=C.c-B.c;
                int dr3=D.r-C.r, dc3=D.c-C.c;
                int dr4=A.r-D.r, dc4=A.c-D.c;
                int L1, a1, L2, a2, L3, a3, L4, a4;
                pair<int,int> d1, d2, d3, d4;
                if (!straight(dr1,dc1,L1,a1,d1)) continue;
                if (!straight(dr2,dc2,L2,a2,d2)) continue;
                if (!straight(dr3,dc3,L3,a3,d3)) continue;
                if (!straight(dr4,dc4,L4,a4,d4)) continue;
                if (L1>0 && L1==L2 && L1==L3 && L1==L4
                    && a1==a3 && d1.first==-d3.first && d1.second==-d3.second
                    && a2==a4 && d2.first==-d4.first && d2.second==-d4.second
                    && a1!=a2)
                {
                    cout << "PARALELOGRAM\n";
                    goto next_group;
                }
            } while (next_permutation(idx.begin(), idx.end()));
        }
        // REGULAR HEXAGON?
        else if (k == 6) {
            // exactly the six neighbor directions
            static const vector<pair<int,int>> ALL_DIRS = {
                {0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1}
            };
            vector<int> idx = {0,1,2,3,4,5};
            do {
                int side_len = -1;
                vector<pair<int,int>> dirs(6);
                bool ok = true;
                for (int i = 0; i < 6; ++i) {
                    auto &P = rc[idx[i]];
                    auto &Q = rc[idx[(i+1)%6]];
                    int dr = Q.r - P.r, dc = Q.c - P.c;
                    int L, axis;
                    pair<int,int> ud;
                    if (!straight(dr, dc, L, axis, ud)) { ok = false; break; }
                    if (i==0) side_len = L;
                    else if (L != side_len) { ok = false; break; }
                    dirs[i] = ud;  // unit‐direction
                }
                if (!ok || side_len <= 0) continue;
                // closure of unit‐directions must sum to zero
                int sdr=0, sdc=0;
                for (auto &d: dirs) { sdr += d.first; sdc += d.second; }
                if (sdr || sdc) continue;
                // must use each of the 6 lattice directions exactly once
                vector<bool> seen(6,false);
                for (auto &d: dirs) {
                    bool found = false;
                    for (int j=0;j<6;++j){
                        if (!seen[j] && d==ALL_DIRS[j]) {
                            seen[j] = true;
                            found = true;
                            break;
                        }
                    }
                    if (!found) { ok = false; break; }
                }
                if (ok) {
                    cout << "SESTOAGOLNIK\n";
                    goto next_group;
                }
            } while (next_permutation(idx.begin(), idx.end()));
        }

        // if we reach here, none matched:
        cout << "NISTO\n";

    next_group:;
    }
    return 0;
}
