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

	// Заполняем массив числами от 1 до num
	for (int i = 1; i <= num; i++)
	{
		nums.insert(i);
	}

	// Удаляем из массива все числа согласно алгоритму Сундарама
	double dbl_num = num;
	for (int i = 1; i <= floor((sqrt((2 * dbl_num) + 1) - 1) / 2);i++)
	{
		for (int j = i; j <= floor((num - i) / ((2 * i) + 1));j++)
		{
			nums.erase((i + j + (2 * i * j)));
		}
	}

	// Заполняем массив простыми числами
	ans.push_back(2);
	for (int number : nums)
	{
		ans.push_back((2 * number) + 1);
	}

	// Возвращаем этот массив в качестве результата 
	return ans;
}


int main()
{
	SetConsoleCP(1251);               
	SetConsoleOutputCP(1251);
	
	cout << "Введите число: ";
	
	int num;
	cin >> num;
	
	cout << "Вот все простые числа на отрезке [2;" << (2 * num) + 1 << "]: \n";
	
	// Выводим массив простых чисел, который мы получили
	for (int a : SundaramasSieve(num))
	{
		cout << a << " ";
	}

	return 0;
}