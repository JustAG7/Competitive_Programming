#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(){
	// co the dung array bang cach nhu sau
	// goi cnt = so luong uoc cua n
	// tao mang[cnt]
	// sau do cho mang[j] = i, mang[j + 1] = n / i
	// roi sort lai bang cach sort(mang,mang + cnt)
	// hoac la dung 2 mang de luu tru neu nhu khong biet sort, vector
	int n;
	cin >> n;
	vector<int> ans;
	for(int i=1;i*i<=n;i++){
		if(n % i == 0){
			ans.push_back(i);
			if(n / i != i) ans.push_back(n / i);
		}
	}
	int sz = ans.size();
	cout << (sz == 3 ? "YES\n" : "NO\n");
	sort(ans.begin(),ans.end());
	for(auto x : ans) cout << x << ' ';
}
int main(){
	fast;
	indef(); // xoa dong nay neu muon tat file
	solve();
}