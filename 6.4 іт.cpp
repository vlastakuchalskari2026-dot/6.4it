#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void create(int* m, int size, int low, int high);
void print(int* m, const int size);
int countab(int* m, const int size, int a, int b);
int maximum(int* m, const int size);
int sumaftermax(int* m, const int size);
void sort(int* m, const int size);
int main()
{
	srand((unsigned)time(NULL));
	int n, A, B;
	cout << "n = "; cin >> n;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	int *m = new int[n];
	int low = -20;
	int high = 20;
	create(m, n, low, high);
	print(m, n);
	cout << "Count elements in range from A to B = " << countab(m, n, A, B) << endl;
	cout << "Sum of the elements after max = " << sumaftermax(m, n) << endl;
	sort(m, n);
	print(m, n);
	return 0;
}
void create(int* m, int size, int low, int high)
{
	for (int i = 0; i < size; i++)
		m[i] = low + rand() % (high - low + 1);
}
void print(int* m, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << m[i];
	cout << endl;
}
int countab(int* m, const int size, int a, int b)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		if (m[i] >= a && m[i] <= b)
			k++;
	return k;
}
int maximum(int* m, const int size)
{
	int max = m[0];
	int maxi = 0;
	for (int i = 0; i < size; i++)
		if (m[i] > max)
		{
			max = m[i];
			maxi = i;
		}
	return maxi;
}
int sumaftermax(int* m, const int size)
{
	int s = 0;
	for (int i = 0; i < size; i++)
		if (maximum(m, size) < i)
			s += m[i];
	return s;
}
void sort(int* m, const int size) 
{
	for (int i = 0; i < size - 1; i++)
	{
		if (m[i] % 2 == 0)
			for (int j = i + 1; j < size; j++)
			{
				if (m[j] % 2 == 0 && abs(m[j]) > abs(m[i]))
				{
					int tmp = m[i];
					m[i] = m[j];
					m[j] = tmp;
				}
			}
	}
}
