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

const int M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n,k,ans=0,tmp;
	cin >> n >> k;
	vector<int> a(6,0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a[x % k]++;
	}
	/* k=4
		2 phan tu:
		1.a[1]+a[3]
		2.a[2]+a[2]
		3 phan tu:
		1.a[1]+a[1]+a[2] (neu a[1]>a[3])
		2.a[3]+a[3]+a[2] (neu a[3]>a[1])
		4 phan tu (luon het a[2] khi cong 3 phan tu):
		a[1]*4
		a[3]*4
 	*/
 	// neu x % k ==0 thi cong vao khong can tinh toan
	ans+=a[0];
	if(k==4){
		//2 phan tu
		tmp=min(a[1],a[3]);
		a[1]-=tmp;a[3]-=tmp;ans+=tmp;
		tmp=a[2]/2;
		a[2]-=tmp*2;ans+=tmp;
		//3 phan tu
		tmp=min(a[1]/2,a[2]);
		a[1]-=tmp*2;a[2]-=tmp;ans+=tmp;
		tmp=min(a[3]/2,a[2]);
		a[3]-=tmp*2;a[2]-=tmp;ans+=tmp;
		//4 phan tu
		ans+=a[1]/4;
		ans+=a[3]/4;
	}
	/*
		k==5
		2 phan tu:
		a[1]+a[4]
		a[2]+a[3]
		3 phan tu (luon phu thuoc vao 2 phan tu ma xay ra cac TH sau, chi xay ra duy nhat 1 TH)
		1.a[1]+a[1]+a[3] 
		2.a[1]+a[2]+a[2]  
		3.a[2]+a[4]+a[4]  
		4.a[3]+a[3]+a[4]    
		4 phan tu (luon phu thuoc vao 3 phan tu ma xay ra cac TH sau, chi xay ra duy nhat 1 TH)
		1.a[1]+a[1]+a[1]+a[2] 
		2.a[1]+a[3]+a[3]+a[3] 
		3.a[4]+a[4]+a[4]+a[3] 
		4.a[2]+a[2]+a[2]+a[4]
		5.a[1]+a[1]+a[4]+a[4] //TH nay ko xay ra dau 
		6.a[2]+a[2]+a[3]+a[3] //TH nay ko xay ra dau (de dam thang cop code)

		5 phan tu (tinh lai cho chac :v)
		a[1]*5
		a[2]*5
		a[3]*5
		a[4]*5
	*/
	else{
		//2 phan tu
		tmp=min(a[1],a[4]);
		a[1]-=tmp;a[4]-=tmp;ans+=tmp;
		tmp=min(a[2],a[3]);
		a[2]-=tmp;a[3]-=tmp;ans+=tmp;
		//3 phan tu
		tmp=min(a[1]/2,a[3]);
		a[1]-=tmp*2;a[3]-=tmp;ans+=tmp;
		tmp=min(a[1],a[2]/2);
		a[1]-=tmp;a[2]-=tmp*2;ans+=tmp;
		tmp=min(a[2],a[4]/2);
		a[2]-=tmp;a[4]-=tmp*2;ans+=tmp;
		tmp=min(a[3]/2,a[4]);
		a[3]-=tmp*2;a[4]-=tmp;ans+=tmp;
		//4 phan tu
		tmp=min(a[1]/3,a[2]);
		a[1]-=tmp*3;a[2]-=tmp;ans+=tmp;
		tmp=min(a[1],a[3]/3);
		a[3]-=tmp*3;a[1]-=tmp;ans+=tmp;
		tmp=min(a[3],a[4]/3);
		a[4]-=tmp*3;a[3]-=tmp;ans+=tmp;
		tmp=min(a[2]/2,a[4]/2);
		a[2]-=tmp*2;a[4]-=tmp*2;ans+=tmp;

		//5 phan tu
		ans+=a[1]/5;
		ans+=a[2]/5;
		ans+=a[3]/5;
		ans+=a[4]/5;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}