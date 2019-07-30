
#include<cstdio> 
#include<iostream>
using namespace std;

#define eps 0.00001
int num[100050];
int n, m;

int check(double l) {
	int ans = 0;	
	for (int i=0; i<n; i++) {
		ans += (int)((double)num[i] / l);
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	double minn = 0.0, maxn = 0.0;
	for (int i=0; i<n; i++) {
		scanf("%d", &num[i]);
		if (maxn < num[i]) maxn = (double)num[i];
	}
	double mid;
	while (maxn - minn >= eps) {
		mid = (minn + maxn) / 2;
		if (m > check(mid)) {
			// 需求 > 能做的，太长了 
			maxn = mid;
			continue; 
		} else {
			// 需求 < 能做的，太短了 
			minn = mid;
			continue; 
		}
	} 
	printf("%.2lf\n", mid);
	return 0;
}
