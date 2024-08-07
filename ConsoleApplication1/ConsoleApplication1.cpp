#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

// 声明 chu2 函数
string chu2(string s);

ll quick_pow(ll a, string b, ll c)
{
	ll ans = 1;
	int nsize = b.size();
	while (nsize != 0)
	{
		if ((b[nsize - 1] - '0') % 2 != 0)
		{
			ans = (ans * a) % c;
		}
		b = chu2(b);
		nsize = b.size();
		a = (a * a) % c;
	}
	return ans;
}

string chu2(string s)
{
	string ans;
	int temp = 0;
	for (int i = 0; i < s.size(); i++)
	{
		temp = temp * 10 + s[i] - '0';
		ans.push_back(temp / 2 + '0');
		temp = temp % 2;
	}
	while (ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string b;
	ll a, m;
	cin >> a >> m;
	cin >> b;
	cout << quick_pow(a, b, m) << endl;
}
