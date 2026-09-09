// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        const int MAX_A = 5005;
        std::vector<int> A(N + 1), dp(N + 1), freq(MAX_A, 0);
        for (int i = 1; i <= N; i++) {
                std::cin >> A[i];
                freq[A[i]]++;
        }
        for (int i = 1; i <= N; i++) {
                dp[i] = dp[i - 1];
                std::vector<int> curr_freq(MAX_A, 0);
                std::unordered_set<int> st;
                curr_freq[A[i]]++;
                st.insert(A[i]);
                int len = bool(freq[A[i]] == curr_freq[A[i]]);
                if (len == 1) dp[i] = dp[i - 1] + A[i];
                int curr_xor = A[i];
                for (int j = i - 1; j >= 1; j--) {
                        curr_freq[A[j]]++;
                        if (!st.count(A[j])) curr_xor ^= A[j];
                        len += bool(freq[A[j]] == curr_freq[A[j]]);
                        st.insert(A[j]);
                        if (curr_freq[A[j]] == freq[A[j]] && len == (int)st.size()) { // possible to end this guy here
                                dp[i] = std::max(dp[i], dp[j - 1] + curr_xor);
                        }
                }
        }
        // for (int i = 1; i <= N; i++) std::cerr << dp[i] << " \n"[i == N];
        std::cout << dp[N] << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
