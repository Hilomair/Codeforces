#include <bits/stdc++.h>

using namespace std;

long long a[200200];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	a[0] = -1e9;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	long long ans = 0,tmp;
	ans = a[n] * k;
	ans += a[n-1];
	tmp = m % (k+1);
	m /= (k+1);
	ans *= m;
	ans += a[n] * tmp;
	cout<<ans;
	return 0;
}