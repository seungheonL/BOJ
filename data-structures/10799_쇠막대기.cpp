#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	stack<string> s;
	string str;
	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
	{
		string bracket = str.substr(i, 1);

		if (bracket == "(")
		{
			if (str.substr(i + 1, 1) == ")")
			{
				cnt += s.size();
				i++;
			}
			else
			{
				s.push("(");
			}
		}
		else if (bracket == ")")
		{
			cnt++;
			if (!s.empty())
			{
				s.pop();
			}
		}
	}
	cout << cnt << endl;

	return 0;
}
