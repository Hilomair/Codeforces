#include <bits/stdc++.h>

using namespace std;

long long a[500],ans[25][25],cnt[1001]{};

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n*n;i++)	cin>>a[i],cnt[a[i]]++;
	if(n%2)
	{
		int flag = 0,now,center = n/2+1;
		for(int i=1;i<=1000;i++)
			if(cnt[i]%2 && flag)	{cout<<"NO";return 0;}
			else if(cnt[i]%2)	flag = 1,now = i;
		cnt[now] --;
		ans[center][center] = now;
		for(int i=1;i<center;i++)
			for(int j=1;j<center;j++)
			{
				flag = 0;
				for(int k=1;k<=1000;k++)
				{
					if(cnt[k] >= 4)
					{
						flag=1,cnt[k]-=4,now=k;
						break;
					}
				}
				if(!flag)	{cout<<"NO";return 0;}
				else ans[i][j] = ans[n-i+1][j] = ans[i][n-j+1] = ans[n-i+1][n-j+1] = now;
			}
		for(int i=1;i<center;i++)
		{
			flag = 0;
			for(int k=1;k<=1000;k++)
				{
					if(cnt[k] >= 2)
					{
						flag=1,cnt[k]-=2,now=k;
						break;
					}
				}
			if(!flag)	{cout<<"NO";return 0;}
			else	ans[i][center] = ans[n-i+1][center] = now;
		}
		for(int i=1;i<center;i++)
		{
			flag = 0;
			for(int k=1;k<=1000;k++)
				{
					if(cnt[k] >= 2)
					{
						flag=1,cnt[k]-=2,now=k;
						break;
					}
				}
			if(!flag)	{cout<<"NO";return 0;}
			else	ans[center][i] = ans[center][n-i+1] = now;
		}
	}
	else
	{
		int flag,now,center = n/2;
		for(int i=1;i<=1000;i++)
			if(cnt[i]%2)	{cout<<"NO"<<"\n";return 0;}
		for(int i=1;i<=center;i++)
			for(int j=1;j<=center;j++)
			{
				flag = 0;
				for(int k=1;k<=1000;k++)
				{
					if(cnt[k] % 4 == 0 && cnt[k] > 0)
					{
						flag=1,cnt[k]-=4,now=k;
						break;
					}
				}
				if(!flag)	{cout<<"NO";return 0;}
				ans[i][j] = ans[n-i+1][j] = ans[i][n-j+1] = ans[n-i+1][n-j+1] = now;
			}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
