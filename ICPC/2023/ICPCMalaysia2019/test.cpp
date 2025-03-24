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

void indef(){
	#ifndef OnLInE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n;
	string s;
	cin >> n >> s;
	char a[n][n];
	char r[8]={'>','v','<','^','>','v','<','^'};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	int rn=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='R') rn++;
		else rn+=3;
	}
	rn%=4;
    if(rn!=0){
	    for(int k=0;k<rn;k++){
		    for (int i = 0; i < n / 2; i++) {
        	for (int j = i; j < n - i - 1; j++) {
            char temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = temp;
        }
    }
	    }
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char x=a[i][j];
				if(x=='.'){
					cout << '.';
					continue;
				}
				for(int k=0;k<8;k++){
					if(x==r[k]){
						cout << r[k+rn];
						break;
					}
				}
			}
			cout << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}