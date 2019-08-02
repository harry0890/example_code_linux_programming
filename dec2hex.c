#include <stdio.h>

#define size 5

static void dec2hex(int dec)
{
    unsigned char array[size] = {'\0'};
    int i = 0;
    int temp = 0;

    while(dec != 0){
	temp = dec%16;
	//array[i] = temp;
	if(temp > 10)
	    array[i] = temp + 55;
	else
	    array[i] = temp + 48;
	i++;
	dec = dec/16;
    }

    for(i=0; i<size; i++)
	printf("%c ",array[i]);
    printf("\n");
}



int main(void)
{
    int input = 2545;

    dec2hex(input);
    //printf("hex = 0x%x\n",out);

    return 0;
}
