#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	fast;
	indef();
	int h,m;
	cin >> h >> m;
	int a=h/10,b=h%10,c=m/10,d=m%10;
	int nh=a*10+c,nm=b*10+d;
	if(nh>23 && h==23) cout << "00 00";
	else if(nh>23 || nm>59){
		if(h>=6 && h<=9) cout << "10 00";
		else if(h>=16 && h<=19) cout << "20 00";
		else{
			if(h<10) cout << 0 << h+1 << " 00";
			else cout << h+1 << " 00";
		}
	}
	else {
		if(h<10) cout << 0 << h << ' ';
		else cout << h << ' ';
		if(m<10) cout << 0 << m << ' ';
		else cout << m;
	}
}