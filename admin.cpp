#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int c = 0;

//Class to create word objects
class collection_of_words
{
	public:
	char game_word[80];
	void input()
	{
		//gets(game_word);
		//cin.clear();
		//cin.sync();
		cin.ignore();
		cin.getline(game_word,80);
	}
	void display()
	{
		//puts(game_word);
		cout << game_word << endl;
	}
	char *retname()
	{
		return game_word;
	}
};

//Function to create a new category file
void create_file(char FN[50])
{
	collection_of_words hangman;
	char choice= 'y';
	//system("cls");
	ofstream fout;
	fout.open(FN/*fstream::out*/,ios::out);
	while(choice=='y'||choice=='Y')
	{
		cout << "Enter word: " << endl;
		hangman.input();
		//gets(hangman.game_word);
		fout << hangman.game_word << "\n";
		cout << "Do you want to enter more words? (y/n) " << endl;
		cin >> choice;
		cout << endl;
		c++;
	}
	fout.close();
}

//Function to view the contents ofa category file
void show_file(char FN[50])
{
	collection_of_words hangman;
	//system("cls");
	ifstream fin(FN);
	cout << "Words in the file are: " << endl;
	while(fin)
	{
		fin.getline(hangman.game_word,80);
		if(fin)
			cout << hangman.game_word << endl;
	}
	fin.close();
}

//Function to add words to a category file
void append_file(char FN[50])
{
	collection_of_words hangman;
	char choice= 'y';
	//system("cls");
	ofstream fout(FN, ios::app);
	while((choice=='y')||(choice=='Y'))
	{
		cout << "Enter word: " << endl;
		hangman.input();
		fout << hangman.game_word;
		cout << "Do you want to enter more words? (y/n) " << endl;
		cin >> choice;
		cout<<endl;
	}
}

//Main driver function
int main()
{
	int select;
	char fn[50];
	cin.clear();
	cin.sync();
	char ch= 'y';
	while((ch=='y')||(ch=='Y'))
	{
		cout << "Select task: ";
		cout << "\n1) Create file";
		cout << "\n2) View file";
		cout < <"\n3) Append file" << endl;
		cin >> select;
		switch(select)
		{
			case 1:
			cout << "Enter file name: "<<endl;
			//gets(fn);
			cin >> fn;
			strcat(fn, ".txt");
			create_file(fn);
			break;
			case 2:
			cout << "Enter file name: " << endl;
			//gets(fn);
			cin >> fn;
			strcat(fn,".txt");
			show_file(fn);
			break;
			case 3:
			cout << "Enter file name: " << endl;
			//gets(fn);
			cin >> fn;
			strcat(fn, ".txt");
			append_file(fn);
			break;
			default: cout << "\n Wrong choice!" << endl;
		}
		cout << "Do you want to continue? (y/n)" << endl;
		cin >> ch;
		cout<<endl;
	}
	return 0;
}
