#include <cstdio>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>

typedef long long ll;
namespace std {
  namespace tr1 {

    template<typename a, typename b>
      struct hash< std::pair<a, b> > {
        private:
          const hash<a> ah;
          const hash<b> bh;
        public:
          hash() : ah(), bh() {}
          size_t operator()(const std::pair<a, b> &p) const {
            size_t bb = bh(p.second);
            return ah(p.first) ^ (bb << 3) ^ bb;
          }
      };

    template<typename a>
      struct hash< std::vector<a> > {
        private:
          const hash<a> ah;
        public:
          hash() : ah() {}
          size_t operator()(const std::vector<a> &p) const {
            size_t ret = 0;
            for (auto it = p.begin(); it != p.end(); ++it) {
              ret = (ret << 3) ^ ret;
              ret ^= ah(*it);
            }
            return ret;
          }
      };

  }}

using namespace std;
using namespace std::tr1;

bool Check3A(int r, int c, int x1, int y1, int x2, int y2) {
  int c1 = (x1 + y1) % 2;
  int c2 = (x2 + y2) % 2;
  if (c1 == 1 && c2 == 0) {
    if (y1 == 2 && x1 < x2) return true;
    if (y1 != 2 && x1 < x2 - 1) return true;
  }
  return false;
}

bool Check3(int r, int c, int x1, int y1, int x2, int y2) {
  if (r != 3) return false;
  if (c % 2 != 0) return false;
  return Check3A(r, c, x1, y1, x2, y2) ||
         Check3A(r, c, x2, y2, x1, y1) ||
         Check3A(r, c, c - x1 + 1, y1, c - x2 + 1, y2) ||
         Check3A(r, c, c - x2 + 1, y2, c - x1 + 1, y1);
}

int upper(int r, int c, int x1, int y1, int x2, int y2) {
  if (r > c) {
    return upper(c, r, y1, x1, y2, x2);
  }
  if (r == 1) return abs(x1 - x2) + 1;
  if (r == 2 && (abs(x1 - x2) <= 1) && y1 != y2) {
    return max(x1+x2, 2*c - x1 - x2 + 2); 
  }
  int c1 = (x1 + y1) % 2;
  int c2 = (x2 + y2) % 2;
  bool con3 = Check3(r, c, x1, y1, x2, y2);

  if (r*c % 2 == 0 && c1 != c2 && con3 == false) {
    return r*c;
  }
  if (r*c % 2 == 1 && c1 == 0 && c2 == 0 && con3 == false) {
    return r*c;
  }
  if (r*c % 2 == 0 && c1 == c2) {
    return r*c - 1;
  }
  if (r*c % 2 == 1 && c1 != c2) {
    return r*c - 1;
  }
  if (r*c % 2 == 1 && c1 == 1 && c2 == 1) {
    return r*c - 2;
  }
  if (r*c % 2 == 0 && c1 != c2 && con3 == true) {
    return r*c - 2;
  }
  if (r*c % 2 == 1 && c1 == 0 && c2 == 0 && con3 == true) {
    return r*c - 2;
  }
  assert(false);
}

int to_num(int x, int y, int r, int c) {
  return y*c+x;
}

pair<int, int> from_num(int num, int r, int c) {
  return make_pair(num % c, num / c);
}

vector<pair<int, int> > FindPathBrute(int r, int c, int x1, int y1, int x2, int y2) {
  if (r*c > 30)
    fprintf(stderr, "brute %d %d %d %d %d %d %d\n", r, c, x1, y1, x2, y2,
            upper(r, c, x1, y1, x2, y2));
  x1--; x2--; y1--; y2--;
  queue<pair<long long, int> > fr;
  unordered_map<pair<long long, int>, int> prev;
  int start = to_num(x1, y1, r, c);
  int fin = to_num(x2, y2, r, c);
//  fprintf(stderr, "s %d f %d\n", start, fin);
  prev[make_pair(1ll<<start, start)] = -1;
  fr.push(make_pair(1ll<<start, start));
  int smx[] = {0,1,0,-1};
  int smy[] = {1,0,-1,0};
  long long best = 0;
  while (!fr.empty()) {
    pair<long long, int> x = fr.front(); fr.pop();
    pair<int, int> pos = from_num(x.second, r, c);
//    fprintf(stderr, "s %lld %d %d %d\n", x.first, x.second, pos.first, pos.second);
    if (x.second == fin) {
      if (__builtin_popcountll(x.first) > __builtin_popcountll(best))
        best = x.first;
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int nx = pos.first + smx[i];
      int ny = pos.second + smy[i];
      if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
      int new_pos = to_num(nx, ny, r, c);
      if (x.first & (1ll << new_pos)) continue;
      long long new_sub = x.first | (1ll << new_pos);
      if (prev.count(make_pair(new_sub, new_pos))) continue;
      prev[make_pair(new_sub, new_pos)] = x.second;
      fr.push(make_pair(new_sub, new_pos));
    }
  }
  vector<pair<int, int> > ret;
  long long cur = best;
  long long curv = fin;
  while (cur != 0) {
    ret.push_back(from_num(curv, r, c));
    long long pv = prev[make_pair(cur, curv)];
    cur ^= (1ll << curv);
    curv = pv;
  }
  reverse(ret.begin(), ret.end());
  for (int i = 0; i < ret.size(); i++) {
    ret[i].first++; ret[i].second++;
  }
/*  fprintf(stderr, "brute out:\n"); 
  for (int i = 0; i < ret.size(); i++) {
    fprintf(stderr, "(%d,%d) ", ret[i].first, ret[i].second);
  }
  fprintf(stderr, "\n");*/
  return ret;
}

vector<pair<int, int> > FindPath(int r, int c, int x1, int y1, int x2, int y2,
                                 bool sw = false) {
  int u = upper(r, c, x1, y1, x2, y2);
//  fprintf(stderr, "f %d %d %d %d %d %d %d %d\n", r, c, x1, y1, x2, y2, (int)sw, u);

  //try splits
  for (int i = 1; i < c; i++) {
    if (x1 <= i && x2 > i) {
      // path (x1, y1) -> (i,j), (i+1,j) -> (x2, y2)
      for (int j = 1; j <= r; j++) {
        if (x1 == i && y1 == j) continue;
        if (x2 == i+1 && y2 == j) continue;
        int u1 = upper(r, i, x1, y1, i, j);
        int u2 = upper(r, c-i, 1, j, x2-i, y2);
        assert(u1 + u2 <= u);
        if (u1 + u2 == u) {
          vector<pair<int, int> > ret = FindPath(r, i, x1, y1, i, j);
          vector<pair<int, int> > ret2 = FindPath(r, c-i, 1, j, x2-i, y2);
          for (int k = 0; k < ret2.size(); k++) {
            ret.push_back(make_pair(ret2[k].first + i, ret2[k].second));
          }
          return ret;
        }
      }
    }
  }
  for (int i = 1; i < r; i++) {
    if (y1 <= i && y2 > i) {
      // path (x1, y1) -> (j,i), (j,i+1) -> (x2, y2)
      for (int j = 1; j <= c; j++) {
        if (x1 == j && y1 == i) continue;
        if (x2 == j && y2 == i+1) continue;
        int u1 = upper(i, c, x1, y1, j, i);
        int u2 = upper(r-i, c, j, 1, x2, y2-i);
        assert(u1 + u2 <= u);
        if (u1 + u2 == u) {
          vector<pair<int, int> > ret = FindPath(i, c, x1, y1, j, i);
          vector<pair<int, int> > ret2 = FindPath(r-i, c, j, 1, x2, y2-i);
          for (int k = 0; k < ret2.size(); k++) {
            ret.push_back(make_pair(ret2[k].first, ret2[k].second + i));
          }
          return ret;
        }
      }
    }
  }

  // try strips
  if (sw) {
    for (int i = 2; i < x1 && i < x2; i++) {
      if (i*r % 2 != 0) continue;
      int u2 = upper(r, c-i, x1-i, y1, x2-i, y2);
      if (u2 + i*r == u) {
        vector<pair<int, int> > ret = FindPath(r, c-i, x1-i, y1, x2-i, y2);
        vector<pair<int, int> > ret2;
        bool fixed = false;
        for (int ii = 0; ii < ret.size(); ii++) {
          if (!fixed && ii > 0 && ret[ii].first == 1 && ret[ii-1].first == 1) {
            vector<pair<int, int> > ret3 = FindPath(r, i, i, ret[ii-1].second, i, ret[ii].second);
            for (int j = 0; j < ret3.size(); j++) {
              ret2.push_back(ret3[j]);
            }
            fixed = true;
          }
          ret2.push_back(make_pair(ret[ii].first + i, ret[ii].second));
        }
        if (fixed) return ret2;
      }
    }
    for (int i = max(x1, x2)+1; i + 2 <= c; i++) {
      if ((c-i)*r % 2 != 0) continue;
      int u2 = upper(r, i, x1, y1, x2, y2);
      if (u2 + (c-i)*r == u) {
        vector<pair<int, int> > ret = FindPath(r, i, x1, y1, x2, y2);
        vector<pair<int, int> > ret2;
        bool fixed = false;
        for (int ii = 0; ii < ret.size(); ii++) {
          if (!fixed && ii > 0 && ret[ii].first == i && ret[ii-1].first == i) {
            vector<pair<int, int> > ret3 = FindPath(r, c-i, 1, ret[ii-1].second, 1,
                                                    ret[ii].second);
            for (int j = 0; j < ret3.size(); j++) {
              ret2.push_back(make_pair(ret3[j].first + i, ret3[j].second));
            }
            fixed = true;
          }
          ret2.push_back(make_pair(ret[ii].first, ret[ii].second));
        }
        if (fixed) return ret2;
      }
    }
    for (int i = 2; i < y1 && i < y2; i++) {
      if (i*c % 2 != 0) continue;
      int u2 = upper(r-i, c, x1, y1-i, x2, y2-i);
      if (u2 + i*c == u) {
        vector<pair<int, int> > ret = FindPath(r-i, c, x1, y1-i, x2, y2-i);
        vector<pair<int, int> > ret2;
        bool fixed = false;
        for (int ii = 0; ii < ret.size(); ii++) {
          if (!fixed && ii > 0 && ret[ii].second == 1 && ret[ii-1].second == 1) {
            vector<pair<int, int> > ret3 = FindPath(i, c, ret[ii-1].first, i, ret[ii].first, i);
            for (int j = 0; j < ret3.size(); j++) {
              ret2.push_back(ret3[j]);
            }
            fixed = true;
          }
          ret2.push_back(make_pair(ret[ii].first, ret[ii].second + i));
        }
        assert(fixed);
        if (fixed) return ret2;
      }
    }
    for (int i = max(y1, y2)+1; i + 2 <= r; i++) {
      if ((r-i)*c % 2 != 0) continue;
      int u2 = upper(i, c, x1, y1, x2, y2);
      if (u2 + (r-i)*c == u) {
        vector<pair<int, int> > ret = FindPath(i, c, x1, y1, x2, y2);
        vector<pair<int, int> > ret2;
        bool fixed = false;
        for (int ii = 0; ii < ret.size(); ii++) {
          if (!fixed && ii > 0 && ret[ii].second == i && ret[ii-1].second == i) {
            vector<pair<int, int> > ret3 = FindPath(r-i, c, ret[ii-1].first, 1,
                                                    ret[ii].first, 1);
            for (int j = 0; j < ret3.size(); j++) {
              ret2.push_back(make_pair(ret3[j].first, ret3[j].second + i));
            }
            fixed = true;
          }
          ret2.push_back(make_pair(ret[ii].first, ret[ii].second));
        }
        assert(fixed);
        if (fixed) return ret2;
      }
    }
  }

  if (!sw) {
    vector<pair<int, int> > ret = FindPath(r, c, x2, y2, x1, y1, true);
    reverse(ret.begin(), ret.end());
    return ret;
  } else {
    return FindPathBrute(r, c, x1, y1, x2, y2);
  }
}

bool Check(vector<pair<int, int> > p, int r, int c, int x1, int y1, int x2, int y2) {
  assert(p[0] == make_pair(x1, y1));
  assert(p.back() == make_pair(x2, y2));
  unordered_set<pair<int, int> > visited;
  for (int i = 0; i < p.size(); i++) {
    assert(visited.count(p[i]) == 0);
    visited.insert(p[i]);
  }
  return true;
}


void solve() {
  int r, c, x1, y1, x2, y2;
  scanf("%d %d %d %d %d %d", &r, &c, &x1, &y1, &x2, &y2);
  int up = upper(r, c, x1, y1, x2, y2);
  vector<pair<int, int> > p = FindPath(r, c, x1, y1, x2, y2);
  // fprintf(stderr, "u %d p %d rc %d\n", up, p.size(), r*c);
  // assert(up == p.size());
  // assert(Check(p, r, c, x1, y1, x2, y2));
/*  for (int i = 0; i < p.size(); i++) {
    printf("(%d,%d) ", p[i].first, p[i].second);
  }
  printf("\n");*/
  printf("YES\n");
  for (int i = 1; i < p.size(); i++) {
    if (p[i].second == p[i-1].second + 1) printf("U");
    else if (p[i].second == p[i-1].second - 1) printf("D");
    else if (p[i].first == p[i-1].first + 1) printf("R");
    else if (p[i].first == p[i-1].first - 1) printf("L");
    else assert(false);
  }
  printf("\n");
//  x1--; x2--; y1--; y2--;

}
void indef(){
  #define JA "input"
  if(fopen(JA ".inp", "r")){
    freopen(JA ".inp","r",stdin);
    freopen(JA ".out","w",stdout);  
  }
}
int main() {
  indef();
  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++) solve();
}
