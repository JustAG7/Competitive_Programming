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

string tong(string a,string b){
	string ans="";
	while(a.size()<b.size()) a="0"+a;
	while(b.size()<a.size()) b="0"+b;
	int n=a.size()-1,digit,nb=0;
	for(int i=n;i>=0;i--){
		int digit=int(a[i]-'0') + int(b[i]-'0') + nb;
		ans=char(digit%10 + '0') + ans;
		nb=digit/10;
	}
	if(nb>0) ans=char(nb + '0') + ans;
	return ans;
}
int main(){
	fast;
	indef();
	int n;
	cin >> n;
	string a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	string ans="";
	for(int i=0;i<n;i++){
		string s=a[i];
		if(int(s[s.size()-1]-'0') % 2!=0) ans=tong(ans,s);
	}
	cout << ans;
}