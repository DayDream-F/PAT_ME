//1004 Counting Leaves (30分) 
#include <bits/stdc++.h>
using namespace std;
int const MAX=105;
vector<int> G[MAX];
int n=MAX,N;
bool vis[MAX]={false};
int child_num[MAX];
int maxdepth=-1;
void DFS(int u,int depth)
{
	vis[u]=true;
	maxdepth=max(maxdepth,depth);//重点，标注当前层 
	if(G[u].size()==0)
	{
		child_num[depth-1]++;
		return ;
	}		
	for(int v=0;v<G[u].size();v++)
	{
		int child=G[u][v];
		if(vis[child]==false)
		{
			DFS(child,depth+1);
		}
	}
}
void DFSTravel()
{
	
	for(int i=1;i<=N;i++)
	{
		if(vis[i]==false)
		{
			DFS(i,1);
		}
	}
}
int main() 
{
	int M;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int node_num,cnt;
		cin>>node_num>>cnt;
		for(int j=0;j<cnt;j++)
		{
			int child;
			cin>>child;
			G[node_num].push_back(child);
		}	
	}
	DFSTravel();
	for(int i=0;i<maxdepth;i++)
	{
		if(i==0)
			cout<<child_num[i];
		else
			cout<<" "<<child_num[i];
	}	
	return 0;
}

