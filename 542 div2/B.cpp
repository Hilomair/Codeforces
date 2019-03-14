#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
//typedef long long ll;
using namespace std;

int a[200200][2];

int main()
{
	long long n,ans = 0,tmp;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>tmp;
		if(a[tmp][0])	a[tmp][1] = i;
		else	a[tmp][0] = i;
		//cout<<i<<" "<<tmp<<" "<<a[tmp][0]<<" "<<a[tmp][1]<<"\n";
	}
	ans = a[1][0] - 1;
	ans += a[1][1] - 1;
	//cout<<ans<<"\n";
	for(int i=1;i<n;i++)
	{
		long long nxt1,nxt2,nxt3,nxt4;

		nxt1 = abs(a[i][0] - a[i+1][0]);
		nxt2 = abs(a[i][0] - a[i+1][1]);
		nxt3 = abs(a[i][1] - a[i+1][0]);
		nxt4 = abs(a[i][1] - a[i+1][1]);
		//cout<<a[i+1][0]<<" !!! "<<a[i+1][1];
		nxt1+=nxt4;
		nxt2+=nxt3;
		tmp = min(nxt1,nxt2);	
		ans += tmp;
		//cout<<i<<" "<<ans<<"\n";	
	}
	cout<<ans;
}