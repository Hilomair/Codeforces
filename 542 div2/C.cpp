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
typedef long long ll;
using namespace std;

char a[53][53];

void dfs(ll r,ll c,char v)
{
	//cout<<r<<" "<<c<<"\n";
	a[r][c] = v;
	if(a[r+1][c] == '0')	dfs(r+1,c,v);
	if(a[r-1][c] == '0')	dfs(r-1,c,v);
	if(a[r][c+1] == '0')	dfs(r,c+1,v);
	if(a[r][c-1] == '0')	dfs(r,c-1,v);
	return ;
}

vector<pair<int,int> > o,t;
int main()
{
	ll n,r1,c1,r2,c2;
	cin>>n;
	cin>>r1>>c1>>r2>>c2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	dfs(r1,c1,'A');
	if(a[r2][c2] == '0')
		dfs(r2,c2,'B');
	ll ans = 1e9;
	t.clear();
	o.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j] == 'A')	o.push_back(make_pair(i,j));
			if(a[i][j] == 'B')	t.push_back(make_pair(i,j));
		}
	//if(t.empty()) {cout<<"0";return 0;}
	for(int i=0;i<o.size();i++)
		for(int j=0;j<t.size();j++)
		{
			//cout<<"o "<<o[i].first<<" "<<o[i].second<<"\n";
			//cout<<"t "<<t[j].first<<" "<<t[j].second<<"\n";
			ll tmp = (o[i].first - t[j].first)*(o[i].first - t[j].first) + (o[i].second - t[j].second)*(o[i].second - t[j].second);
			ans = min(ans,tmp);
		}
	if(ans == 1e9)	ans = 0;
	cout<<ans;
}