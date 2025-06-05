#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long long min, max;
	cin >> min >> max;

	vector<bool> numbers;
	numbers.resize(max - min + 1);

	for (long long i = 2; i * i <= max; i++)
	{
		for (long long j = min / i / i; j <= max / i / i; j++)
		{
			if (j * i * i >= min && j * i * i <= max)
			{
				numbers[j * i * i - min] = true;
			}
		}
	}
	cout << count(numbers.begin(), numbers.end(), false);
}
