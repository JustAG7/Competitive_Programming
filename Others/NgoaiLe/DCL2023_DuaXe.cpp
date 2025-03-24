#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define vi vector<int> 
#define vvi vector<vector<int>> 

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

db lengthCircle(db k, db a, db b) {
    db integral = 0.0;
    db dx = 0.0001;
    db x = a;
    while (x < b) {
        db f1 = sin(k*x);
        db f2 = sin(k*(x+dx));
        db df = (f2 - f1) / dx;
        integral += sqrt(1 + df*df) * dx;
        x += dx;
    }
    return integral;
}
db lengthTriangle(db d,db w, db h){
	db t = d/(w/2);
	h*=t;
	return sqrt(pow(d,2)+pow(h,2));
}
void solve(){
	db d,k,h,w,va,vb;
	cin >> d >> k >> h >> w >> va >> vb;
	db x = lengthCircle(k,0,d);
	db y = lengthTriangle(d,w,h);
	if(x/va<y/vb) cout << "PIP";
	else cout << "POSY";
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}
