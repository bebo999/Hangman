#include<fstream>
#include<stdio.h>
#include<string>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int ReadFile(string (&words)[1000]){
	
	int i=0;
	string line;
	ifstream file("Words.txt");
	if (file.is_open())
	{
		while(getline(file,line))
		{   
			words[i]=line;
			i++;
		}
		file.close();
	}	
	return i;
}  //read file containing words and puts them in an array of strings


string RandomGenerator(int wordNumber,string (&words)[1000]){
	int random;
	srand(time(NULL));
	random=rand() % wordNumber;
	return words[random];
}    // picks a rondom word and returns it


int main(){
	
	cout<<"Welcome to my Hangman game\n "<<endl;;
	cout<<"\t\t****-----*******-----******------****"<<endl;
	string words[1000];
	string pickedWord;
	int wordNumber;
	wordNumber=ReadFile(words);
	pickedWord=RandomGenerator(wordNumber,words);
     
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
}
