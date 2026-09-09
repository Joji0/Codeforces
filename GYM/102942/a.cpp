// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::string s; std::cin >> N >> s;
        int start = 0;
        for (int i = 0; i < N; i++) {
                if (s[i] == '1') {
                        start++;
                } else {
                        start--;
                }
        }
        start = ((start % 4) + 4) % 4;
        switch(start) {
                case 0:
                        std::cout << "E\n";
                        break;
                case 1:
                        std::cout << "N\n";
                        break;
                case 2:
                        std::cout << "W\n";
                        break;
                case 3:
                        std::cout << "S\n";
                        break;
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
