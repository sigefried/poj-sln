//mst
#include<vector>
#include<list>
#include<deque>
#include<queue>
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

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))

struct edge {
	int u,v,cost;
	bool operator < (const edge &e) const {
		return cost < e.cost;
	}
};

int N, E;

edge edges[10000];
int parent[100];
int height[100];


const int MAX = 10000;

void init() {
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		height[i] = 0;
	}
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}


bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

	if (height[a] < height[b])
		parent[a] = b;
	else {
		parent[b] = a;
		if (height[a] == height[b])
			height[a]++;
	}
}

int kruskal() {
	sort(edges, edges+E);
	init();
	int ret = 0;
	for (int i = 0; i < E; ++i) {
		edge &cur = edges[i];
		if (!same(cur.u, cur.v)) {
			unite(cur.u, cur.v);
			ret += cur.cost;
		}
	}
	return ret;
}

int main() {
	while (scanf("%d", &N) != EOF) {
		int idx = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0 ; j < N; ++j) {
				int w;
				cin >> w;
				if (i != j) {
					edges[idx].u = i;
					edges[idx].v = j;
					edges[idx].cost = w;
					idx++;
				}
			}
		}
		E = idx;
		printf("%d\n", kruskal());
	}
	return 0;
}
