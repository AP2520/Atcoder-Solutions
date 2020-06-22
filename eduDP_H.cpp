#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
	int n,m;
	cin>>n>>m;
	vector<string>s(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	// A vector table to store the dp values
	// A vector containing n vectors of size m
	vector<vector<int>>dp(n,vector<int>(m,0));
	// If there is only 1 block then there is only 1 path
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '#')
				continue;
			if(i==0 && j==0)
				continue;
			if(i==0)
				dp[i][j]=dp[i][j-1];
			else if(j==0)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=(dp[i][j]%MOD + dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}