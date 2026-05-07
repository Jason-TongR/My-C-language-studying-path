#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define simulations 100000
int main(){
    srand(time(NULL));
    int n=0; //times not starting with a letter
    for(int i=0;i<simulations;i++){
       int a=rand()%10; //random number from 0 to 9
       char first;
       if(a<4){
         first='a'+rand()%26;
}      else if(a<7){
         first='A'+rand()%26;
}      else if(a<9){
         first='0'+rand()%10;
}      else{
         first=35+rand()%13;
}
    if(!((first>='a' && first<='z') || (first>='A' && first<='Z'))){
         n++;
}
}
    printf("Percentage of passwords not starting with a letter: %d%%\n",(n*100)/simulations);
    return 0;
}
