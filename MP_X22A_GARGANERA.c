/*

This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts learned. I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged with my own efforts. I further certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or persons. 

<AIRA JIN B. GARGANERA>, DLSU ID# <12205373>

*/


/*
     Description: <MERGE2WIN game where the values used are all powers of two. Player wins when one, two or three box value/s equal target>
     Programmed by: <GARGANERA, AIRA JIN> <X22A>
     Last modified: <12/05/2022>
     Version: <finalversion.0>
     [Acknowledgements: <none>]
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateTB(int *target_exponent, int *target, int *boxA, int *boxB, int *boxC);
void pressKey (char one);
void printBoxes();
void levelDesc();

int generateExponent(int lower, int upper);
int evaluateBox(int token, int *chosen_box, int *stars);
int chooseLevel (char level, int *n);

int rookieTarget (int boxA, int boxB, int boxC, int target);
int skilledTarget (int boxA, int boxB, int boxC, int target);
int expertTarget (int boxA, int boxB, int boxC, int target);

void welcome();

int main ()
{
	
	int target, target_exponent;
	int boxA, boxB, boxC;
	char level;
	int i=0, n=0, t=0;
	int token=0, chosen_box;
	char chosen_box_letter;
	char again;
	int tokens_used;
	int stars, yes, yes1, yes2, yes3;
	char play_again;
	char one;
	
	int cont1, cont2, cont;
	int stars2, stars3;
	int terminate = 1;
	int x = 0;
	
	srand(time(NULL));
	
	// introduction display
	welcome();
	
	// "terminate" while loop - used for RESTART and PLAYAGAIN functions
	while (terminate == 1 ) {
	
	// generates target and boxes
	generateTB(&target_exponent, &target, &boxA, &boxB, &boxC);	

 //test WIN for expert / skilled

/*	target_exponent = generateExponent(8, 12);
	
	target = 2;
	
	boxA = 2;
	boxB = 2;
	boxC = 4;
*/

	//press '1' to start game
	pressKey (one);	
	
	//choose a level of difficulty	
	levelDesc(); 
	
	// loop for valid input (R/r, S/s and E/e only)
	do {
	
	printf("Choose a level [ ROOKIE (r), SKILLED (s), EXPERT (e) ]:");
	scanf(" %c", &level);
	
	yes = chooseLevel (level, &n);
			
	} while (yes != 1);
	
	//generate tokens, unlimited tokens for rookie, 20 tokens for skilled, 10 tokens for expert
	switch (n) {
		
		case 50:
			
			stars = 0; // initialize 0 stars
			
			printf("\n>>  Your TARGET is %d  <<\n", target);
			
			//prints boxes
			printBoxes( boxA,  boxB,  boxC);
			
			cont = 1; // initialized for "cont" nested loop for ROOKIE - loop for 50 tokens 
		
// "cont" while loop - used for CONTINUE function 		
while (cont == 1) {
				
	i++; // number of loops increases
	t++; // number of tokens increases every loop
			
	// generates token			
	int token = pow(2, generateExponent(1, target_exponent));				
	printf("	TOKEN = %d\n", token);
				
				// user is prompted to choose a box; only valid inputs are accepted
				do {
				
				printf("\nChoose a box: ");
				scanf("  %c", &chosen_box_letter);
				
				switch (chosen_box_letter) {
					case 'A':
					case 'a':
						boxA = evaluateBox(token, &boxA, &stars);
						yes1 = 1;
						break;
					case 'B':
					case 'b':
						boxB = evaluateBox(token, &boxB, &stars);
						yes1 = 1;
						break;
					case 'C':
					case 'c':
						boxC = evaluateBox(token, &boxC, &stars);
						yes1 = 1;
						break;
					default: 
						yes1 = 0;
						printf("Choose a Valid Box!\n");
				}
				
				} while (yes1 != 1);
				
			// display target and (new) boxes
			printf("\n>>  Your TARGET is %d  <<\n", target);		
			printBoxes( boxA,  boxB,  boxC);
			
//	printf("\nYou have used %d tokens.\n", t); // see tokens used
//	printf("\nloops = %d", i); // see number of loops
//	printf("\nstars = %d", stars); // see number of stars
	
					//if player wins
					if (rookieTarget(boxA, boxB, boxC, target) == 1) {
							terminate = 0;
							cont = 0;
							
							// conditions for +10 / +5 stars based on # of tokens
								if (t<=10)
									stars = stars + 10;
								else if (t>10 && t<20)
									stars = stars + 5;
									
						//congratulatory message and displays tokens used and total accumulated stars			
						printf("\nCONGRATULATIONS, you won the game!\n");
						printf("You used up %d tokens and gained %d stars!\n\n", t, stars);
						
					//asks if the player wants to play again; only valid inputs are accepted
					do {
						
						printf("Play again (P) or Quit (Q)? : ");
						scanf("  %c", &play_again);	
								
						switch (play_again) 
						{
							case 'P':
							case 'p':
								t = 0; // reset tokens
								i = 0; //reset i value
								stars = 0; // reset stars
								terminate = 1;
								cont = 0;
								yes2 = 1;
								break;
							case 'Q':
							case 'q':
								i = 0;
								t = 0;
								terminate = 0;
								cont = 0;
								yes2 = 1;
								break;
							default: 
								yes2 = 0; 
								printf("Choose valid option!\n");
						}
							
					} while (yes2 != 1);
					
				}
				
				// if rookie reaches 50 tokens, prompts user to continue, restart or quit; only valid inputs accepted
				else if (i==50) {
						
					do {
						printf("Nice try, but you have used up all of your tokens :(\n");
						printf("Do you want to continue (C), restart (R), or Quit (Q)? : ");
						scanf("  %c", &again);
							
							switch (again) {
								case 'R':
								case 'r':
									i = 0;
									t = 0;
									stars = 0;
									terminate = 1;
									cont = 0;
									yes3 = 1;
									break;
									
								case 'Q':
								case 'q':
									i = 0;
									t = 0;
									terminate = 0;
									cont = 0;
									yes3 = 1;
									break;
									
								case 'C':
								case 'c':
									
									printf("\n>>  Your TARGET is %d  <<\n", target);
									
									printBoxes( boxA,  boxB,  boxC);
			
									i = 0;
									terminate = 0;
									cont = 1;
									yes3 = 1;
								
									break;
									
								default:
									yes3 = 0;
									printf("Enter valid option!");	
									break;
							}
						 
				
				} while (yes3 == 0);
		}
	}

		break;
			
		case 20:
		
		stars2 = 0; // stars are initialized
			
			//displays target and boxes
			printf("\n>>  Your TARGET is %d  <<\n", target);
			printBoxes( boxA,  boxB,  boxC);
			
			cont = 1; // initialize "cont" nested loop for SKILLED - loop for 20 tokens
		
while (cont == 1) {
				
	i++; // number of loops increases
	t++; // number of tokens increases every loop
				

	// token is generated
	int token = pow(2, generateExponent(1, target_exponent));
	printf("	TOKEN = %d\n", token);
	
		//choose a box; only valid inputs accepted				
				do {
				
				printf("\nChoose a box: ");
				scanf("  %c", &chosen_box_letter);
				
				switch (chosen_box_letter) {
					case 'A':
					case 'a':
						boxA = evaluateBox(token, &boxA, &stars2);
						yes1 = 1;
						break;
					case 'B':
					case 'b':
						boxB = evaluateBox(token, &boxB, &stars2);
						yes1 = 1;
						break;
					case 'C':
					case 'c':
						boxC = evaluateBox(token, &boxC, &stars2);
						yes1 = 1;
						break;
					default: 
						yes1 = 0;
						printf("Choose a Valid Box!\n");
				}
				
				} while (yes1 != 1);
			
			// target and boxes are displayed
			printf("\n>>  Your TARGET is %d  <<\n", target);	
			printBoxes( boxA,  boxB,  boxC);
			
	// i (can be used for tokens used)
//	printf("\nYou have used %d tokens.\n", t);
//	printf("\nloops = %d", i);
	
	//stars from boxes;
//	printf("\nstars = %d", stars2);
					
					// if skilled player won
					if (skilledTarget(boxA, boxB, boxC, target) == 1) {
							terminate = 0;
							cont = 0;
							
								if (t<=10)
									stars2 = stars2 + 10;
								else if (t>10 && t<20)
									stars2 = stars2 + 5;
									
						printf("\nCONGRATULATIONS, you won the game!\n");
						printf("You used up %d tokens and gained %d stars!\n\n", t, stars2);
						
					//asks if the player wants to play again; only valid inputs are accepted
					do {
						printf("Play again (P) or Quit (Q)? : ");
						scanf("   %c", &play_again);	
								
						switch (play_again) 
						{
							case 'P':
							case 'p':
								t = 0; // reset tokens
								i = 0; //reset i value
								stars2 = 0; // reset stars
								terminate = 1;
								cont = 0;
								yes2 = 1;
								break;
							case 'Q':
							case 'q':
								i = 0;
								t = 0;
								terminate = 0;
								cont = 0;
								yes2 = 1;
								break;
							default: 
								yes2 = 0; 
								printf("Choose valid option!\n");
						}
							
					} while (yes2 != 1);
					
				}
				
				// if skilled player reaches 20 tokens; only valid inputs are accepted
				else if (i==20) {
						
					do {
						printf("Nice try, but you have used up all of your tokens :(\n");
						printf("Do you want to play again (P) or Quit (Q)? : ");
						scanf("   %c", &play_again);	
								
						switch (play_again) 
						{
							case 'P':
							case 'p':
								t = 0; // reset tokens
								i = 0; //reset i value
								stars2 = 0; // reset stars
								terminate = 1;
								cont = 0;
								yes3 = 1;
								break;
							case 'Q':
							case 'q':
								i = 0;
								t = 0;
								terminate = 0;
								cont = 0;
								yes3 = 1;
								break;
							default: 
								yes3 = 0; 
								printf("Choose valid option!\n");
						}
					} while (yes3 == 0);
						 
				}
			
			} 
			
			break;
			
		case 10:
		
		stars3 = 0; // stars are initialized
		
		printf("\n>>  Your TARGET is %d  <<\n", target);
		printBoxes( boxA,  boxB,  boxC);
		
			
			cont = 1; // initialize cont nested loop for EXPERT - loop for 10 tokens
	
while (cont == 1) {
				
	i++; // number of loops increases
	t++; // number of tokens increases every loop
				
	// token is generated		
	int token = pow(2, generateExponent(1, target_exponent));			
	printf("	TOKEN = %d\n", token);
				
				//choose a box; only valid inputs are accepted
				do {
				
				printf("\nChoose a box: ");
				scanf("  %c", &chosen_box_letter);
				
				switch (chosen_box_letter) {
					case 'A':
					case 'a':
						boxA = evaluateBox(token, &boxA, &stars3);
						yes1 = 1;
						break;
					case 'B':
					case 'b':
						boxB = evaluateBox(token, &boxB, &stars3);
						yes1 = 1;
						break;
					case 'C':
					case 'c':
						boxC = evaluateBox(token, &boxC, &stars3);
						yes1 = 1;
						break;
					default: 
						yes1 = 0;
						printf("Choose a Valid Box!\n");
				}
				
				} while (yes1 != 1);
			
			// display target and boxes
			printf("\n>>  Your TARGET is %d  <<\n", target);
			printBoxes( boxA,  boxB,  boxC);
			
	// i (can be used for tokens used)
//	printf("\nYou have used %d tokens.\n", t);
//	printf("\nloops = %d", i);
	
	//stars from boxes;
//	printf("\nstars = %d", stars3);	
					
					// if expert wins; only valid inputs are accepted
					if (expertTarget(boxA, boxB, boxC, target) == 1) {
							terminate = 0;
							cont = 0;
							
								if (t<=10)
									stars3 = stars3 + 10;
								else if (t>10 && t<20)
									stars3 = stars3 + 5;
									
						printf("\nCONGRATULATIONS, you won the game!\n");
						printf("You used up %d tokens and gained %d stars!\n\n", t, stars3);
						
					//asks if the player wants to play again; only valid inputs are accepted
					do {
						printf("Play again (P) or Quit (Q)? : ");
						scanf("  %c", &play_again);	
								
						switch (play_again) 
						{
							case 'P':
							case 'p':
								t = 0; // reset tokens
								i = 0; //reset i value
								stars3 = 0; // reset stars
								terminate = 1;
								cont = 0;
								yes2 = 1;
								break;
							case 'Q':
							case 'q':
								i = 0;
								t = 0;
								terminate = 0;
								cont = 0;
								yes2 = 1;
								break;
							default: 
								yes2 = 0; 
								printf("Choose valid option!\n");
						}
							
					} while (yes2 != 1);
					
				}
				
				// if expert reaches 10 tokens; only valid inputs are accepted
				else if (i==10) {
						
					do {
						printf("Nice try, but you have used up all of your tokens :(\n");
						printf("Do you want to play again (P) or Quit (Q)? : ");
						scanf("  %c", &play_again);	
								
						switch (play_again) 
						{
							case 'P':
							case 'p':
								t = 0; // reset tokens
								i = 0; //reset i value
								stars3 = 0; // reset stars
								terminate = 1;
								cont = 0;
								yes3 = 1;
								break;
							case 'Q':
							case 'q':
								i = 0;
								t = 0;
								terminate = 0;
								cont = 0;
								yes3 = 1;
								break;
							default: 
								yes3 = 0; 
								printf("Choose valid option!\n");
						}
					} while (yes3 == 0);
						 
				}
			
			} 
			
			break;
			
		default:
			printf("ERROR"); // something is wrong with the variable n
			break;

	
    }

} 
	
	
	return 0;

}
		
// FUNCTIONS USED:

void welcome()
{
//	printf("======================================================================================================================\n");
	printf("======================================================================================================================\n\n");
	printf("					WELCOME PLAYER!\n\n");
	printf("		 MERGE2WIN is a game that challenges you by using powers of 2.\n");
	printf("		  You are going to be given a token, and then a target value.\n		You will then be presented 3 boxes, each with a designated value.\n");
	printf("		    Your goal is to use the tokens to manipulate the boxes, \n			such that the boxes will equal the target value.\n\n");
	printf("======================================================================================================================\n");
//	printf("======================================================================================================================\n");
}
	
void printBoxes(int boxA, int boxB, int boxC)
{
printf("\n");	
printf("||======================||\n");
printf("||			||\n");
printf("||	box A = %d	||\n", boxA);
printf("||			||\n");
printf("||======================||\n");
printf("\n");
printf("||======================||\n");
printf("||			||\n");
printf("||	box B = %d	||\n", boxB);
printf("||			||\n");
printf("||======================||\n");
printf("\n");
printf("||======================||\n");
printf("||			||\n");
printf("||	box C = %d	||\n", boxC);
printf("||			||\n");
printf("||======================||\n");
printf("\n");

}	

void levelDesc()
{
	
	printf("||	ROOKIE\n||	- Unlimited tokens! Unlimited chances of winning!\n");
	printf("||\n");
	printf("||	SKILLED\n||	- Give it all you've got with 20 tokens!\n");
	printf("||\n");
	printf("||	EXPERT\n||	- Test your limits with only 10 tokens!\n\n");
}
	
/*   
            <Description of function>
     Precondition: <target_exponent, target, boxA, boxB, and boxC are non-negative numbers>
     @param <target_exponent> <exponent of target number (m in 2^m)>
     @param <target> <value of target>
     @param <boxA> <value of box A>
     @param <boxB> <value of box B>
     @param <boxC> <value of box C>
     @return <updated values for target_exponent, target, boxA, boxB, and boxC>
*/

void generateTB(int *target_exponent, int *target, int *boxA, int *boxB, int *boxC)
{
	*target_exponent = generateExponent(8, 12);
	
	*target = pow(2, *target_exponent);
	
	*boxA = pow(2, generateExponent(1, *target_exponent - 1 ));
	*boxB = pow(2, generateExponent(1, *target_exponent - 1 ));
	*boxC = pow(2, generateExponent(1, *target_exponent - 1 ));

}


/*   
     <function generates a random number between (lower value) and (upper value)>
     Precondition: <lower and upper are non-negative values>
     @param <lower> <minimum value of the randomly-generated exponent>
     @param <upper> <maximum value of the randomly-generated exponent>
     @return <randomly-generated exponent>
*/

int generateExponent(int lower, int upper)
{
	return rand() % ( upper - lower + 1 ) + lower;
}

/*   
     <function evaluates if token value is greater than, less than or equal to value of chosen box>
     Precondition: <token, chosen_box, and stars are non-negative values>
     @param <token> <value of token>
     @param <chosen_box> <value of the chosen box>
     @param <stars> <number of stars>
     @return <new value of the chosen box>
*/

int evaluateBox(int token, int *chosen_box, int *stars)
{
	*stars;
	
	if (token < *chosen_box)
		*chosen_box = token;
	else if (token > *chosen_box)
		*chosen_box = token / *chosen_box;
	else if (token == *chosen_box) {
		*chosen_box = *chosen_box * 2;
		*stars += 1;
		printf("\nYay! You earned 1 star!\n");
	}
		
	return *chosen_box;
		
}

/*   
     <function loops until user inputs character '1'>
     Precondition: <single-digit input>
     @param <one> <user's character input>
     @return <none>
*/

void pressKey (char one)
{	
	do {
		printf("\nARE YOU READY 2 WIN?\nPress 1 to start the game!\n");
		scanf(" %c", &one);
	}
	
	while (one != '1');
	printf("\nGood luck on your journey, PLAYER!\n\n");
} 

/*   
     <function determines if input from user is valid and asks for valid input if not>
     Precondition: <single-digit input>
     @param <level> <chosen level of difficulty>
     @param <n> <variable for test cases>
     @return <variable "yes" = 1 if valid, otherwise it asks for valid input>
*/

int chooseLevel (char level, int *n) {
	
	int yes;
	
		switch (level) {
		case 'R':
		case 'r':
			*n = 50;
			yes = 1;
		break;
		
		case 'S':
		case 's':
			*n = 20;
			yes = 1;
		break;
		
		case 'E':
		case 'e':
			*n = 10;
			yes = 1;
		break;
		default: printf("Choose a valid level!\n");
		}
		
		return yes;
	}            

/*   
     <function evaluates if user wins (ROOKIE)>
     Precondition: <boxA, boxB, boxC, and target are non-negative values>
     @param <boxA> <value of box A>
     @param <boxB> <value of box B>
     @param <boxC> <value of box C>
     @param <target> <value of target>
     @return <result of condition (atleast one of the boxes should equal target)>
*/

int rookieTarget (int boxA, int boxB, int boxC, int target)
{
	return (target == boxA || target == boxB || target == boxC);
}
	
/*   
     <function evaluates if user wins (SKILLED)>
     Precondition: <boxA, boxB, boxC, and target are non-negative values>
     @param <boxA> <value of box A>
     @param <boxB> <value of box B>
     @param <boxC> <value of box C>
     @param <target> <value of target>
     @return <result of condition (two boxes should equal target)>
*/

int skilledTarget (int boxA, int boxB, int boxC, int target)
{
	return ((target == boxA && target == boxB ) || (target == boxA && target == boxC ) || (target == boxC && target == boxB));
}

/*   
     <function evaluates if user wins (EXPERT)>
     Precondition: <boxA, boxB, boxC, and target are non-negative values>
     @param <boxA> <value of box A>
     @param <boxB> <value of box B>
     @param <boxC> <value of box C>
     @param <target> <value of target>
     @return <result of condition (all boxes should equal target)>
*/

int expertTarget (int boxA, int boxB, int boxC, int target)
{
	return (target == boxA && target == boxB && target == boxC);
}
