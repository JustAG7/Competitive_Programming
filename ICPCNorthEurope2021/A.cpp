#include<iostream>
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


void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void solve(){
    string c="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string tmp="a";
    string ans="";
    ll time=0,i=0,j=0;
    bool len=false;
    cout << tmp << nl << nl;
    while(true){
        ll ttime=0;
        string s1,s2,s3;
        cin >> s1 >> s2;
        if(s2=="GRANTED") break;
        else{
            getline(cin,s3);
            for(ll i=2;i<s3.size();i++){
                if(s3[i]==' ') break;
                ll lt=s3[i]-'0';
                ttime=ttime*10+lt;
            }
        }
        if(!len){
            if(ttime>=time){
                tmp+='a';
                time=ttime;
            }
            else{
                len=true;
                tmp=tmp.substr(0,tmp.size()-1);
            }
            cout << tmp << nl << nl;
            continue;
        }
        else{
            if(ttime>time){
                i++;
                j=0;
                time=ttime;
            }
            else{
                tmp[i]=c[j];
                j++;
            }
        }
        cout << tmp << nl << nl;
    }
}
int main(){
    //fast;
    indef();
    ll tt=1;
    while(tt--) solve();
}