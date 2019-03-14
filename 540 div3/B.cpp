#include <bits/stdc++.h>

using namespace std;

long long a[200200],s[200200];

int main()
{
	int n;
	cin>>n;
	cin>>a[1];
	cin>>a[2];
	s[0] = 0;
	s[1] = a[1];
	s[2] = a[2];
	long long even,odd,ans=0;
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		s[i] = a[i] + s[i-2];
		if(i%2)	odd = s[i];
		else even = s[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long tmpe = even,tmpo = odd;
		if(i%2)	tmpe = tmpe - s[i-1] + s[i] - a[i],tmpo = tmpo - s[i] + s[i-1];
		else	tmpo = tmpo - s[i-1] + s[i] - a[i],tmpe = tmpe - s[i] + s[i-1];
		if(tmpe == tmpo)	ans++;
	}
	cout<<ans;
	return 0;
}