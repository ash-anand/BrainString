#include <iostream>
#include <stdio.h>
#define ITER 9 //Increments inside the loop

using namespace std;

string brainfuck(char c){
	//cout<<c<<"\t";
	int quo = (int)c/ITER;  //Number of times loop runs
	int rem = (int)c%ITER;   //Number of increments after loop
	string returnString;

	for(int i = 0; i < quo; i++){
		returnString += "+";     //Loop incrementation
	}
	returnString += "[ > ";        //Enter loop
	for(int i = 0; i < ITER; i++){
		returnString += "+";     //Inside loop increment
	}
	returnString += "< - ] > ";     //Decrement the last element and continue the loop
	for(int i = 0; i < rem; i++)
		returnString += "+";
	returnString += ". <\n";	//Print the value and go to iterator
	for(int i = 0; i < rem; i++)
		returnString += "-"; //Make iterator zero
	for(int i = 0; i < quo; i++){
		returnString += "+";     //Loop incrementation
	}
	returnString += "[ > ";        //Enter loop
	for(int i = 0; i < ITER; i++){
		returnString += "-";     //Inside loop decrement
	}
	returnString += "< - ] > ";     //Decrement the last element and continue the loop
	for(int i = 0; i < rem; i++)
		returnString += "-";
	returnString += "<";
	for(int i = 0; i < rem; i++)
		returnString += "-"; //Make iterator zero
	returnString += "\n";	//Looks good
	return returnString;
}
int main(int argc, char ** argv){

	string bf;
	string input;
	cout<<"Enter the String : ";
	getline(cin,input);
	for(int j = 0; j < input.length(); j++){
		bf += brainfuck(input[j]);
	}
	cout<<bf<<endl;
	return 0;
}