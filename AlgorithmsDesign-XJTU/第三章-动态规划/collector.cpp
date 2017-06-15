#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

#define MAXN 22

int h[MAXN][MAXN][MAXN][MAXN];
int v[MAXN][MAXN];
int n;

void update(int x1, int y1, int x2, int y2, int val) {
	if(y1 >= n || y2 >= n) return;
	if(x1 >= n || x2 >= n) return;
	if(x1 == x2 && y1 == y2) {
		h[x1][y1][x2][y2] = max(h[x1][y1][x2][y2], 
			val + v[x1][y1]);
	} else {
		h[x1][y1][x2][y2] = max(h[x1][y1][x2][y2], 
			val + v[x1][y1] + v[x2][y2]);
	}
}

int main() {
	scanf("%d", &n);
	memset(v, 0, sizeof(v));
	int x, y, val;
	while(scanf("%d %d %d", &x, &y, &val) && x != 0) {
		v[x - 1][y - 1] = val;
	}
	memset(h, 0, sizeof(h));
	h[0][0][0][0] = v[0][0];

	for(int s = 0; s < 2 * n - 2; ++s) {
		for(int x1 = 0; x1 < n && x1 <= s; ++x1) {
			for(int x2 = 0; x2 < n && x2 <= s; ++x2) {
			int y1 = s - x1;
			int y2 = s - x2;
			int v = h[x1][y1][x2][y2];

			update(x1 + 1, y1, x2 + 1, y2, v);
			update(x1 + 1, y1, x2, y2 + 1, v);
			update(x1, y1 + 1, x2 + 1, y2, v);
			update(x1, y1 + 1, x2, y2 + 1, v);
			}
		}
	}
	printf("%d\n", h[n - 1][n - 1][n - 1][n - 1] + 15);
	return 0;
}
