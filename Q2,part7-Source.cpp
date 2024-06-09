#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string PlainText = "TRANSPOSITIONCIPHER";
	//string Key = "SECRET";
	string Key, PlainText;
	
	cout << " Enter key:" << endl;
	getline(cin, Key);
	cout << "Enter plain text: " << endl;
	getline(cin, PlainText);

    string sKey = Key;
   int KeySize = Key.size();
	int matrixRNo = (PlainText.size() % KeySize > 0) ? ((PlainText.size() / KeySize) + 1) : (PlainText.size() / KeySize);

	char** matrix1 = new char* [matrixRNo];//matrixRNo
	for (int i = 0; i < matrixRNo; i++)
		matrix1[i] = new char[KeySize];//KeySize

	int x = 0;
	for (int i = 0; i < matrixRNo; i++)
		for (int j = 0; j < KeySize; j++)
		{
			if (x > (PlainText.size() - 1))
				matrix1[i][j] = ' ';
			else
			{
				matrix1[i][j] = PlainText[x];
				x++;
			}
		}
	cout << endl;
	

	char temp;
	for (int i = 0; i < KeySize; i++)
	{
		for (int j = 0; j < KeySize - i - 1; j++)
		{
			if (Key[j] > Key[j + 1])
			{
				temp = Key[j];
				Key[j] = Key[j + 1];
				Key[j + 1] = temp;
				//===============================================
				for (int k = 0; k < matrixRNo; k++)
				{
					temp = matrix1[k][j];
					matrix1[k][j] = matrix1[k][j + 1];
					matrix1[k][j + 1] = temp;
				}
			}
		}
	}
	//==============================================================
	
	string sPlainText = PlainText;
	
    x = 0;
	for (int i = 0; i < KeySize; i++)
	{
		for (int j = 0; j < matrixRNo; j++)
		{
			if (matrix1[j][i] != ' ')
			{
				sPlainText[x] = matrix1[j][i];
				x++;
			}
		}
	}

	cout << " The encrypted text is:";
	cout << endl << sPlainText;

}

