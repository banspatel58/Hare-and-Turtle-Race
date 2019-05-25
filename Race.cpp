//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// banspate

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#define RACE_LENGTH 50

void advanceTortoise(int* ptrTortoise);
void advanceHare(int* ptrHare);
void printPosition(int* ptrTortoise, int* ptrHare);

int main(){
	//both hare and tortoise starts from zero space and race is about fifty spaces.
	int ptrTortoise = 0;
	int ptrHare = 0;
	
	std::cout<< " Welcome to CSCI 240s Tortoise vs. Hare race! " <<std::endl;
	
	//seed the random function once
	srand(time(NULL));
	
	//as long as either tortoise or the hare reaches the finish line, this function repeats itself.
	while ( ptrTortoise != RACE_LENGTH &&	ptrHare != RACE_LENGTH ){
		
		//calls the function that rolls a dice for Hare as hare rolls dice first and hence hare makes it move
		advanceHare(&ptrHare);
		
		//calls the function that rolls a dice for tortoise so that tortoise can make its move
		advanceTortoise(&ptrTortoise);
		
		//calls the function in order to track, update and print the position of tortoise and hare
		printPosition(&ptrTortoise, &ptrHare);
		
	}
	
	//if tortoise reaches the finish line first, tortoise wins the race else hare wins
	if ( ptrTortoise > ptrHare){
		std::cout<<" The Tortoise wins! Slow and steady wins the race! " <<std::endl;
	}else{
		std::cout<<" The hare wins... " <<std::endl;
	}
}

// defining a function that tracks and updates the move of hare
void advanceHare(int* ptrHare){
	
	//generating a random number between 1 - 10
	int diceH = rand()%10+1;
	
	//there is 10% probability that hare moves 1 space.
	if(diceH == 1){
		
		*ptrHare = *ptrHare + 1;
		
	}
	//there is 30% probability that hare moves 2 spaces.
	else if( diceH >= 2 && diceH <= 4){
		
		*ptrHare = *ptrHare + 2;
		
	}
	//there is 30% probability that hare moves 3 spaces.
	else if( diceH >= 5 && diceH <= 7){
		
		*ptrHare = *ptrHare + 3;
		
	}
	//there is 10 % probability that hare takes rst as a result of which it moves back 2 spaces.
	else if( diceH == 8){
		
		*ptrHare = *ptrHare - 2;
		
	}
	//there is 20% probability that hare takes a nap resulting moving back 3 spaces.
	else{
		
		*ptrHare = *ptrHare - 3;
		
	}
	
	//To check that the hare doesn't crosses out the finish line nor goes beyond the starting line.
	//if the position of Hare goes beyond finish line(50) than set the position to 50
	if ( *ptrHare > 50 ){
		
		*ptrHare = 50;
		
	}
	//if the position of Hare goes less than 1 keep the hare positio on 1 don't go on negative direction
	else if ( *ptrHare < 1 ){
		
		*ptrHare = 1;
		
	}
	//the position of hare remains the same.
	else{
		
		*ptrHare = *ptrHare;
		
	}
}

// defining a function that tracks and updates the move of tortoise
void advanceTortoise(int *ptrTortoise){
	
	//generating a ranom number between 1 - 10
	int dice = (rand() % 10) + 1;
	
	//Since there is 60% probability that the tortoise moves one space.
	if( dice >= 1 && dice <= 6){
		
		*ptrTortoise = *ptrTortoise + 1;
		
	}
	//there is 10% probability that tortoise moves 2 spaces.
	else if( dice == 7 ){
		
		*ptrTortoise = *ptrTortoise + 2;
		
	}
	//there is 10% probability that tortoise moves 3 spaces.
	else if( dice == 8){
		
		*ptrTortoise = *ptrTortoise + 3;
		
	}
	//there is 20% probability that tortoise moves zero space.
	else{
		
		*ptrTortoise = *ptrTortoise;
		
	}
	
	//To check that the tortoise doesn't cross the finish line nor goes beyond the starting line
	//if the position of Tortoise goes beyond finish line(50) than set the position to 50
	if ( *ptrTortoise > 50 ){
		
		*ptrTortoise = 50;
		
	}
	//if the position of tortoise goes less than 1 keep the Tortoise position on 1 don't go on negative direction
	else if ( *ptrTortoise < 1 ){
		
		*ptrTortoise = 1;
		
	}
	//else the position is according to result when dice is rolled
	else{
		
		*ptrTortoise = *ptrTortoise;
		
	}
}
//defining a function that prints the position of tortoise and hare.
void printPosition(int* ptrTortoise, int* ptrHare){
	
	int T = *ptrTortoise;
	int H = *ptrHare;
	
	
	//if Hare is ahead of Tortoise
	if( H > T)
	{ 

		// set width of T to print tortoise position and than set width H-T and than print Hare position
		std::cout << std::setw(T) << "T" << std::setw(H - T) << "H";
		//if H is greater than T than the finish line would be 
		std::cout << std::setw(RACE_LENGTH - H + 1) << "|" << std::endl;
		
	}
	//If both hare and tortoise are on the same position
	else if ( T == H){
		
		//Tortoise kindly gives its space to hare by moving back 1 space and hare remains at the same position
		std::cout << std::setw(T - 1) << "T" << std::setw(H - T) << "H";
		//the finish line width would be the space between hare as hare and the endline (51 spaces from start)
		std::cout << std::setw(RACE_LENGTH - H + 1) << "|" << std::endl;
		
	}
	//else we have the position of tortoise ahead of the position of the hare
	else{
		
		//set width of hare to print hare position and since tortoise is ahead of hare, the width between tortoise and hare would be //T - H
		std::cout << std::setw(H) << "H" << std::setw(T - H) << "T";
		//the finish line width would be the space between tortoise as tortoise and the endline (51 spaces from start)
		std::cout << std::setw(RACE_LENGTH - T + 1) << "|" << std::endl;
		
	}
}
	