#include <stdio.h>
#include <stdlib.h>

#define MUX(a,b) (a)*(b)

int fun(int x)
{
   int count = 0 ;

   while(x){
      count++ ;
      //printf("%d\n",count);
      x = x & (x-1) ;
   }
   return count ;
}    

 
int main(void)
{
	
	printf("%d\n", fun(456)); // (456) -> (0001 1100 1000) 4­Ó1 
	printf("%d\n", fun(123)); // (123) -> (0111 1011)      6­Ó1 
	printf("%d\n", fun(789)); // (789) -> (0011 0001 0101) 5­Ó1 

	printf("%d\n",MUX(10+5,10-5));

	return 0;
} 
 

/* 
int c;

int fib(int n)

{

    c++;

    if ((n==1)|| (n==2))

      return 1;

   

    return (fib(n-1)+fib(n-2)); 

}

int main()

{

    c=0;

    fib(5);

    printf("%d", c);

    return 0;

}
*/ 
