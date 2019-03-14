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
int a[202];

int main()
{
	int n,d = 0,b = 0;
	cin>>n;
	for(int i=0;i<n;i++)	
	{
		cin>>a[i];
		if(a[i] > 0)	d++;
		if(a[i] < 0)	b++;	
	}
	if(n%2)	n/=2,n++;
	else	n/=2;
	if(d >= n)	cout<<"1";
	else if(b >=n)	cout<<"-1";
	else cout<<"0";
}