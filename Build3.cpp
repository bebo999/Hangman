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

 void SetGame(string pickedWord, string &missing){
 	int i=0;
 	int len=pickedWord.length();
 	for(i=0;i<len;i++){
 		missing[i] = '_';
	 }
 } //return an array of characters ex: _ _ _ _
 
 void Game(string pickedWord, string &missing){
 	int flag=0;
 	int i=0;
 	int j;
 	int left=5;
 	//char wrong[5];
 	char guess;
 	int right=0;
 	
 	while(left!=0){
	     cout<<"\t\t\t\t";
 	   	for(i=0;i<missing.length();i++){
 			cout<<missing[i]<<" ";
		 }
		 cout<<"\n\nGuess the missing letters \n";
	     cout<<"Lives left:"<<left;
	     //cout<<"Letters Guessed"<<wrong[0]<<wrong[1]<<wrong[2]<<wrong[3]<<wrong[4];
	     cout<<"\n";
	     cin>>guess;
	     j=right;
	    for(i=0;i<pickedWord.length();i++){
	    	 if(guess==pickedWord[i]){
	    	 	missing[i]=pickedWord[i];
	    	 	right++;
			 }
		}
		if(j==right){
			left--;
		}
		system("CLS");
       if(right==pickedWord.length()){
		 flag=1;
			break;
	   }
      
 	} 
 	
 	if(flag==0){
 		cout<<"Your lives ran out, the word is: "<<pickedWord;
	 }
	 else 	cout<<"Congratulations the word is: "<<pickedWord;

 }

int main(){
	cout<<"\t\t\tWelcome to my Hangman game\n "<<endl;;
	cout<<"\t\t****-----*******-----******------****"<<endl;
	cout<<"Press any key to start"<<endl;
	getch();
	system("CLS");
	loop1:string words[1000];
	string pickedWord;
	int wordNumber;
	int restart;
	wordNumber=ReadFile(words);
	pickedWord=RandomGenerator(wordNumber,words);
	string missing=pickedWord;
	SetGame(pickedWord,missing);
	Game(pickedWord,missing);
	
	cout<<"\n\n Press any key to play again\n\n";
	getch();
	system("CLS");
	goto loop1;
}
