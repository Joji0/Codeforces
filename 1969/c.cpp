#include <bits/stdc++.h>
using namespace std;
int n,k;
int64_t dp[1<<20][11];
template <class T> struct SparseTable {
        int N = 0, LOG = 25;
        vector<vector<T>> st;
        T f(const T &a, const T &b) const { return min(a, b); }
        void init(const vector<T> &A) {
                N = (int)A.size();
                st.assign(LOG, vector<T>(N));
                for (int j = 0; j < N; j++) st[0][j] = A[j];
                for (int i = 1; i < LOG; i++) {
                        for (int j = 0; j + (1LL << i) - 1 < N; j++) {
                                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
                        }
                }
        }
        T query(int L, int R) const {
                int len = R - L + 1;
                int lg = (int)log2(len);
                return f(st[lg][L], st[lg][R - (1 << lg) + 1]);
        }
};
void solve() 
{
        cin>>n>>k;
        vector<int64_t>a(n);for(auto&x:a)cin>>x;
        SparseTable<int64_t> st;
        st.init(a);
        for(int i=0;i<=n;i++)
                for(int j=0;j<=k;j++)
                        dp[i][j]=1LL<<60;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
                for(int j=0;j<=k;j++)
                {
                        for(int len=1;len-1<=j&&len<=i;len++)
                        {
                                dp[i][j]=min(dp[i][j],dp[i-len][j-(len-1)]+len*st.query(i-len,i-1));
                        }
                }
        }
        int64_t ans=1LL<<60;
        for(int i=0;i<=k;i++)ans=min(ans,dp[n][i]);
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
