#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<cctype>
#include<locale.h>

using namespace std;

char word[300][50];
int c=0;
locale loc;

//Class to manage the words being read from the category files
class collection_of_words
{
	public:
	char game_word[50];
	char *retname()
	{
		return game_word;
	}
};

//Function to read category files and store them in a 2-D array
void admin_file(char FN[50])
{
	c = 0;
	collection_of_words hangman;
	ifstream fin;
	fin.open(FN);
	while(fin)
	{
		fin.getline(hangman.game_word, 80);
		if(fin)
			strcpy(word[c++],hangman.game_word);
	}
	fin.close();
}

//Functions to display the game word
void display(char str[])
{
	for(int i=0; str[i]!='\0'; i++)
	cout << str[i] << " ";
	cout << endl;
}
void change(int q, char NEW[], char ch)
{
	for(int i=0; NEW[i]!='\0'; i++)
	if(i==q)
		NEW[i] = ch;
}

//Main driver function
int main()
{
	int d=0;
	char fn[50],ab[100];
	char ch= 'y';
	char Copy[50];
	char dot[50];
	while((ch=='y')||(ch=='Y'))
	{
		cout << "Enter the index number of the category: ";
		cout << "\n1) Countries";
		cout << "\n2) Books";
		cout << "\n3) Music";
		cout << "\n4) Custom File" << endl << endl;
		cin >> d;
		if(d==1)
			strcpy(fn, "Countries");
		else if(d==2)
			strcpy(fn, "Books");
		else if(d==3)
			strcpy(fn, "Music");
		else if(d==4)
		{
			char fname[40];
			cout << "Enter file name:";
			cin.getline(fname,40);
			strcpy(fn, fname);
		}
		strcat(fn, ".txt");
		strcpy(ab, " *LOCATION OF YOUR TXT FILES* ");
		strcat(ab, fn);
		admin_file(ab);
		srand(time(NULL));
		int a;
		a = rand()%(c+1);
		cout << "\nYour word is:" << endl;
		int i = 0;
		for(i=0; i<50; i++)
		{
			if(word[a][i]=='\0')
				break;
			else if((word[a][i]=='A')
				  ||(word[a][i]=='E')
			      ||(word[a][i]=='I')
				  ||(word[a][i]=='O')
				  ||(word[a][i]=='U')
				  ||(isalpha(word[a][i])==0))
			{
				cout << word[a][i] << " ";
				dot[i] = word[a][i];
			}
			else
			{
				cout << "___ ";
				dot[i] = '_';
			}
			Copy[i]= word[a][i];
		}
		Copy[i]= '\0';
		dot[i]= '\0';
		char draw[7][11]=
		{" (* *)",
		 "   | ",
		 "  /|\\",
		 " / | \\",
		 "   | ",
		 "  / \\",
		 " /   \\"};
		int chance = 0;
		while(chance<7)
		{
			int z = strlen(Copy);
			int flag = 0;
			char guess;
			cout << "\n\n\nEnter a letter: " << endl;
			cin >> guess;
			for(int i=0; i<z; i++)
			{
				if(guess==Copy[i])
				{
					change(i, dot, guess);
					flag++;
				}
			}
			if(strcmp(dot,Copy)==0)
			{
				display(dot);
				cout << "You have won the game! :)" << endl << endl;
				cout << "Do you want to play another game? (y/n)" << endl;
				cin >> ch;
				cout << endl;
				system("cls");
				break;
			}
			if(flag>0)
				display(dot);
			if(flag==0)
			{
				cout << "\nWrong letter\n" << endl;
				chance++;
				for(int j=0; j<chance; j++)
				{
					cout << draw[j];
					cout << endl;
				}
				cout << endl;
				display(dot);
				int w = 7-chance;
				if(w!=0)
					cout << "You have " << w << " chance(s) left" << endl;
				else
				{
					cout << "\n\nYou have lost the game :(\n\n" << "Your word was: ";
					display(Copy);
					cout << endl;
					cout << "Do you want to play another game? (y/n)" << endl;
					cin >> ch;
					cout << endl;
				}
			}
		}
	}
	return 0;
}