//#include<iostream>
//using namespace std;
//typedef long long ll;
//int n;
//ll a[100000], b[100000];
//ll exdgcd(ll a, ll b, ll& x, ll& y)
//{
//	if (b == 0)
//	{
//		x = 1;
//		y = 0;
//		return a;
//	}
//	else
//	{
//		ll t = exdgcd(b, a % b, x, y);
//		ll temp = x;
//		x = y;
//		y = temp - a / b * y;
//		return t;
//	}
//}
//ll CRT(ll* a, ll* b)
//{
//	ll m1 = a[0],r1=b[0];
//	ll x, y;
//	for (int i = 1; i < n; i++)
//	{
//		ll m2 = a[i], r2 = b[i];
//		ll tempm = exdgcd(m1, m2, x, y);
//		x = (x * (r2 - r1) / tempm);
//		x = (x % (m2 / tempm) + m2 / tempm) % (m2 / tempm);
//		r1 = (m1 * x + r1);
//		m1 = (m1 * m2 / tempm);
//	}
//	return (r1 % m1 + m1) % m1;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i] >> b[i];
//	}
//	cout << CRT(a, b) << endl;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//typedef __int128 ll;
typedef long long ll;
int n;
ll a[100001], b[100001];
ll exdgcd(ll a, ll b, ll& x, ll& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll t = exdgcd(b, a % b, x, y);
	ll temp = x;
	x = y;
	y = temp - a / b * y;
	return t;
}
ll CRT(ll* a, ll* b)
{
	ll m1 = a[0], r1 = b[0];
	ll x, y;
	for (int i = 1; i < n; i++)
	{
		ll m2 = a[i], r2 = b[i];
		ll tempm = exdgcd(m1, m2, x, y);
		x = (x * (r2 - r1) / tempm);
		x = (x % (m2 / tempm) + m2 / tempm) % (m2 / tempm);
		r1 = (m1 * x + r1);
		m1 = (m1 * m2 / tempm);
	}
	return (r1 % m1 + m1) % m1;
}
int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i], &b[i]);
	}
	printf("lld", CRT(a, b));
	return 0;
}