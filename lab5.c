#include<stdio.h>
long add(long, long*, long, long*);
long x=100, y=200, sum;
long main(){
	long z,w;
	z=-30;
	w=50;
	sum = add(x,&y,z,&w);
	return w;
}
long add(long a, long *b, long c, long*d){
	int t = a + *b - c - *d;
	return t;
}
