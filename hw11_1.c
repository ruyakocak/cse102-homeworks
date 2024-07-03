#include <stdio.h>

int numPathsHome(int a,int street, int resultstreet, int avenue,int resultavenue, int variable){
    int b;
    if(street==1 && avenue==1 ) {
        b=variable/a;
    return b;
        
    }
    resultstreet*=street;
    resultavenue*=avenue;
    if(street>1) street--;
    else street=1;
    if(avenue>1) avenue--;
    else avenue=1;
    a=resultstreet*resultavenue;
    return numPathsHome(a,street,resultstreet,avenue,resultavenue,variable);
     
}

int main(){
    
    int street,avenue,i,result;

    printf("Enter street: ");
    scanf("%d",&street);

    printf("Enter avenue: ");
    scanf("%d",&avenue);


    int number=street+avenue-2;
    int fact=1;
    for(i=1;i<=number;i++){
        fact*=i;
    }
    if(street==1 || avenue==1) result=1;
    else result= numPathsHome(1,street-1,1,avenue-1,1,fact);
    printf("Available paths: %d",result);
    return 0;
}
