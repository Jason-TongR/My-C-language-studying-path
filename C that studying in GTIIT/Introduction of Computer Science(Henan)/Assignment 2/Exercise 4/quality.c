#include <stdio.h>
int main(){
    int n;
    int uppercase=0,lowercase=0,digit=0,symbol=0;
    int total=0; //total number of passwords
    int very_strong,strong,weak,very_weak;
    while((n=getchar()) != EOF){
         int E_uppercase=0,E_lowercase=0,E_digit=0,E_symbol=0;
         while(n!='\n' && n !=EOF ){
              if(n>='A' && n<='Z'){
                uppercase++;
                E_uppercase=1;
}             else if(n>='a' && n<='z'){
                lowercase++;
                E_lowercase=1;
}             else if(n>='0' && n<='9'){
                digit++;
                E_digit=1;
}             else{
                symbol++;
                E_symbol=1;
}             n=getchar();
}        if(n=='\n' || n==EOF){
            total++;
            if(E_uppercase && E_lowercase && E_digit && E_symbol){
              int max=uppercase,min=uppercase;
              if (lowercase>max) max=lowercase;
              if (digit>max) max=digit;
              if (symbol>max) max=symbol;
              if (lowercase<min) min=lowercase;
              if (digit<min) min=digit;
              if (symbol<min) min=symbol;
              if (max-min<=1){
                 very_strong++;
}             else{
                 strong++;
}
}             else if(E_uppercase && E_lowercase && E_digit && E_symbol==0){
                 weak++;
}             else{
                 very_weak++;
}
}
}   if(total>0){
       printf("Very Strong: %d%%",(very_strong*100)/total);
       printf("Strong: %d%%",(strong*100)/total);
       printf("Weak: %d%%",(weak*100)/total);
       printf("Very Weak: %d%%",(very_weak*100)/total);
}   else{
       printf("No passwords exist");
}   return 0;
}
