// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        std::string s; int x, y; std::cin >> x >> y >> s;
        for (char c : s) {
                if (c == 'U') y++;
                else if (c == 'D') y--;
                else if (c == 'R') x++;
                else x--;
        }
        std::cout << x << " " << y << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        // std::cin >> tc;
        while (tc--) solve();
        return 0;
}
