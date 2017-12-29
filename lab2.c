//Alina Thai
#include<stdio.h>
#include<math.h>
int BinaryAdd(int in1, int in2);
int main(){
	int a1, a2, bin, sum;
	//the maximum value for an unsigned int
	int UINT_MAX = 4294967295;
	int last1, last2, carry = 0;
	//get the inputs
	printf("Give 2 integers in hex to add: ");
	scanf(" %x %x", &a1, &a2);
	//prints as signed, unsigned and hex
	printf("First = 0x%.8x As unsigned = %u As signed = %d \n", a1, a1, a1);
	printf("Second = 0x%.8x As unsigned = %u As signed = %d \n", a2, a2, a2);
	//call the BinaryAdd function
	sum = BinaryAdd(a1, a2);
	printf("Sum = 0x%.8x As unsigned = %u As signed = %d \n", sum, sum, sum);	
	//indicates if there is signed or/and unsigned overflow
	if((a1 > 0 && a2 > 0 && 0 > sum) || (0 > a1 && 0 > a2 && sum > 0))
		printf("Signed Overflow\n");
	if(a2 > UINT_MAX - a1)
		printf("Unsigned Overflow\n");
	return 0;
}

int BinaryAdd(int in1, int in2){
	int sum = 0, number = 0, i, ai = 0, bi = 0, carry = 0;
	//32 iterations of loop
	for(i = 0; i < 32; i++){
		if(in1 &(1 << i))
			ai = 1;
		else
			ai = 0;
		if(in2 &(1 << i))
			bi = 1;
		else 
			bi = 0;
		sum = 0;
		// 1-bit adder truth table
		if(!carry){
			if(ai + bi == 0){
				carry = 0;
				sum = 0;
			}else if(ai + bi == 1){
				carry = 0;	
				sum = 1;
			}else if(ai + bi == 2){
				carry = 1;	
				sum = 0;
			}
		}else{
			if(ai + bi == 0){
				carry = 0;
				sum = 1;
			}else if(ai + bi == 1){
				carry = 1;	
				sum = 0;
			}else if(ai + bi == 2){
				carry = 1;	
				sum = 1;
			}
		} 
		if(sum == 1)
			number = number | (1 << i);
	}

	return number;
}	



