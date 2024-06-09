#include<iostream>
using namespace std;
int main()
{
	
	int psize;

	cout << "Enter the size of plain text:" << endl;
	cin >> psize;

	char **plain = new char*[psize];
	for (int i = 0; i < psize; i++)
		plain[i] = new char[1];

	cout << "Enter the plain text:" << endl;
	for (int i = 0; i < psize; i++)
		cin >> plain[i];

	char key[3][3];
	

	cout << "Enter the key text:" << endl;
	for (int i = 0; i < 3; i++)
		for(int j=0;j<3;j++)
		  cin >> key[i][j];

	//char encryp[psize][1];
	char** encryp = new char* [psize];
	for (int i = 0; i < psize; i++)
		encryp[i] = new char[1];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 1; ++j)
			for (int k = 0; k < 3; ++k)
			{
				encryp[i][j] += key[i][k] * plain[k][j];
			}
	
	
	for (int i = 0; i < psize; i++)
		for (int j = 0; j < 1; j++)
			encryp[i][j] = encryp[i][j] % 26;

	cout << "The encrypted text is:" << endl;
	for (int i = 0; i < psize; i++)
		for (int j = 0; j < 1; j++)
			cout << encryp[i][j];


}