#include "stdio.h"
#include "stdlib.h"
#include <stdio.h>


// int main(int argc, char **argv)
// {
//     int num  = 0;
//     FILE *fp1 = fopen(argv[1],"r");
//     FILE *fp2 = fopen(argv[2],"a");
//     if(fp1 == NULL&& fp2 == NULL)
//     {
//         perror("open is  erros\n");
//         exit(1);
//     }
//     while (1)
//     {
//         num = fgetc(fp1);

//         if (num == EOF )
//         {
//             printf("is out\n");
//             break;
//         }
//          fputc(num,fp2);
        
//     }
//     fclose(fp1);
//     fclose(fp2);
//     exit(0);    
// }
char buf[102];
int main(int argc ,char **argv )
{
    FILE *fp1 = fopen(argv[1],"r");
    FILE *fp2 = fopen(argv[2],"w");
    if(fp1 == NULL&& fp2 == NULL)
    {
        perror("fopen is erros");
        exit(0);
    }

        while (fgets(buf,5,fp1)!= NULL) {
                fputs(buf,fp2);
        }
    fclose(fp1);
    fclose(fp2);
    exit(0);
}