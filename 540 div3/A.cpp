#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		long long n,a,b;
		cin>>n>>a>>b;
		long long ans1,ans2;
		ans1 = n*a;
		ans2 = (n/2)*b;
		ans2 += (n%2)*a;
		ans1 = min(ans1,ans2);
		cout<<ans1<<"\n";
	}
	return 0;
}