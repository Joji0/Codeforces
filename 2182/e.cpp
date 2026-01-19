#include <bits/stdc++.h>
using namespace std;

struct Info {
    int id, x;
    int64_t y, z, d;
};

void solve() {
    int N, M;
    int64_t K;
    cin >> N >> M >> K;
    vector<int> A(M);
    for (auto &x : A)
        cin >> x;
    sort(A.begin(), A.end());
    vector<Info> F(N);
    int64_t s = 0;
    for (int i = 0; i < N; i++) {
        cin >> F[i].x >> F[i].y >> F[i].z;
        F[i].d = F[i].z - F[i].y;
        F[i].id = i;
        s += F[i].y;
    }
    int64_t B = K - s;
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int i, int j) { return F[i].x < F[j].x; });
    priority_queue<array<int64_t, 2>, vector<array<int64_t, 2>>> pq;
    vector<bool> boxing(N, 0);
    int ptr = 0, cnt = 0;
    for (auto &bty : A) {
        while (ptr < N && F[order[ptr]].x <= bty) {
            int id = order[ptr];
            pq.push({F[id].d, id});
            ptr++;
        }
        if (!pq.empty()) {
            auto [d, id] = pq.top();
            pq.pop();
            if (!boxing[id]) {
                boxing[id] = 1;
                cnt++;
            }
        }
    }
    vector<int64_t> need;
    for (int i = 0; i < N; i++) {
        if (!boxing[i])
            need.push_back(F[i].d);
    }
    sort(need.begin(), need.end());
    int64_t p = 0, spend = 0;
    for (auto &d : need) {
        if (spend + d <= B) {
            spend += d;
            p++;
        } else {
            break;
        }
    }
    cout << cnt + p << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
