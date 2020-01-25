//1103 Integer Factorization (30分)
#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init()
{
	int temp=0,index=1;
	while(temp<=n)
	{
		v.push_back(temp);
		temp=pow(index,p);
		index++;
	}
}
void dfs(int index,int tempSum,int tempK,int facSum)
{
	// 出口1，搜索完k个数
	if(tempK==k)
	{
		if(tempSum==n&&facSum>maxFacSum)
		{
			ans=tempAns;
			maxFacSum=facSum;
		}
		return ;
	}
	
	
	
	while(index>=1)
	{
		if(tempSum+v[index]<=n)
		{
			tempAns[tempK]=index;
			dfs(index,tempSum+v[index],tempK+1,facSum+index);
		}
		 // 出口2， 未搜索完k个数但目标值小于等于0
		if(index==1)
			return ;
		index--;
	}
}
int main() 
{
	cin>>n>>k>>p; 
	init();// 初始化所有底数及相应的幂
	tempAns.resize(k);//分配k个空间 
	dfs(v.size()-1,0,0,0);
	if(maxFacSum==-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<n<<"=";
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
			cout<<"+";
		cout<<ans[i]<<"^"<<p;
	}
	return 0;
}

////首先初始化可能符合条件的因子，即对任意t = k ^ P（k <= N, t <=N），将其存放在一维数组v[k]中。
//然后深度优先搜索。对于题目要求的结果是底数和最大的序列，我们每一次dfs之后都计算指数的和并进行回溯，
//其结果存放在tempAns中，在符合条件的搜索结果中，只要facSum>maxFacSum就更新序列和ans。
//对于底数和相同的序列，题目要求求字典序最大的一个。由于我们是从大的底数开始考虑，
//所以先搜索到的结果（底数和相同的情况下）一定是字典序优先级高的，
//所以对此情况无需处理。具体细节看代码。

