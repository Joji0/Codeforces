#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 67;

bool prime[maxN];
set<int> primes;

void precompute() {
    for (int i = 0; i < maxN; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int64_t i = 2; i < maxN; i++) {
        if (prime[i])
            for (int64_t j = i * i; j < maxN; j += i) {
                prime[j] = false;
            }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i])
            primes.insert(i);
    }
}

vector<array<int64_t, 2>> trial_division1(int64_t n) {
    vector<array<int64_t, 2>> factorization;
    for (long long d = 2; d * d <= n; d++) {
        int cnt = 0;
        if (n % d == 0) {
            while (n % d == 0) {
                cnt++;
                n /= d;
            }
            factorization.push_back({d, cnt});
        }
    }
    if (n > 1)
        factorization.push_back({n, 1});
    return factorization;
}

void solve() {
    /*
     * observation: for lcm(a, b) to be a semi prime we need the following:
     * if we decompose a and b to it's prime factorization and we have
     * form(1):
     * a = pa^1
     * b = pb^1
     * then a is prime and b is prime and pa != pb -> lcm(a, b) semi prime.
     * Consider pa = pb, we can also have
     * form(2):
     * a = pa^1
     * b = pa^2
     * then if pa = pb and max(ea, eb) = 2 -> lcm(a, b) semi prime.
     * consider only a with
     * form(3):
     * a = pa ^ 1 * pb ^ 1
     * we can actually pair this a with every pow1[pa] and pow1[pb].
     * We can consider only the three above form.
     */
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int64_t> pow1, pow2;
    vector<array<int64_t, 2>> spec;
    auto isSqr = [](const int &x) -> bool {
        int r = (int)sqrt(x);
        return r * r == x;
    };
    for (auto &x : A) {
        cin >> x;
        if (primes.contains(x)) {
            pow1[x]++;
        } else if (isSqr(x) && primes.contains((int)sqrt(x))) {
            pow2[(int)sqrt(x)]++;
        } else {
            auto f = trial_division1((int64_t)x);
            if ((int)f.size() == 2 && f[0][1] == 1 && f[1][1] == 1) {
                spec.push_back({f[0][0], f[1][0]});
            }
        }
    }
    int64_t ans = 0;
    int64_t tot = 0, pair = 0;
    for (auto &[_, cnt] : pow1) {
        pair += cnt;
    }
    for (auto &[_, cnt] : pow1) {
        tot += cnt * (pair - cnt);
        pair -= cnt;
    }
    ans += tot;
    for (auto &[el, cnt] : pow2) {
        ans += cnt * (cnt + 1) / 2;
        ans += cnt * pow1[el];
    }
    map<array<int64_t, 2>, int64_t> mspec;
    for (auto &[a, b] : spec) {
        ans += pow1[a] + pow1[b];
        if (a < b)
            swap(a, b);
        mspec[{a, b}]++;
    }
    for (auto &[arr, c] : mspec) {
        ans += c * (c + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
