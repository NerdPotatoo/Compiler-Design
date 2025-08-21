#include<stdio.h>
int add(int a, int b, int c){
return a+b+c;
}
int subtract(int a, int b){
return a-b;
}

void main(){
int a=1, b=2, c=3;
int sum = add(a,b,c);
int sub = subtract(b,a);
printf("sum = %d sub = %d", sum, sub);
}
