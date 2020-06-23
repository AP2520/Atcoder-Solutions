#include<bits/stdc++.h>
using namespace std;
// To check whether each node is visited or not
bool visited[100005];

// To store the path that we have to take from each node
// i.e the signposts that have to be placed in each room
int path[100005];

// To store the graph
vector<int>adj[100005];

// Helps in BFS
queue<int>q;
int main()
{
	memset(visited, sizeof(visited), false);
	int n,m;
	cin>>n>>m;
	int x,y;
	bool flag=false;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		// To check whether there is an edge between 1 and any other node
		// If there is no connection between 1 and any other node it means that 1 is completely disconnected 
		// from the rest of the graph
		if(x==1 || y==1)
			flag=true;
	}
	// If 1 has no connections then print NO
	if(!flag){
		cout<<"No";
		return 0;
	}
	q.push(1);
	while(q.size()){
		int x=q.front();
		q.pop();
		if(!visited[x]){

			// Make sure that it is visited
			visited[x]=true;

			// Do a for loop over it's children
			for(int i=0;i<adj[x].size();i++){
				// Push their children into the queue
				q.push(adj[x][i]);
				// This is to check whether the path has been updated or not
				// If it has not been updated then set it to the parent variable
				if(path[adj[x][i]]==0)
					path[adj[x][i]]=x;
			}
		}
	}
	cout<<"Yes"<<"\n";
	for(int i=2;i<=n;i++)
		cout<<path[i]<<"\n";	
	return 0;
}