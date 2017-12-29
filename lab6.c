#include<stdio.h>
void bubble(int*, int);
int a[] = {0x23,0x21,0x010,0x3321,0x1123,0x121,0x23,0x221,0x423,0x1121,0x223,0x81};
int main(){
	int i =0xc;
	bubble(a,i);
}
void bubble(int *data, int count){
	int i, last;
	for(last = count -1; last> 0; last--){
		for(i = 0; i<last;i++)
		if(data[i+1]<data[i]){
			int t = data[i+1];
			data[i+1] = data[i];
			data[i] = t;
		}	
	}
}
