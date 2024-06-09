#include<iostream>
using namespace std;
int main()
{
	char l1, key ,choice;
	do {
		cout << "Enter letters" << endl;
		cin >> l1;
		cout << "Enter key" << endl;
		cin >> key;

		char encrypt = (l1 + key) % 26;
		encrypt = encrypt + 'A';


		cout << "The cipher letter will be: " << encrypt << endl;

		char decrypt = (encrypt - key + 26) % 26;
		decrypt = decrypt + 'A';

		cout << "The decrypted letter is: " << decrypt << endl;

		cout << "Do you want to enter another character:" << endl;
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');


}