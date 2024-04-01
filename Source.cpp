#include <iostream> 
#include <math.h>
#include <vector>
#include <set>
#include <windows.h>

using namespace std;

vector<int> SundaramasSieve(int num)
{
	set <int> nums;
	vector <int> ans;

	// ��������� ������ ������� �� 1 �� num
	for (int i = 1; i <= num; i++)
	{
		nums.insert(i);
	}

	// ������� �� ������� ��� ����� �������� ��������� ���������
	double dbl_num = num;
	for (int i = 1; i <= floor((sqrt((2 * dbl_num) + 1) - 1) / 2);i++)
	{
		for (int j = i; j <= floor((num - i) / ((2 * i) + 1));j++)
		{
			nums.erase((i + j + (2 * i * j)));
		}
	}

	// ��������� ������ �������� �������
	ans.push_back(2);
	for (int number : nums)
	{
		ans.push_back((2 * number) + 1);
	}

	// ���������� ���� ������ � �������� ���������� 
	return ans;
}


int main()
{
	SetConsoleCP(1251);               
	SetConsoleOutputCP(1251);
	
	cout << "������� �����: ";
	
	int num;
	cin >> num;
	
	cout << "��� ��� ������� ����� �� ������� [2;" << (2 * num) + 1 << "]: \n";
	
	// ������� ������ ������� �����, ������� �� ��������
	for (int a : SundaramasSieve(num))
	{
		cout << a << " ";
	}

	return 0;
}