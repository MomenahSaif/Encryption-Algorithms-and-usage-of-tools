#include<iostream>
using namespace std;
int main()
{
	char *plain,cipher;
	int size,k=3;
	
	cout << "Enter the size of plain text:" << endl;
	cin >> size;
	plain = new char[size];

	cout << "Enter the plain text:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> plain[i];
	}


	cout << "The cipher text will be:" << endl;
	for (int j = 0; j < size; j++)
	{
		cipher= plain[j] + (k % 26);
		cout << cipher;
	}

}