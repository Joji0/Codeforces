#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N, Y, Z;
        cin >> N;
        vector<int> divs;
        for (int64_t i = 1; i * i <= N; i++) {
                if (N % i == 0) {
                        divs.push_back(i);
                        if (N % (N / i) == 0 && i != N / i) {
                                divs.push_back(N / i);
                        }
                }
        }
        int M = (int)divs.size();
        bool ok = false;
        for (int i = 0; i < M; i++) {
                for (int j = i + 1; j < M; j++) {
                        int64_t have = (int64_t)(divs[i] + divs[j]) * N;
                        if ((int64_t)divs[i] * divs[j] == have) {
                                ok = true;
                                Y = divs[i], Z = divs[j];
                                goto DONE;
                        }
                }
        }
DONE:
        if (ok)
                cout << N << " " << Y << " " << Z << '\n';
        else
                cout << "-1\n";
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
