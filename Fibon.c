//Alina Thai
#include<stdio.h>
#include<math.h>
float get_Median(int count, FILE *file);
int main(int arg_count, char **arg_pointer){
	FILE *Fibon;
	int n, i, count;
	unsigned long long num1 = 0, num2 = 1, sum;
	float median;
	//step 1
	//check the arguments
	if(arg_count != 2){
		if (arg_count > 2)
			printf("Too many arguments\n");
		else if (arg_count < 2)
			printf("Not enough arguments\n");
	}
	else{
		arg_pointer++;
		//convert a string of digits to an int value
		n = atoi(*arg_pointer);
		//returns 0 if not a number
		if(n <= 2)		
			printf("N is illegal\n");
		else{

			printf("You entered argument: %d\n", n);
			Fibon = fopen("Fibonacci", "w");
			if(Fibon == NULL){
				printf("Open Fibonacci failed\n");
				return -1;	
			}
			//create the Fibonacci sequence and keep the count of the numbers 
			printf("\nFile Fibonacci content:\n");	
			printf("%llu\t ", num2);
			fprintf(Fibon, "%llu\t ", num2);
			count = 1;
			for(i = 0; i < n - 1 ; i++){
				if(count % 4 == 0){
					fprintf(Fibon,"\n");
					printf("\n");
				}
				sum = num1 + num2;
				num1 = num2;
				num2 = sum;	

				if((unsigned)sum < (unsigned)num1){
					printf("\nUnsigned Overflow\n");
					break;
				}	
						
				fprintf(Fibon, "%llu\t ", num2);
				printf("%llu\t ", num2);
				count ++;			
			}
			fprintf(stdout, "\nTotal: %d numbers in Fibonacci\n\n", count);
			fclose(Fibon);

			//step 2
			//find out the median of numbers
			Fibon = fopen("Fibonacci","r");
			median = get_Median(count, Fibon);
			fprintf(stdout, "The Fibonacci median: %.2f\n", median);
			fprintf(stdout, "\n");
			fclose(Fibon);

			//step 3
			FILE *feven; 
			FILE *fodd; 
			int count_odd = 0, count_even = 0;
			float median_odd, median_even;
			unsigned long long c;
			//separate odd and even numbers in different files
			Fibon = fopen("Fibonacci", "r");
			feven = fopen("Fibonacci.even", "w");	
			fodd = fopen("Fibonacci.odd", "w");
			if(feven == NULL){
				printf("Open Fibonacci.even failed\n");
				return -1;	
			}	
			if(fodd == NULL){
				printf("Open Fibonacci.odd failed\n");
				return -1;	
			}
			//also write 4 numbers per row

			while(fscanf(Fibon," %llu", &c) > 0){
				//printf("dumb\n");
				if(c % 2 == 0){
					fprintf(feven, "%llu\t ", c);
					count_even++;
					if(count_even % 4 == 0)
						fprintf(feven, "\n");
				}else{	
					fprintf(fodd, "%llu\t ", c);
					count_odd++;
					if(count_odd % 4 == 0)
						fprintf(fodd, "\n");
				}
			}
			//print how many numbers are in each file
			fprintf(stdout,"Total: %d numbers in Fibonacci.even\n", count_even);
			fprintf(stdout,"Total: %d numbers in Fibonacci.odd\n", count_odd);
			fclose(feven);
			fclose(fodd);
			fclose(Fibon);

			//get the medians for odd and even
			feven = fopen("Fibonacci.even", "r");	
			fodd = fopen("Fibonacci.odd", "r");
			median_even = get_Median(count_even, feven);
			fprintf(stdout, "Fibonacci.even median: %.2f\n", median_even);
			median_odd = get_Median(count_odd, fodd);
			fprintf(stdout, "Fibonacci.odd median: %.2f\n", median_odd);
			fprintf(stdout, "\n");
			fclose(feven);
			fclose(fodd);

			//step 4
			//append even at the end of odd
			int new_count = 0;
			FILE *fodd_new;
			feven = fopen("Fibonacci.even", "r");
			fodd = fopen("Fibonacci.odd", "r");
			fodd_new = fopen("Fibonacci.copy", "w");
			if(fodd_new == NULL){
				printf("Open new Fibonacci.copy failed\n");
				return -1;	
			}
			//copy numbers into a new file without \n
			while(fscanf(fodd,"%llu", &c) > 0){
				fprintf(fodd_new, "%llu\t ",c);
			}
			fclose(fodd);
			fclose(fodd_new);
			
			//delete the content of odd
			fodd = fopen("Fibonacci.odd", "w");
			fclose(fodd);

			//add all the numbers to odd
			fodd = fopen("Fibonacci.odd", "a");
			fodd_new = fopen("Fibonacci.copy", "r");
			while(fscanf(fodd_new,"%llu", &c) > 0){
				fprintf(fodd, "%llu\t",c);
			}
			while(fscanf(feven,"%llu", &c) > 0){
				fprintf(fodd, "%llu\t",c);
			}
			fclose(fodd_new);
			fclose(fodd);
			fclose(feven);
			
			//get the new count
			fodd = fopen("Fibonacci.odd", "r");
			while(fscanf(fodd,"%llu", &c) > 0){
				new_count++;
			}
			printf("\nTotal count in Fibonacci.odd is now: %d\n", new_count);
			fclose(fodd);

			//separate per row
			new_count = 0;
			fodd = fopen("Fibonacci.odd", "r+");
			while(fscanf(fodd,"%llu", &c) > 0){
				new_count++;
				printf("%llu\t", c);
				if(new_count % 6 == 0)
					fprintf(fodd,"\n");
				else if (new_count % 5 == 0)
					printf("\n");
			}		
			fclose(fodd);
			printf("\n");		
		}
	}
	return 0;
}

float get_Median(int count, FILE *file){
	float median;
	int c, j = 0;
	int half = count / 2 - 1;
	if(count % 2 == 1){	
		//get the middle element
		while(fscanf(file,"%d", &c) > 0){
			if(j == half){
				median = c;
				break;
			}
		j++;
		}
	}else{
		//get the average of the middle elements
		double mid1, mid2;
		while(fscanf(file,"%d", &c) > 0){

			if(j == half)
				mid1 = c;
			if(j == (half + 1)){
				mid2 = c;
				break;
			}
		j++;
		}
		median = (mid1 + mid2)/ 2;
	}
	return median;
}
