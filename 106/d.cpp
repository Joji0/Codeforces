#include <bits/stdc++.h>
using namespace std;

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
        for (auto &x : v) in >> x;
        return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
        for (auto &x : v) out << x << ' ';
        return out;
}
template <typename T> istream &operator>>(istream &in, vector<vector<T>> &vv) {
        for (auto &v : vv) in >> v;
        return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<vector<T>> &vv) {
        for (const auto &v : vv) out << v << '\n';
        return out;
}
template <typename T> void print(const vector<T> &v) {
        for (auto &x : v) cout << x << " ";
        cout << '\n';
}
template <typename T> void _print(const T &x) { cerr << x; }
template <typename T> void _print(const vector<T> &v) {
        cerr << '[';
        bool first = true;
        for (const auto &x : v) {
                if (!first) cerr << ", ";
                first = false;
                _print(x);
        }
        cerr << ']';
}
template <typename T> void _print(const vector<vector<T>> &vv) {
        cerr << "DEBUG:\n[\n";
        for (const auto &v : vv) {
                cerr << "  ";
                _print(v);
                cerr << '\n';
        }
        cerr << "]\n";
}
template <typename A, typename B> void _print(const pair<A, B> &p) {
        cerr << "(";
        _print(p.first);
        cerr << ", ";
        _print(p.second);
        cerr << ")";
}
template <typename T, size_t N> void _print(const array<T, N> &a) {
        cerr << "[";
        for (size_t i = 0; i < N; i++) {
                _print(a[i]);
                if (i + 1 < N) cerr << ", ";
        }
        cerr << "]";
}
template <typename T, size_t N> void _print(const T (&a)[N]) {
        cerr << "[";
        for (size_t i = 0; i < N; i++) {
                _print(a[i]);
                if (i + 1 < N) cerr << ", ";
        }
        cerr << "]";
}
template <typename T> void _print(const set<T> &s) {
        cerr << "{";
        bool first = true;
        for (auto &x : s) {
                if (!first) cerr << ", ";
                first = false;
                _print(x);
        }
        cerr << "}";
}
template <typename T> void _print(const multiset<T> &s) {
        cerr << "{";
        bool first = true;
        for (auto &x : s) {
                if (!first) cerr << ", ";
                first = false;
                _print(x);
        }
        cerr << "}";
}
template <typename K, typename V> void _print(const map<K, V> &m) {
        cerr << "{";
        bool first = true;
        for (auto &p : m) {
                if (!first) cerr << ", ";
                first = false;
                _print(p);
        }
        cerr << "}";
}
template <typename K, typename V> void _print(const unordered_map<K, V> &m) {
        cerr << "{";
        bool first = true;
        for (auto &p : m) {
                if (!first) cerr << ", ";
                first = false;
                _print(p);
        }
        cerr << "}";
}
template <typename T> void _print(const deque<T> &dq) {
        cerr << "dq(";
        for (int i = 0; i < dq.size(); i++) {
                _print(dq[i]);
                if (i + 1 < dq.size()) cerr << ", ";
        }
        cerr << ")";
}
template <typename T> void _print(queue<T> q) {
        cerr << "q(";
        bool first = true;
        while (!q.empty()) {
                if (!first) cerr << ", ";
                first = false;
                _print(q.front());
                q.pop();
        }
        cerr << ")";
}
template <typename T> void _print(stack<T> st) {
        cerr << "st(";
        bool first = true;
        vector<T> temp;
        while (!st.empty()) {
                temp.push_back(st.top());
                st.pop();
        }
        reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++) {
                if (!first) cerr << ", ";
                first = false;
                _print(temp[i]);
        }
        cerr << ")";
}
template <typename T> void _print(priority_queue<T> pq) {
        cerr << "pq(";
        bool first = true;
        while (!pq.empty()) {
                if (!first) cerr << ", ";
                first = false;
                _print(pq.top());
                pq.pop();
        }
        cerr << ")";
}
template <typename T> void _print(priority_queue<T, vector<T>, greater<T>> pq) {
        cerr << "minpq(";
        bool first = true;
        while (!pq.empty()) {
                if (!first) cerr << ", ";
                first = false;
                _print(pq.top());
                pq.pop();
        }
        cerr << ")";
}
template <typename T> bool chmax(T &a, const T &b) {
        if (a < b) {
                a = b;
                return true;
        }
        return false;
}
template <typename T> bool chmin(T &a, const T &b) {
        if (b < a) {
                a = b;
                return true;
        }
        return false;
}
template <typename T> void offset(T o, vector<T> &x) {
        for (auto &a : x) a += o;
}
#define CLR_RESET "\033[0m"
#define CLR_BOLD "\033[1m"
#define CLR_CYAN "\033[36m"
#define CLR_YELLOW "\033[33m"
#define CLR_DIM "\033[2m"
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void debug_impl(const char *name, T &&value) {
        cerr << CLR_BOLD << CLR_CYAN << name << CLR_RESET << " = " << CLR_YELLOW;
        _print(value);
        cerr << CLR_RESET << '\n';
}
template <typename T, typename... Args> void debug_impl(const char *names, T &&value, Args &&...args) {
        const char *comma = strchr(names, ',');
        cerr << CLR_BOLD << CLR_CYAN;
        cerr.write(names, comma - names);
        cerr << CLR_RESET << " = " << CLR_YELLOW;
        _print(value);
        cerr << CLR_RESET << " " << CLR_DIM << "| " << CLR_RESET;
        debug_impl(comma + 1, args...);
}
#ifndef ONLINE_JUDGE
#define IOJUDGE(title) freopen(title ".in", "r", stdin), freopen(title ".out", "w", stdout)
#else
#define IOJUDGE(title)
#endif
inline int popcnt64(int64_t x) { return __builtin_popcountll(x); }
inline int safe_ctz64(int64_t x) { return x ? __builtin_ctzll(x) : 64; }
inline int safe_clz64(int64_t x) { return x ? __builtin_clzll(x) : 64; }
inline int64_t lsone64(int64_t x) { return x & -x; }
inline int64_t msbone64(int64_t x) { return 1LL << (63 - __builtin_clzll(x)); }
inline bool ispow2_64(int64_t x) { return x && !(x & (x - 1)); }
inline int popcnt32(int x) { return __builtin_popcount(x); }
inline int safe_ctz32(int x) { return x ? __builtin_ctz(x) : 32; }
inline int safe_clz32(int x) { return x ? __builtin_clz(x) : 32; }
inline int lsone32(int x) { return x & -x; }
inline int msbone32(int x) { return 1 << (31 - __builtin_clz(x)); }
inline bool ispow2_32(int x) { return x && !(x & (x - 1)); }
template <class Fun> struct y_combinator_result {
        Fun fun;
        template <class T> explicit y_combinator_result(T &&fun) : fun(std::forward<T>(fun)) {}

        template <class... Args> decltype(auto) operator()(Args &&...args) {
                return fun(std::ref(*this), std::forward<Args>(args)...);
        }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T, int NDIMS> struct Tensor_view {
        static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

      protected:
        std::array<int, NDIMS> shape;
        std::array<int, NDIMS> strides;
        T *data;
        Tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T *data_)
            : shape(shape_), strides(strides_), data(data_) {}

      public:
        Tensor_view() : shape{0}, strides{0}, data(nullptr) {}

      protected:
        int flatten_index(std::array<int, NDIMS> idx) const {
                int res = 0;
                for (int i = 0; i < NDIMS; i++) {
                        res += idx[i] * strides[i];
                }
                return res;
        }
        int flatten_index_checked(std::array<int, NDIMS> idx) const {
                int res = 0;
                for (int i = 0; i < NDIMS; i++) {
                        assert(0 <= idx[i] && idx[i] < shape[i]);
                        res += idx[i] * strides[i];
                }
                return res;
        }

      public:
        T &operator[](std::array<int, NDIMS> idx) const {
#ifdef _GLIBCXX_DEBUG
                return data[flatten_index_checked(idx)];
#else
                return data[flatten_index(idx)];
#endif
        }
        T &at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }
        template <int D = NDIMS>
        typename std::enable_if<(0 < D), Tensor_view<T, NDIMS - 1>>::type operator[](int idx) const {
                std::array<int, NDIMS - 1> nshape;
                std::copy(shape.begin() + 1, shape.end(), nshape.begin());
                std::array<int, NDIMS - 1> nstrides;
                std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
                T *ndata = data + (strides[0] * idx);
                return Tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
        }
        template <int D = NDIMS> typename std::enable_if<(0 < D), Tensor_view<T, NDIMS - 1>>::type at(int idx) const {
                assert(0 <= idx && idx < shape[0]);
                return operator[](idx);
        }
        template <int D = NDIMS> typename std::enable_if<(0 == D), T &>::type operator*() const { return *data; }
        template <typename U, int D> friend struct Tensor_view;
        template <typename U, int D> friend struct Tensor;
};

template <typename T, int NDIMS> struct Tensor {
        static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

      protected:
        std::array<int, NDIMS> shape;
        std::array<int, NDIMS> strides;
        int len;
        T *data;

      public:
        Tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}
        explicit Tensor(std::array<int, NDIMS> shape_, const T &t = T()) {
                shape = shape_;
                len = 1;
                for (int i = NDIMS - 1; i >= 0; i--) {
                        strides[i] = len;
                        len *= shape[i];
                }
                data = new T[len];
                std::fill(data, data + len, t);
        }
        Tensor(const Tensor &o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
                for (int i = 0; i < len; i++) {
                        data[i] = o.data[i];
                }
        }
        Tensor &operator=(Tensor &&o) noexcept {
                using std::swap;
                swap(shape, o.shape);
                swap(strides, o.strides);
                swap(len, o.len);
                swap(data, o.data);
                return *this;
        }
        Tensor(Tensor &&o) : Tensor() { *this = std::move(o); }
        Tensor &operator=(const Tensor &o) { return *this = Tensor(o); }
        ~Tensor() { delete[] data; }
        using view_t = Tensor_view<T, NDIMS>;
        view_t view() { return Tensor_view<T, NDIMS>(shape, strides, data); }
        operator view_t() { return view(); }
        using const_view_t = Tensor_view<const T, NDIMS>;
        const_view_t view() const { return Tensor_view<const T, NDIMS>(shape, strides, data); }
        operator const_view_t() const { return view(); }
        T &operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
        T &at(std::array<int, NDIMS> idx) { return view().at(idx); }
        const T &operator[](std::array<int, NDIMS> idx) const { return view()[idx]; }
        const T &at(std::array<int, NDIMS> idx) const { return view().at(idx); }
        template <int D = NDIMS> typename std::enable_if<(0 < D), Tensor_view<T, NDIMS - 1>>::type operator[](int idx) {
                return view()[idx];
        }
        template <int D = NDIMS> typename std::enable_if<(0 < D), Tensor_view<T, NDIMS - 1>>::type at(int idx) {
                return view().at(idx);
        }
        template <int D = NDIMS>
        typename std::enable_if<(0 < D), Tensor_view<const T, NDIMS - 1>>::type operator[](int idx) const {
                return view()[idx];
        }
        template <int D = NDIMS>
        typename std::enable_if<(0 < D), Tensor_view<const T, NDIMS - 1>>::type at(int idx) const {
                return view().at(idx);
        }
        template <int D = NDIMS> typename std::enable_if<(0 == D), T &>::type operator*() { return *view(); }
        template <int D = NDIMS> typename std::enable_if<(0 == D), const T &>::type operator*() const {
                return *view();
        }
};

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct Info {
        int x, y, step;
        char from;
};

void solve() {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> grid(N, vector<char>(M));
        vector<Info> source;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        cin >> grid[i][j];
                        if ('A' <= grid[i][j] && grid[i][j] <= 'Z') {
                                source.push_back({i, j, 0, grid[i][j]});
                        }
                }
        }
        Tensor<int, 2> pref_row({N, M + 1}, 0), pref_col({N + 1, M}, 0);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        pref_row[{i, j + 1}] = pref_row[{i, j}] + (grid[i][j] == '#');
                        pref_col[{i + 1, j}] = pref_col[{i, j}] + (grid[i][j] == '#');
                }
        }
        int K;
        cin >> K;
        auto conv = [](const char &ch) -> int {
                switch (ch) {
                case 'E':
                        return 0;
                case 'S':
                        return 1;
                case 'W':
                        return 2;
                case 'N':
                        return 3;
                default:
                        assert(false);
                }
        };
        vector<array<int, 2>> instr(K);
        for (int i = 0; i < K; i++) {
                char ch;
                int len;
                cin >> ch >> len;
                instr[i][0] = conv(ch), instr[i][1] = len;
        }
        queue<Info> q;
        for (Info &info : source) {
                q.push(info);
        }
        auto blocked_row = [&](int x, int l, int r) -> bool {
                if (l > r) return 0;
                return (pref_row[{x, r + 1}] - pref_row[{x, l}] > 0);
        };
        auto blocked_col = [&](int y, int l, int r) -> bool {
                if (l > r) return 0;
                return (pref_col[{r + 1, y}] - pref_col[{l, y}] > 0);
        };
        vector<int> ans(26, 0);
        while (!q.empty()) {
                auto [x, y, step, from] = q.front();
                // debug(x, y, step, from);
                q.pop();
                if (step >= K) {
                        ans[from - 'A']++;
                        continue;
                }
                int facing = instr[step][0], len = instr[step][1];
                int nx = x + dx[facing] * len, ny = y + dy[facing] * len;
                bool ok = true;
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                        ok = false;
                } else {
                        if (facing == 0) {
                                ok &= (!blocked_row(x, y + 1, y + len));
                        } else if (facing == 1) {
                                ok &= (!blocked_col(y, x + 1, x + len));
                        } else if (facing == 2) {
                                ok &= (!blocked_row(x, y - len, y - 1));
                        } else {
                                ok &= (!blocked_col(y, x - len, x - 1));
                        }
                }
                if (ok) {
                        q.push({x + dx[facing] * len, y + dy[facing] * len, step + 1, from});
                }
        }
        bool ok = false;
        for (int i = 0; i < 26; i++) {
                if (ans[i]) {
                        cout << (char)(i + 'A');
                        ok = true;
                }
        }
        if (!ok) {
                cout << "no solution";
        }
        cout << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
