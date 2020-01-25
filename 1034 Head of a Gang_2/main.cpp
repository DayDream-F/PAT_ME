#include <bits/stdc++.h>
using namespace std;
int const MAX=2010;
int G[MAX][MAX],weight[MAX];
bool vis[MAX]={false};
map<string,int> stringtoInt;
map<int,string> Intostring; 
map<string,int> ans;
int head,numMember,totalWeight;
int idNumber=1;
int k;
int stoifunc(string str)
{
	if(stringtoInt[str]==0)
	{
		stringtoInt[str]=idNumber;
		Intostring[idNumber]=str;
		return idNumber++;
	}
	else
	{
		return stringtoInt[str];
	}
}
void DFS(int u,int &head,int &numMember,int &totalWeight)
{
	vis[u]=true;
	if(weight[u]>weight[head])
		head=u;
	numMember++;
	for(int v=1;v<idNumber;v++)//1?/
	{
		if(G[u][v]>0)
		{
			totalWeight+=G[u][v];////??
			G[u][v]=G[v][u]=0;
			if(vis[v]==false)
				DFS(v,head,numMember,totalWeight);
		}
	}
}
void DFSTravel()
{
	for(int i=1;i<idNumber;i++)
	{
		if(vis[i]==false)
		{
			int head=i,numMember=0,totalWeight=0;
			DFS(i,head,numMember,totalWeight);
			if(numMember>2&&totalWeight>k)
			{
				ans[Intostring[head]]=numMember;
			}
		}
	}
}
int main() 
{
	int n,w;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2>>w;
		int id1=stoifunc(s1);
		int id2=stoifunc(s2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTravel();
	cout<<ans.size()<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
