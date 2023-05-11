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

/*
	Sum of 2 any bignum
	Author: JustA
	Time: 18:07:23 Thursday 10/11/2022
*/
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
string hieu(string a,string b){
	string ans="";
	while(a.size()<b.size()) a="0"+a;
	while(b.size()<a.size()) b="0"+b;
	int nb=0,digit,n=a.size()-1;
	for(int i=n;i>=0;i--){
		int digit=int(a[i]-'0') - int(b[i]-'0') -nb;
		if(digit<0){
			digit+=10;
			nb=1;
		}
		else nb=0;
		ans=char(digit + '0') + ans;
	}
	while(ans[0]=='0') ans.erase(ans.begin());
	return ans;
}
int main(){
	fast;
	indef();
	string a,b;
	cin >> a >> b;
	//cout << a.substr(1,a.size());
	if(a[0]!='-' && b[0]!='-'){
		cout << tong(a,b);
		return 0;
	}
	if(a[0]=='-' && b[0]=='-'){
		a=a.substr(1,a.size());
		b=b.substr(1,b.size());
		cout << '-' << tong(a,b);
		return 0;
	}
	if(a[0]=='-') swap(a,b);
	b=b.substr(1,b.size());
	if(a==b){
		cout << 0;
		return 0;
	}
	if(a>b) cout << hieu(a,b);
	else{
		swap(a,b);
		cout << "-" << hieu(a,b);
	}
}