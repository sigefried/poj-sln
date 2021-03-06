//dp
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
#include<cstdlib>
#include<cstring>
#include<cstdio>
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
const int MAX_N = 100020;
const int MAX_M = 110;

int dp[MAX_N];
int A[MAX_M];
int C[MAX_M];

typedef pair<int, int> P;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF && n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &C[i]);
		}
		fill_n(dp, MAX_N, -1);
		dp[0] = 0;
		forn(i, n) {
			fore(j, 0, m) {
				if(dp[j] > -1) {
					//if it is valid
					dp[j] = 0;
				} else if(j >= A[i] && dp[j - A[i]] > -1 && dp[j - A[i]] < C[i]) {
					dp[j] = dp[j-A[i]] + 1;
				}
			}
		}
		int ans = 0;
		for1(i, m) {
			if(dp[i] > -1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

