#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> sequence;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		sequence.push_back(value);
	}

	std::stack<int> stack;
	std::vector<char> printer;
	int num = 1;

	for (int i = 0; i < n; i++)
	{
		if (stack.empty())
		{
			int loop = sequence[i] - num + 1;
			for (int j = 0; j < loop; j++)
			{
				stack.push(num++);
				printer.push_back('+');
				//cout << "+" << endl;
			}
			stack.pop();
			printer.push_back('-');
			//cout << "-" << endl;
		}
		else if (num == sequence[i])
		{
			stack.push(num++);
			printer.push_back('+');
			//cout << "+" << endl;

			stack.pop();
			printer.push_back('-');
			//cout << "-" << endl;

		}
		else if (sequence[i] > num)
		{
			int loop = sequence[i] - num + 1;
			for (int j = 0; j < loop; j++)
			{
				stack.push(num++);
				printer.push_back('+');
				//cout << "+" << endl;

			}
			stack.pop();
			printer.push_back('-');
			//cout << "-" << endl;

		}
		else if (stack.top() == sequence[i])
		{
			stack.pop();
			printer.push_back('-');
			//cout << "-" << endl;
		}
		else if (sequence[i] < stack.top())
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i = 0; i < printer.size(); i++)
	{
		printf("%c\n", printer[i]);
	}

	return 0;
}
