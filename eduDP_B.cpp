#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int main()
{
	long long n,k;
	cin>>n>>k;
	vector<long long> h(n);
	for(long long i=0;i<n;i++){
		cin>>h[i];
	}
	// Initialise the vector elements with INF
	vector<long long> dp(n, INF);
	dp[0] = 0;
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<=i+k;j++){
			if(j<n)
				dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]));
		}
	}
	cout<<dp[n-1];
	return 0;
}