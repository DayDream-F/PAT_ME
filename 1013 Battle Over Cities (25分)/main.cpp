//1013 Battle Over Cities (25分) 
#include <bits/stdc++.h>
using namespace std;
 
vector<int> G[1004];
bool vis[1004]={false};
int occupy;
int N,cnt=0;
void DFS(int u)
{
	vis[u]=true;
	for(int v=0;v<G[u].size();v++)
	{
		int city=G[u][v];
		if(vis[city]==false)
		{
			
		//	cnt++;
			DFS(city);
		}
	}
}
void DFSTravel()
{
	for(int i=1;i<=N;i++)
	{
		if(vis[i]==false)
		{
			DFS(i);
			cnt++;
		}
	}
}
int main() 
{
	int M,K;
	cin>>N>>M>>K;
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);//此处一定要注意，该图为无向图 
	}
	for(int i=0;i<K;i++)
	{
		scanf("%d",&occupy);
		memset(vis,false,sizeof(vis));
		cnt=0;
		vis[occupy]=true;// the city is occupied
		DFSTravel();
		//cout<<N-1-cnt-1<<endl;
		cout<<cnt-1<<endl;//需要重修的路为连通分量-1 
	}
	return 0;
}
