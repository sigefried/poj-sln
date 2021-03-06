//mst
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<limits>
#include<utility>

//#define c11
#ifdef c11
#include<unordered_set>
#include<unordered_map>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define initz(x) memset(x,0,sizeof(x))
#define initm(x) memset(x,0x7f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 30;
const int MAX_M = 5000;

typedef pair<int, int> P;
int fa[MAX_M];
struct E{
  E() {}
  E(int uu, int vv, int cc): u(uu), v(vv), c(cc) {}
  bool operator > (const E& e) const {
    return c < e.c;
  }
  int u, v, c;
};

priority_queue<E, vector<E>, greater<E> > pq;

int find(int x) {
  if(x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

int Kruskal(int n) {
  for(int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int cnt = 1;
  int ans = 0;

  while(cnt < n && !pq.empty()) {
    const E& e = pq.top();
    int u, v, c;
    u = e.u;
    v = e.v;
    c = e.c;
    pq.pop();

    u = find(u);
    v = find(v);
    if(u == v) continue;
    fa[u] = v;
    ans += c;
    ++cnt;
  }
  if(cnt < n) {
    return -1;
  } else {
    return ans;
  }
}

int main() {
	int n, m;
  scanf("%d%d", &n, &m);
  while(m--) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    pq.push(E(u, v ,c));
  }
	cout << Kruskal(n) << endl;
	return 0;
}
