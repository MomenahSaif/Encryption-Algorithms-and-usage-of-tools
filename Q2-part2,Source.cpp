#include<iostream>
using namespace std;
int main()
{
	char* arr;
	int size = 0;

	cout << "Enter the size of cipher text:" << endl;
	cin >> size;
    arr = new char[size];

	cout << "Enter The encrypted text:" << endl;
	for (int i = 0; i < size; i++)
	   cin >> arr[i];
	
	
	cout << "The combinations will be:" << endl;

	for (int k = 1; k < 26; k++)
	{
		cout << endl << k  << ".";
		for (int j = 0; j < size; j++)
		{
			if(arr[j]+3>90)
				arr[j]=(arr[j]+3)-26;
			else
				arr[j] = arr[j] + 3;

			cout << arr[j];
		}
	}
}
