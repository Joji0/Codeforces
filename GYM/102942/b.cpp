// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<int> A(N);
        bool ok = 0;
        int cnt = 0;
        for (auto &x : A) {
                std::cin >> x;
                ok |= (x & 1);
                if (!(x & 1)) cnt++;
        }
        if (!ok) {
                std::cout << "-1\n";
                return;
        }
        std::cout << cnt << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
