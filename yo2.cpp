#include <bits/stdc++.h>

using namespace std;
struct Coordinate_Compress{
    map<int,int> comp;
    int cnt=0;
    vector<int> rev;

    void add(int x){
        comp[x];
    }

    void build(){
        cnt=0;
        for(auto& x:comp){
            rev.emplace_back(x.first);
            x.second=cnt++;
        }
    }

    inline int getComp(int x){
        return comp[x];
    }

    inline int getOrg(int x){
        return rev[x];
    }

    int getPrev(int x){
        auto it=comp.upper_bound(x);
        it--;
        return it->second;
    }

    int getNext(int x){
        auto it=comp.lower_bound(x);
        return it->second;
    }
};




struct node{
    int sum,maxr,lazy;
    node(){
        sum=0;
        maxr=0;
        lazy=0;
    }
};

node merge(node l,node r){
    node temp;
    temp.sum=l.sum+r.sum;
    temp.maxr=max(l.maxr,r.maxr);
    return temp;
}

node t[400400],arr[100100];

void push(int idx,int l,int r){
    if(t[idx].lazy!=0){
        t[idx].sum=(r-l+1)*t[idx].lazy;
        t[idx].maxr+=t[idx].lazy;
        if(l!=r){
            t[2*idx].lazy=t[idx].lazy;
            t[2*idx+1].lazy=t[idx].lazy;
        }
        t[idx].lazy=0;
    }
}
void update(int idx,int l,int r,int lq,int rq,int val){
    push(idx,l,r);
    if(l>rq || lq>r)return;
    if(lq<=l && r<=rq){
        t[idx].lazy=val;
        push(idx,l,r);
        return;
    }

    int mid=(l+r)>>1;
    update(idx*2,l,mid,lq,rq,val);
    update(idx*2+1,mid+1,r,lq,rq,val);
}

node query(int idx,int l,int r,int lq,int rq){
    push(idx,l,r);
    if(l>rq || lq>r)return node();
    if(lq<=l && r<=rq)return t[idx];

    int mid=(l+r)/2;
    return merge(query(idx*2,l,mid,lq,rq),query(idx*2+1,mid+1,r,lq,rq));
}


void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
