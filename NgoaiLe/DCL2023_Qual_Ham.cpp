#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

const int N = 1e7;
int phi[N + 5];
int x = 0, y = 0;

void indef(){
    #define JA "input"
    if(fopen(JA ".txt", "r")){
        freopen(JA ".txt","r",stdin);
        freopen("output.txt","w",stdout);  
    }
}

void initialize_phi() {
    for (int i = 2; i <= N; i++)
        phi[i] = i;

    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    phi[0] = 0;
    phi[1] = 0;
}

int f(int n) {
    if(n <= 1) return 0;
    if(n <= N) return phi[n];
    assert(n <= N);
    return 0;
}

int ff(int x, int y) {
    int ans = f(x);
    int res = ans;
    for (int i = 1; i < y ; ++i) {
        ans = 2 * f(ans);
        if(ans == res) return ans;
        res = ans;
    }

    return ans;
}

int fff(int x, int y) {
    return x + y;
}

int eval(string s);

int eval(string s) {
    if (s.empty()) return 0;
    if (s == "x") return x;
    if (s == "y") return y;
    
    string left = "";
    string right = "";
    string fun = "";
    int pos = 0;
    
    // Get function name
    for (int i = pos; i < s.size(); ++i) {
        if (s[i] == '(') {
            pos = i + 1;
            break;
        }
        fun += s[i];
    }
    
    // Get first argument
    if (s[pos] != 'f') {
        for (int i = pos; i < s.size(); ++i) {
            if (s[i] == ',') {
                pos = i;
                break;
            }
            left += s[i];
        }
    } else {
        int stack = 0;
        for (int i = pos; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack += 1;
            } else if (s[i] == ')') {
                stack -= 1;
                if (stack == 0) {
                    left += ')';
                    pos = i + 1;
                    break;
                }
            }
            left += s[i];
        }
    }
    
    // Get second argument, if present
    bool check = s[pos] == ',';
    if (check) {
        int stack = 0;
        for (int i = pos + 1; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack += 1;
            } else if (s[i] == ')') {
                stack -= 1;
                if (stack == 0) {
                    right += ')';
                    pos = i + 1;
                    break;
                }
            }
            right += s[i];
        }
    } else {
        left.pop_back();
        int stack = 0;
        for(int i=0;i<left.size();i++){
            if(left[i] == '(') stack++;
            else if(left[i] == ')'){
                if(stack == 0) left.push_back(')');
                else stack--;
            }
        }
        while(stack--) left.push_back(')');
    }
    if (!right.empty() && right[0] != 'f') {
        right.pop_back();
    }

    // evaluate
    if (right.empty()) {
        return f(eval(left));
    } else {
        if (fun == "ff") {
            return ff(eval(left), eval(right));
        } else {
            return fff(eval(left), eval(right));
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    indef();
    int t;
    cin >> t;
    
    initialize_phi();
    while (t--) {
        string a, b, func;
        cin >> a >> b >> func;
        while(cin >> a){
            if(a[a.size() - 1] == ';') break;
        }
        while(cin >> b){
            if(b[b.size() - 1] == ';') break;
        }
        while(cin >> func){
            if(func[func.size() - 1] == ';') break;
        }
        a.pop_back();
        b.pop_back();
        func.pop_back();
        x = stoi(a);
        y = stoi(b);
        
        cout << eval(func) << '\n';
    }
    
}