#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,D,arr[100100];
map<int,int> comp;

int t[400400];

void update(int idx,int l,int r,int pos,int val){
    if(pos<l || pos>r)return;
    if(l==r){
        t[idx]=max(t[idx],val);
        return;
    }
    int mid=(l+r)/2;
    update(idx*2,l,mid,pos,val);
    update(idx*2+1,mid+1,r,pos,val);
    t[idx]=max(t[2*idx],t[2*idx+1]);
}

int query(int idx,int l,int r,int lq,int rq){
    if(l>rq || lq>r)return 0;
    if(lq<=l && r<=rq)return t[idx];

    int mid=(l+r)/2;
    return max(query(idx*2,l,mid,lq,rq),query(idx*2+1,mid+1,r,lq,rq));
}

void solve() {
    cin>>n>>D;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        comp[arr[i]];
    }

    int cnt=0;
    for(auto& x:comp){
        x.second=cnt++;
    }

    int dp[n];
    int ans=0;
    for(int i=0;i<n;i++){
        int lo=arr[i]-D;
        int hi=arr[i]+D;

        auto it=comp.upper_bound(hi);
        it--;hi=it->second;

        it=comp.lower_bound(lo);
        lo=it->second;

        dp[i]=query(1,0,cnt,lo,hi)+1;
        ans=max(ans,dp[i]);
        update(1,0,cnt,comp[arr[i]],dp[i]);
    }

    cout<<ans<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t=1;
    cin>>t;

    while(t--)solve();

    return 0;
}