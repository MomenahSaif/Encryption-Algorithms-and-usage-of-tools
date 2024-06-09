#include<iostream>
#include<string>
using namespace std;
void Matrix(char **matrix,char *key,int ksize)
{
	int x = 0, z = 0, y = 0, i = 1, MyFlag = 0;
	matrix[0][0] = key[0];
	do
	{   
		if (i < ksize)
		{for (int j = 0; j < i; j++)
		 {if (key[j] == key[i])
		  {
			MyFlag = 1;
			break;
	      }
	     }   
		
			if (MyFlag == 0)
			{
				if (y<4)
				   y++;
				else
				{ x++;
				  y=0;
				}
			
				matrix[x][y] = key[i];
			}
			MyFlag = 0;
			i++;
		}
		else
		{  for (int j = 0; j < ksize; j++)
			{
				if (('A' + z) == key[j])
				{
					MyFlag = 1;
					break;
				}
			}
			if ((MyFlag == 0) && (('A'+z)!='J'))
			{
				if (y<4)
				  y++;
				else
				{
					x++;
					y=0;
				}
				matrix[x][y] = ('A' + z);
			}
			MyFlag = 0;
			z++;
		}	
	}while((x < 4) || (y < 4));
}





bool findHor(char &fChar, char &sChar, char **matrixH)
{
	bool myFlag=false;
	int myRow;
	char fChar1, sChar1;

	for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			if (matrixH[i][j]==fChar)
			{
				myFlag=true;
				myRow=i;
				fChar1=(j==4)?matrixH[i][0]:matrixH[i][j+1];
				break;
			}		
		}
	if (myFlag)
	{
		myFlag=false;
		for (int j=0;j<5;j++)
		{
			if(matrixH[myRow][j]==sChar)
			{
				myFlag=true;
				sChar1=(j==4)?matrixH[myRow][0]:matrixH[myRow][j+1];
				break;
			}
		}
	}
	if (myFlag)
	{
		fChar=fChar1;
		sChar=sChar1;
	}
	return myFlag;
}

bool findVer(char &fChar, char &sChar, char **matrixV)
{
	bool myFlag=false;
	int myCol;
	char fChar1, sChar1;

	for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			if (matrixV[j][i]==fChar)
			{
				myFlag=true;
				myCol=i;
					fChar1=(j==4)?matrixV[0][i]:matrixV[j+1][i];
				break;
			}		
		}
	if (myFlag)
	{
		myFlag=false;
		for (int j=0;j<5;j++)
		{
			if(matrixV[j][myCol]==sChar)
			{
				myFlag=true;
				sChar1=(j==4)?matrixV[0][myCol]:matrixV[j+1][myCol];
				break;
			}
		}
	}
	
	if (myFlag)
	{
		fChar=fChar1;
		sChar=sChar1;
	}
	
	return myFlag;
}


void findDia(char &fChar, char &sChar, char **matrixD)
{
	bool myFlag=false;
	int Row1,Row2,Col1,Col2;
	char fChar1, sChar1;

	for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			if (matrixD[i][j]==fChar)
			{
				Row1=i;
				Col1=j;
				break;
			}		
		}

	for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			if (matrixD[i][j]==sChar)
			{
				Row2=i;
				Col2=j;
				break;
			}		
		}
		fChar=matrixD[Row1][Col2];
		sChar=matrixD[Row2][Col1];
}



void Encrypt(string sText, char **matrix)
{	
	string finalString=sText;
	int k=2;
	for(int i=0;i<sText.size();i=i+2)	
	{
		if (findHor(finalString[i],finalString[i+1],matrix))
			k=0;
		else if (findVer(finalString[i],finalString[i+1],matrix))
			k=1;
		else
		{
			k=2;
			findDia(finalString[i],finalString[i+1],matrix);
		}
		
		
	}
	
	cout<<" Plain Text: "<<sText<<endl<<" Encrypted Text:"<<finalString;
}

int main()
{
	int ksize1=0;
	string myText;
	char* key1 = new char[ksize1];
	char** matrix1= new char*[5];
    for (int i = 0; i < 5; i++)
    	matrix1[i] = new char[5];
	
	cout << "Enter key size:" << endl;
	ksize1=8; cin >> ksize1;

	cout << "Enter the key:" << endl;
	for (int i = 0; i < ksize1; i++)
		cin >> key1[i];

	cout << "Enter required Text:" << endl;
	cin >> myText;

	Matrix(matrix1,key1,ksize1);
	Encrypt(myText,matrix1);

	
}
