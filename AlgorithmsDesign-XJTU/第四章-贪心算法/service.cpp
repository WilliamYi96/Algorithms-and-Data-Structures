#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100] = { 0 };
	for (int i = 1; i <=n; i++)
		cin >> a[i];
	sort(a, a+n);
	double sum=0;
	for (int i = 1; i <= n; i++)
		sum +=(n+1-i)*a[i];
	cout << sum / n<<endl;
	return 0;
}
