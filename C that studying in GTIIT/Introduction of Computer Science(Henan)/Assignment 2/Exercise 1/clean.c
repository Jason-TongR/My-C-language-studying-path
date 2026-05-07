#include <stdio.h>
int main(){
    int c;
    int last_c='\n';
    printf("Input: ");
    while((c=getchar())!= EOF){
         if (c==' '){
            if (last_c!=' ' && last_c!='\n'){
               putchar(c);
            }
         } else{
               putchar(c);
         }
         last_c=c;
       }
    return 0;
}
