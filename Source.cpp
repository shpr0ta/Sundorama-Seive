#include <iostream> 
#include <math.h>
#include <vector>
#include <set>

using namespace std;

vector<int> SundaramasSieve(int num)
{
	set <int> nums;
	vector <int> ans;

	for (int i = 1; i <= num; i++)
	{
		nums.insert(i);
	}

	double dbl_num = num;
	for (int i = 1; i <= floor((sqrt((2 * dbl_num) + 1) - 1) / 2);i++)
	{
		for (int j = i; j <= floor((num - i) / ((2 * i) + 1));j++)
		{
			nums.erase((i + j + (2 * i * j)));
		}
	}

	ans.push_back(2);
	for (int number : nums)
	{
		ans.push_back((2 * number) + 1);
	}

	return ans;
}


int main()
{
	cout << "Enter number: ";
	
	int num;
	cin >> num;
	
	cout << "All primes numbers in [2;" << (2 * num) + 1 << "]: ";
	
	for (int a : SundaramasSieve(num))
	{
		cout << a << " ";
	}

	return 0;
}