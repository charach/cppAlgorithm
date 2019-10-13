#include <stdio.h>
#include <string.h>
using namespace std;

int main(void)
{
    char str[100];
    scanf("%s",str);
    char b[10] = "CAMBRIDGE";

    for(int i = 0 ; i< 9; i++)
    {
        for(int j = 0; j< strlen(str); j++){
            if(str[j] == b[i])
            {
                str[j] = ' ';
            }
        }
    }

    for(int i = 0 ; i < strlen(str); i++)
    {
        if(str[i] != ' '){
            printf("%c",str[i]);
        }
    }
    printf("\n");
}