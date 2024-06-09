#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	char *plain;
	char *sPlain;
	int size;

	cout << "Enter the size of plain text:" << endl;
	cin >> size;
	
	plain = new char[size];
	sPlain= new char[size];

	cout << "Enter the plain text:" << endl;
	for (int i = 0; i < size; i++)
		cin >> plain[i];
		
	char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };
 
    char key[26];
    for (int i = 0; i < 26; i++)
        key[i] = alphabet[rand()%26] ;

	 
	 cout<<"The random key is:"<<endl;
	  for (int i = 0; i < 26; i++)
	    cout<<key[i]<<"\t";
	 
    for(int i=0; i<size;i++)
	{
		int j=int(plain[i])-65;		
		sPlain[i]=key[j];
	}
	
	cout << endl << "The encrpted text is" << endl;
	for (int l = 0; l < size; l++)
	   cout << sPlain[l];
	

}
