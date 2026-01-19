#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &A, bool invert) {
    int n = (int)A.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(A[i], A[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2.0 * PI / len * (invert ? -1.0 : 1.0);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = A[i + j];
                cd v = A[i + j + len / 2] * w;
                A[i + j] = u + v;
                A[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd &x : A)
            x /= (double)n;
    }
}

vector<int> convolution_fft(const vector<int> &A, const vector<int> &B,
                            int mx) {
    if (A.empty() || B.empty())
        return {};
    int n1 = (int)A.size(), n2 = (int)B.size();
    int need = min(mx + 1, n1 + n2 - 1);
    int n = 1;
    while (n < need)
        n <<= 1;
    vector<cd> fa(n), fb(n);
    for (int i = 0; i < n1 && i < n; i++)
        fa[i] = cd((double)A[i], 0.0);
    for (int i = 0; i < n2 && i < n; i++)
        fb[i] = cd((double)B[i], 0.0);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
        long long v = llround(fa[i].real());
        res[i] = (v > 0 ? 1 : 0);
    }
    return res;
}

vector<int> convolution_exp(vector<int> &base, int pow, int mx) {
    vector<int> res(1, 1);
    while (pow > 0) {
        if (pow & 1)
            res = convolution_fft(res, base, mx);
        pow >>= 1;
        if (!pow)
            break;
        base = convolution_fft(base, base, mx);
    }
    return res;
}

void solve() {
    /*
     * observation: this is convolution over the possible sum of A. Let sum[i] =
     * true if i is contained in A. Then to take K items we just need to get sum
     * ^ K
     */
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int mx = 0, mxA = 0;
    for (auto &x : A) {
        cin >> x;
        mxA = max(mxA, x);
    }
    mx = mxA * K;
    vector<int> sum(mxA + 1, 0);
    for (auto &x : A) {
        sum[x] = true;
    }
    vector<int> ans = convolution_exp(sum, K, mx);
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i] > 0) {
            cout << i << " ";
        }
    }
    cout << '\n';
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
