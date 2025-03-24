#include <bits/stdc++.h>
using namespace std;

// Tên chương trình
const string NAME = "input";
// Số test kiểm tra
const int NTEST = 100;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int Rand(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= 100; iTest++) {
        ofstream inp((NAME + ".inp").c_str());
        int C = Rand(1, 2);
        // Code phần sinh test ở đây
        int n = Rand(1, 1e4); // Random n from 1 to 10^4
        int m = Rand(0, 1e5); // Random m from 1 to n
        int d = Rand(0, 1e5); // Random d <= 10^4
        inp << C << "\n";
        inp << n << " " << m << " " << d << "\n";

        // Generate 2*m pairs in the range [0, n-1]
        for (int i = 0; i < 2 * m; i++) {
            int a = Rand(0, n - 1);
            inp << a << "\n";
        }

        inp.close();

        // Nếu dùng Linux thì "./" + Tên chương trình
        system("F.exe");
        system("F_debug.exe");
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
