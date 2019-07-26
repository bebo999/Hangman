#include <fstream>
#include<stdio.h>
#include <string>
#include <iostream>
#include<conio.h>
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
}





int main(){
	
	cout<<"Welcome to my Hangman game\n "<<endl;;
	cout<<"\t\t****-----*******-----******------****"<<endl;
	string words[1000];
	 int wordNumber;
	 wordNumber=ReadFile(words);
	
	
	
	
	
	
	
	
	
	
	
	
	
}
