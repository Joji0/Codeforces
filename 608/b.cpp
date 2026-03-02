#include <bits/stdc++.h>
using namespace std;

int64_t pref[200005];

void solve() {
        string a,b;cin>>a>>b;
        int N=(int)a.size(),M=(int)b.size(),R=M-N;
        int64_t ans=0;
        assert(N<=M);
        pref[0]=b[0]-'0';
        for(int i=1;i<M;i++){
                pref[i]=pref[i-1]+(b[i]-'0');
        }
        for(int i=0;i<N;i++){
                if(a[i]-'0'){
                        ans+=R+1-(pref[i+R]-(i?pref[i-1]:0)); 
                }else{
                        ans+=pref[i+R]-(i?pref[i-1]:0);
                }
        }
        cout<<ans<<'\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
