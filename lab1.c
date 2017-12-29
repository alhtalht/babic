//Alina Thai
#include <stdio.h>
#include <math.h>
int sum_cards(char face, int sum);
int main(){
	//create variables
	char ans, c1,c2,c3,c4,c5, a1,a2,a3,a4,a5;
	int cards, sum, game = 1;
	while (game == 1){
		sum = 0;
		//get number of cards
		printf("Enter a number of cards(2-5): ");
		scanf("%d", &cards);
		//check number of cards
		if(cards >= 2 && cards <= 5){
			printf("Number of cards entered = %d\n", cards);
			//go to the next line, skips scanning the extra characters, discard them
			while(getchar()!='\n');
			printf("Enter the faces of the cards, 2-9, t, j, q, k, a: ");
			//cases for each input
			if(cards == 2){
				//get cards
				scanf(" %c %c", &c1, &c2);
				//go to the next line, skips scanning the extra characters, discard them
				while(getchar()!='\n');
				printf("Faces of cards entered = %c %c\n", c1, c2);
				//check to see if there's any invalid card
				if(sum_cards(c1, sum) == 0 || sum_cards(c2,sum) == 0)
					sum = 0;					
				else{
					sum = sum + sum_cards(c1, sum);
					sum = sum + sum_cards(c2, sum); 
				}				
			}
			else if(cards == 3){
				//get cards
				scanf(" %c %c %c", &c1, &c2, &c3);
				//go to the next line, skips scanning the extra characters, discard them
				while(getchar()!='\n');
				printf("Faces of cards entered = %c %c %c\n", c1, c2, c3);
				//check to see if there's any invalid card
				if(sum_cards(c1, sum) == 0 || sum_cards(c2,sum) == 0 || sum_cards(c3,sum) == 0)
					sum = 0;
				else{
					//check if there's any aces
					if(!(sum_cards(c1, sum) == 1 || sum_cards(c1, sum) == 11))
						sum = sum + sum_cards(c1, sum);
					else
						a1 = c1;
					if(!(sum_cards(c2, sum) == 1 || sum_cards(c2, sum) == 11))
						sum = sum + sum_cards(c2, sum);
					else
						a2 = c2;
					if(!(sum_cards(c3, sum) == 1 || sum_cards(c3, sum) == 11))
						sum = sum + sum_cards(c3, sum);
					else
						a3 = c3;
					//use which aces are better for the player
					if(a1 != '\0')
						sum = sum + sum_cards(a1,sum);
					if(a2 != '\0')
						sum = sum + sum_cards(a2,sum);
					if(a3 != '\0')
						sum = sum + sum_cards(a3,sum);
				}
			}
			else if(cards == 4){
				//get cards
				scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);
				//go to the next line, skips scanning the extra characters, discard them
				while(getchar()!='\n');
				printf("Faces of cards entered = %c %c %c %c\n", c1, c2, c3, c4);
				//check to see if there's any invalid card
				if(sum_cards(c1, sum) == 0 || sum_cards(c2,sum) == 0 || sum_cards(c3,sum) == 0 || sum_cards(c4,sum) == 0)
					sum = 0;
				else{
					//check if there's any aces
					if(!(sum_cards(c1, sum) == 1 || sum_cards(c1, sum) == 11))
						sum = sum + sum_cards(c1, sum);
					else
						a1 = c1;
					if(!(sum_cards(c2, sum) == 1 || sum_cards(c2, sum) == 11))
						sum = sum + sum_cards(c2, sum);
					else
						a2 = c2;
					if(!(sum_cards(c3, sum) == 1 || sum_cards(c3, sum) == 11))
						sum = sum + sum_cards(c3, sum);
					else
						a3 = c3;
					if(!(sum_cards(c4, sum) == 1 || sum_cards(c4, sum) == 11))
						sum = sum + sum_cards(c4, sum);
					else
						a4 = c4;
					//use which aces are better for the player
					if(a1 != '\0')
						sum = sum + sum_cards(a1,sum);
					if(a2 != '\0')
						sum = sum + sum_cards(a2,sum);
					if(a3 != '\0')
						sum = sum + sum_cards(a3,sum);
					if(a4 != '\0')
						sum = sum + sum_cards(a4,sum);
				}
			}
			else if(cards == 5){
				//get cards
				scanf(" %c %c %c %c %c", &c1, &c2, &c3, &c4, &c5);
				//go to the next line, skips scanning the extra characters, discard them
				while(getchar()!='\n');	
			 	printf("Faces of cards entered = %c %c %c %c %c\n", c1, c2, c3, c4, c5);
				//check to see if there's any invalid card
				if(sum_cards(c1, sum) == 0 || sum_cards(c2,sum) == 0 || sum_cards(c3,sum) == 0 || sum_cards(c4,sum) == 0 || sum_cards(c5,sum) == 0)
					sum = 0;
				else{
					//check to see if all 5 cards are the same
					if(sum_cards(c1, sum) == sum_cards(c2,sum) && sum_cards(c3,sum) == sum_cards(c4,sum) && sum_cards(c5,sum) == sum_cards(c1,sum) && sum_cards(c1, sum) == sum_cards(c3,sum) ){
						sum = 0;
						printf("It is not possible to have five cards all having the same value\n");
					}else{
						//check if there's any aces
						if(!(sum_cards(c1, sum) == 1 || sum_cards(c1, sum) == 11))
							sum = sum + sum_cards(c1, sum);
						else 
							a1 = c1;
						if(!(sum_cards(c2, sum) == 1 || sum_cards(c2, sum) == 11))
							sum = sum + sum_cards(c2, sum);
						else
							a2 = c2;
						if(!(sum_cards(c3, sum) == 1 || sum_cards(c3, sum) == 11))
							sum = sum + sum_cards(c3, sum);
						else
							a3 = c3;
						if(!(sum_cards(c4, sum) == 1 || sum_cards(c4, sum) == 11))
							sum = sum + sum_cards(c4, sum);
						else
							a4 = c4;
						if(!(sum_cards(c5, sum) == 1 || sum_cards(c5, sum) == 11))
							sum = sum + sum_cards(c5, sum);
						else
							a5 = c5;
						//use which aces are better for the player
						if(a1 != '\0')
							sum = sum + sum_cards(a1,sum);
						if(a2 != '\0')
							sum = sum + sum_cards(a2,sum);
						if(a3 != '\0')
							sum = sum + sum_cards(a3,sum);
						if(a4 != '\0')
							sum = sum + sum_cards(a4,sum);
						if(a5 != '\0')
							sum = sum + sum_cards(a5,sum);
					}
				}
			}
			//respond if all the cards were valid
			if(sum > 0){		
				//give the total value of the hand
				printf("The value of your hand = %d ", sum);
				if(sum > 21)
					printf("-->Busted\n");
				else if(sum == 21)
					printf("-->Blackjack\n");
				printf(" \n");
				//ask player if want to try again
				printf("Type Y or y to try again: ");
				scanf(" %c", &ans);
				if(ans == 'Y' || ans == 'y'){
					printf("You typed: %c\n", ans);
					continue;
				}else{
					printf("You typed: %c\n", ans);
					game = 0;
				}		
			}else{
				printf("At least one of the faces of cards is an invalid input\n");
				printf("\n");
				//ask player if want to try again
				printf("Type Y or y to try again: ");
				scanf(" %c", &ans);
				if(ans == 'Y' || ans == 'y'){
					printf("You typed: %c\n", ans);
					continue;
				}else{
					printf("You typed: %c\n", ans);
					game = 0;
				}		
			}
		}else{
			printf("Invalid input\n");
			printf("\n");
			//go to the next line, skips scanning the extra characters, discard them
			while(getchar()!='\n');
			//ask player if want to try again
			printf("Type Y or y to try again: ");
			scanf(" %c", &ans);
			if(ans == 'Y' || ans == 'y'){
				printf("You typed: %c\n", ans);
				continue;
			}else{
				printf("You typed: %c\n", ans);
				game = 0;	
			}	
		}
			
	}

	return 0;	
}

//get the value of each card
int sum_cards(char face, int sum){
	int card;
	//ascii representation - face is between 2 and 9
	if(face > 49 && face < 58){
		card = face - '0';
	}
	else if(face == 't' || face == 'j' || face == 'q' || face == 'k' || face == 'T' || face == 'J' || face == 'Q' || face == 'K'){
		card = 10;
	}
	else if(face == 'a' || face == 'A'){	
		//decides which ace to use		
		if(sum + 11 > 21)
			card = 1;				
		else
			card = 11;
	}else{
		return 0;
	}	
	return card;
}
