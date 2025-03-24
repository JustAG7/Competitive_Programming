#include<bits/stdc++.h>
#define inf INT_MAX
#define re register
#define pii pair<int,int>
#define mk make_pair
#define ls ((p)<<1)
#define rs (((p)<<1)|1)
#define mid ((l+r)>>1)
#define lowbit(x) ((x)&(-(x)))
#define si short int
#define ll long long
#define maxn -1
#define maxm -1
#define mod 0
using namespace std;
int T;
int n,m;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cout<<1<<'\n';
    cout<<200000<<'\n';
    int tmp = 1e9-1;
    for(re int j=1;j<=100000;++j){
        cout<<tmp+1<<' '<<tmp;
        if(j!=100000)cout<<' ';
        tmp-=2;
    }
    cout<<'\n';
    return 0;
}
