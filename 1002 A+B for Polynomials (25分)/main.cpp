#include <bits/stdc++.h>
using namespace std;

float num[1005]; 
int main() 
{
	int k,l,index,cnt=0;
	float s;
	cin>>k;
	for(int i=0;i<k;i++) 
	{
		cin>>index;
		cin>>s;
		num[index]+=s;
	}
	cin>>l;
	for(int i=0;i<l;i++)
	{
		cin>>index;
		cin>>s;
		num[index]+=s;
	}
	for(int i=0;i<=1000;i++)
		if(num[i]!=0)
		cnt++;
	cout<<cnt;
	for(int i=1000;i>=0;i--)
	{
		if(num[i]!=0)
		{
			cout<<" "<<i;
			printf(" %.1f",num[i]);
		}
		
	}	
	return 0;
}
