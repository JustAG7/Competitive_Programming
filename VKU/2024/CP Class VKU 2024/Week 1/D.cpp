#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
    #define JA "input"
    if(fopen(JA ".inp", "r")){
        freopen(JA ".inp","r",stdin);
        freopen(JA ".out","w",stdout);  
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> a, b;
    vector<int> c(n);
    for(int &x : c) cin >> x;
   	for(int i=0;i<n;i++){
   		if(a.size() && b.size() && a.back() >= c[i] && b.back() >= c[i]){
   			if(a.back() < b.back()) a.pb(c[i]);
   			else b.pb(c[i]);
   			continue;
   		}
   		if(!a.size()) a.pb(c[i]);
   		else{
   			if(a.back() >= c[i]) a.pb(c[i]);
   			else {
   				if(!b.size()){
   					b.pb(c[i]);
   					continue;
   				}
   				if(b.back() >= c[i]) b.pb(c[i]);
   				else{
   					if(a.back() > b.back()) b.pb(c[i]);
   					else a.pb(c[i]);
   				}
   			}
   		}
   	}
    int ans = 0;
    if(a.size() >= 2){
        for(int i=0;i<a.size()-1;i++){
            ans += (a[i] < a[i + 1]);
        }
    }
    if(b.size() >= 2){
        for(int i=0;i<b.size()-1;i++){
            ans += (b[i] < b[i + 1]);
        }
    }
    cout << ans;
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
