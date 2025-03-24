#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
int main(){
    ll p,n;
    cin >> p >> n;
    ll num = 0;
    for(int i=1;i<=N;i++){
        num = (num*10 + 9) % p;
        if(num == 0){
            cout << n/i;
            return 0;
        }
    }
    cout << 0;
}
