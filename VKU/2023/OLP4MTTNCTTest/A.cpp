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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=1e5+5;

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
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> a(n+1);
	vector<ll> b(n+1,0);
	b[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1') a[i]++;
		else a[i]--;
	}
	for (int i=1;i<=n;i++){
        ll sum=0;
        for (int j=i;j<=n;j++){
            sum+=a[j];
            if (sum<=k && sum>=-k)
            b[j]=(b[j]+b[i-1])%M;;
        }
    }
    cout << b[n]%M;
}
