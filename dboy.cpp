#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second


void printarray(int a[], int size)
{
	for(int i=0; i<=size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


int main()
{
// Uncomment to use TestCases
	int T;
	int n, maxh, h[550], k[550], dp[1100];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		maxh = INT_MIN;
		for(int i=0; i<n; i++)
		{
			scanf("%d", h+i);
			h[i]*=2;
			maxh = max(maxh, h[i]);
		}
		for(int i=0; i<n; i++)
			scanf("%d", k+i);
		sort(k, k+n);
		dp[0] = 0;
		for(int i=1; i<=maxh; i++)
		{
			dp[i] = 100000;
			if(binary_search(k, k+n, i))
			{
				dp[i] = 1;
				continue;
			}
			for(int j=i/2; j>0; j--)
				dp[i] = min(dp[i], dp[j]+dp[i-j]);
		}
		int ans = 0;
		for(int i=0; i<n; i++)
			ans += dp[h[i]];
//		printarray(dp, maxh);
		printf("%d\n", ans);
	}
	return 0;
}

