#include <bits/stdc++.h>

using namespace std;

long long a[200200];

int main()
{
	long long n,maxa = -1,ans,cnt;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxa = max(a[i],maxa);
	cnt = 0;ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i] == maxa && a[i] != a[i-1])	cnt=1;
		if(a[i] == maxa && a[i] == a[i-1])	cnt++;
		ans = max(cnt,ans);
	}
	cout<<ans<<"\n";
	return 0;
}