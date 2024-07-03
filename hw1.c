#include <stdio.h>


int main(){
    char new;
    int i=0;
    char a;
    char star;
    int counter=0;
    char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?', '\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while(scanf("%c",&new)!=EOF){
       if(new==' ') printf(" ");
       else if(new=='\n') printf("\n");
       else if( new=='/') {
     
      if(scanf("%c",&star)==1){
      if(star=='*'){
     
printf("@");
    do{
    scanf("%c",&a);
    if(a!='*' && a!=' ') counter++;
       
       }while(a!='/');
       
       int rcounter=counter-1;
       int temp=rcounter;
       int k,m;
       int bas=0;
       int o;
      while(temp>0){
      temp/=10;
      bas++;
      }
     
     
      for(bas; bas>0; bas--){
      o=rcounter;
      k=rcounter;
     
      m=bas;
      for(m; m>1; m--){
      k/=10;
     
      }
     
      o=k%10;
   
       if(o<3) printf("%d",o+7);
       else {
       if(o==3) printf("a");
       if(o==4) printf("b");
       if(o==5) printf("c");
       if(o==6) printf("d");
       if(o==7) printf("e");
       if(o==8) printf("f");
       if(o==9) printf("g");
       
       }
       
     
       }
       }
}
printf(" ");
    }
   
   
       
       else {
       while(1) {
     
if(alphabet[i]==new) break;
else i++;
     
       }
 
     
       
       if(i<=53) printf("%c",alphabet[i+7]);
       else printf("%c",alphabet[i-54]);
       i=0;
     
       
       }
   
}
}
