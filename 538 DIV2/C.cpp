#include <bits/stdc++.h>

using namespace std;

int main()
{
	for(int i=1;i<=100;i++)
	{
		int cnt = 0,tmp = i;
		if(i%2 == 0)
		{
			while(tmp%2 == 0)	tmp/=2,cnt++;
			cout<<i<<"   "<<cnt<<"\n";
		}
	}
	return 0;
}