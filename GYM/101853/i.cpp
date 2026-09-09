// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        const double PI = acos(-1);
        int64_t a, b; double d; std::cin >> a >> b >> d;
        double r = double(d) / 2.0;
        double sector = 1.0 / 4.0 * PI * r * r;
        double segment = sector - 1.0 / 2.0 * double(d) / sqrt(2.0) * sqrt((d / 2.0) * (d / 2.0) - (d / (2 * sqrt(2))) * (d / (2 * sqrt(2))));
        double r_in = d / (2 * sqrt(2));
        double ans = 1.0 / 2.0 * PI * r_in * r_in - segment;
        std::cout << std::fixed << std::setprecision(10) << 4 * ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
