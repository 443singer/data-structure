#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 32003;
int n,c[N],ans[N];
int lowbit(int x) { return x&(-x);}
void modify(int x,int add) {
	while(x <= N) {
		c[x] += add;
		x += lowbit(x);
	}
}
int query(int x) {
	int sum = 0;
	while(x) {
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int main() {
	while(scanf("%d",&n)!=EOF) {
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		for(int i = 1 ; i <= n ; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			ans[query(++x)]++;
			modify(x,1);
		}
		for(int i = 0 ; i < n ; ++i) printf("%d\n",ans[i]);
	}
}
