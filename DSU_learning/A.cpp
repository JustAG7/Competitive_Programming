#include <bits/stdc++.h>
using namespace std;

int a[100005],n,m;
struct DSU{
    vector<int> par,sz,mx;
    DSU(int n) : par(n),sz(n),mx(n) {};
    
    void make_set(int n){
        par[n]=n;
        sz[n]=1;
        mx[n]=a[n];
    }
    
    int find_set(int n){
        return n == par[n] ? n : par[n] = find_set(par[n]);
    }
    
    void union_set(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
            mx[a]=max(mx[a],mx[b]);
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    DSU g(n+5);
    for(int i=1;i<=n;i++) g.make_set(i);
    for(int i=0;i<m;i++){
        string s;int a,b;
        cin >> s >> a >> b;
        if(s=="union") g.union_set(a,b);
        else cout << ((g.find_set(a)!=g.find_set(b)) ? "NO\n" : "YES\n");
    }
}
