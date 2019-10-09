#include <stdio.h>

int ary[500001];
int main(void)
{
    int num;
    scanf("%d",&num);
       
    int index = 0;
    int numBuf = 1;
    while(numBuf < 500000){
        ary[index] = numBuf;
        numBuf *=2;
        index++;   
    }
    ary[index++] = numBuf;

    int i = 0;
    while(num > ary[i]){
        i++;
    }
    printf("%d\n",2 * num - ary[i]);

}
