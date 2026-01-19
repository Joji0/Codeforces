#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 67;
const int64_t INF = 1e18;

bool prime[maxN];
vector<int> primes;

void precompute() {
    for (int i = 0; i < maxN; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int64_t i = 2; i < maxN; i++) {
        if (prime[i]) {
            for (int64_t j = i * i; j < maxN; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < maxN; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int64_t>> mat(N, vector<int64_t>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    int64_t ans = INF;
    for (int i = 0; i < N; i++) {
        int64_t cnt = 0;
        for (int j = 0; j < M; j++) {
            auto it = lower_bound(primes.begin(), primes.end(), mat[i][j]);
            cnt += *it - mat[i][j];
        }
        ans = min(ans, cnt);
    }
    for (int j = 0; j < M; j++) {
        int64_t cnt = 0;
        for (int i = 0; i < N; i++) {
            auto it = lower_bound(primes.begin(), primes.end(), mat[i][j]);
            cnt += *it - mat[i][j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
