#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    /*
     * observation: for each occurence from 1 to maxC we try this number, say K.
     * Then for every occurence < K we need to delete it until 0. Else, we can
     * reduce it to K. To efficiently compute this let pref[K - 1] be the total
     * elements with occurence <= K - 1 and let suff[K + 1] be the total cost to
     * shift all elements with occurence >= K + 1 to K. Then for this specific K
     * the cost is simply pref[K - 1] + suff[K + 1].
     *
     * so actually suff is a bit more tricky because its not simply counting
     * occurence > K lol. suff definition must be treated more carefully since
     * we are actually trying to shift every element > K to K itself NOT 0!
     */
    int N;
    cin >> N;
    vector<int64_t> A(N);
    map<int64_t, int64_t> mp;
    int64_t mx = -1;
    for (auto &x : A) {
        cin >> x;
        mp[x]++;
        mx = max(mx, mp[x]);
    }
    map<int64_t, int64_t> occ;
    for (auto &[el, cnt] : mp) {
        occ[cnt]++;
    }
    vector<int64_t> pref(mx + 67, 0), suff1(mx + 67, 0), suff2(mx + 67, 0);
    for (int i = 1; i <= mx; i++) {
        pref[i] = pref[i - 1] + 1LL * i * occ[i];
    }
    for (int i = mx; i >= 1; i--) {
        suff1[i] = suff1[i + 1] + 1LL * i * occ[i];
        suff2[i] = suff2[i + 1] + occ[i];
    }
    int64_t ans = INF;
    for (int i = 1; i <= mx; i++) {
        ans = min(ans, pref[i - 1] + (suff1[i + 1] - 1LL * i * suff2[i + 1]));
    }
    cout << ans << '\n';
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
