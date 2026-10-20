#include "my_template.hpp"
#include "other/io.hpp"

unsigned __int128 sqrt128(unsigned __int128 n) {
	unsigned __int128 res = 0;
	unsigned __int128 bit = (unsigned __int128)1 << 126;

	while (bit > n) {
		bit >>= 2;
	}

	while (bit != 0) {
		if (n >= res + bit) {
			n -= res + bit;
			res = (res >> 1) + bit;
		} else {
			res >>= 1;
		}
		bit >>= 2;
	}
	return res;
}

void solve() {
	// a(n) = ((t*t+3*t+4)/2-n)*(n-(t*(t+1)/2)), where t=floor((-1+sqrt(8*n-7))/2) (oeis A003991)
	LL(N);
	VEC(ll, A, N);
	VEC(ll, B, N);
	vc<i128> multiply(N + 1);
	i128 base = (i128(N) - 1) * N / 2;
	FOR(i, 1, N + 1) {
		i128 t = (-1 + sqrt128(i128(8) * (base + i) - 7)) / 2;
		multiply[i] = ((t * t + 3 * t + 4) / 2 - (base + i)) * ((base + i) - (t * (t + 1) / 2));
		A[i - 1] *= multiply[i];
	}
	sort(all(A));
	sort(all(B), greater<ll>());
	i128 ANS = 0;
	FOR(i, N) {
		ANS += A[i] * B[i];
	}
	print(ANS);
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t = 1;
	// INT(t);
	FOR(t)
	solve();

	return 0;
}
