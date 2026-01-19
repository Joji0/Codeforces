#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
     * observation: just simple combinatorics problem, notice that we can do the
     * following construction:
     * First case: N consec at the front or the back
     * -> For the N consec we can have 4 ways to do this and at position N + 1
     * we must have 3 ways (not 4 since that will become N + 1 consec) and
     * from N + 2 to 2N - 2 we have 4 ways for each position giving the
     * contribution: 4 * 3 * 4 ^ (2N - 2 - (N + 2) + 1) BUT DONT FORGET we can
     * do this in the back too from symmetry. Hence the final contribution must
     * be multiplied by 2. Giving the first case total contribution as 4 * 3 * 4
     * ^ (N - 3) * 2 = 24 * 4 ^ (N - 3)
     *
     * Second case: N consec at middle
     * -> For the N consec we again have 4 ways, and the position exactly before
     * the consecutive must be 3 ways and after that also must be 3 ways. The
     * other (2N - 2 - (N + 2)) = N - 4 position can be filled up with 4 ways.
     * For each middle part (which is 2N - 2 - (N + 2) + 1 = N - 3 possible
     * start point) we have the final contribution as:
     * 4 * 3 * 3 * 4 ^ (N - 4) * (N - 3) = 36 * 4 ^ (N - 4) * (N - 3)
     *
     * Finally we have 24 * 4 ^ (N - 3) + 36 * (N - 3) * 4 ^ (N - 4) (for N >=
     * 3)
     *
     * The edge case is when N = 1 and N = 2, for N = 1 there are no available
     * parking slot so the answer is 0. For N = 2, 2N - 2 = 2 so that theres
     * only 4 ways (for each car)
     */
    int N;
    cin >> N;
    auto pw = [](const int64_t base, const int pow) -> int64_t {
        int64_t ret = 1;
        for (int i = 0; i < pow; i++) {
            ret *= base;
        }
        return ret;
    };
    if (N == 1) {
        cout << "0\n";
    } else if (N == 2) {
        cout << "4\n";
    } else {
        int64_t ans = 24 * pw(4, N - 3) + 36 * (N - 3) * pw(4, N - 4);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
