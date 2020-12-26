#include <iostream>

using namespace std;

int main()
{
	int n, x, y, ans = 0;
	string a;
	cin >> n >> x >> y >> a;
	if (a[n-y-1] != '1')
		ans++;
	for (int i = a.size() - y; i < a.size(); i++)
		if(a[i] != '0')
			ans++;
	for (int i = a.size() - x; i < a.size() - y - 1; i++)
		if(a[i] != '0')
			ans++;
	cout << ans;

	return 0;
}