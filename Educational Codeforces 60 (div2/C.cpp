#include <bits/stdc++.h>

using namespace std;

long long a[200200];
map<char,int> m;
int main()
{
	int x1,y1,x2,y2,n;
	string a;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>n;
	cin>>a;
	for(int i=0;i<a.size();i++)	m[a[i]]++;
	x2-=x1;y2-=y1;
	long long cnt = 0,ans = 0;
	for(int i=1;i<=999999999;i++)
	{
		if(x2 == 0 && y2 == 0)	{ans = i;break;}
		cnt %= n;
		 
	}
	return 0;
}