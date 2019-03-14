#include <bits/stdc++.h>

using namespace std;

long long a[200200],b[200200];
map<long long ,long long > cnt;
vector<int> ans;
int main()
{
	int n,m,k;
	long long total = 0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=n;i>=n-m*k+1;i--)	cnt[b[i] ]++,total += b[i];
	int flag = 0,count = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i] ] != 0 && !flag)
		{
			flag = 1,cnt[a[i] ]--,count++;
			if(count >= m)
				ans.push_back(i),flag = 0,count=0;
			continue;
		}
		if(cnt[a[i]] != 0 && flag)
		{
			count++;
			if(count >= m)
				ans.push_back(i),flag = 0,count=0;
		}
	}
	cout<<total<<"\n";
	for(int i=0;i<ans.size()-1;i++)
		cout<<ans[i]<<" ";
	return 0;
}