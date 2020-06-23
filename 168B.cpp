#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	string s;
	string t;
	cin>>k>>s;
	if(s.size() < k)
		cout<<s;
	else{
		t = s.substr(0,k).append("...");
		cout<<t;
	}
	return 0;
}