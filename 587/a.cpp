#include <bits/stdc++.h>
using namespace std;

void solve() {
        int A[1000069],N,ans=0,x;cin>>N;
        memset(A,0,4*1000069);
        for(int i=0;i<N;i++){cin>>x;A[x]++;}
        for(int i=0;i<1000068;i++){
                A[i+1]+=A[i]/2;A[i]%=2;
                if(A[i]&1){
                        ans++;
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
