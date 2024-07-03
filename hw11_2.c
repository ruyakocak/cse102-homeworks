#include <stdio.h>

typedef struct {
    char *name;
    char citiesServed[4]; 
} Hospital;

void combination(int numbers[], int size, int numhospital, int selection[][numhospital], int *count, int temp[], int start, int index) {
    int i,j;
    if (index == numhospital) {
        for (j = 0; j < numhospital; j++) {
            selection[*count][j] = temp[j];
        }
        (*count)++;
        return;
    }

    for (i = start; i < size && size - i >= numhospital - index; i++) {
        temp[index] = numbers[i];
        combination(numbers, size, numhospital, selection, count, temp, i + 1, index + 1);
    }
}

void Ispossible(char* cities, int numhospital, int count, int m, Hospital hospitals[count][4], int selection[][numhospital],char covered[15]){
    
    if(m==count){ 
        printf("No,some cities are not covered.\n");
        return;
    }
    int counter=0;
    int flag,i,j,k,a=0;
   
        for(i=0;i<numhospital;i++){                

                    for(j=0;j<3;j++){
                        if(hospitals[selection[m][i]-1]->citiesServed[0]!='\0'){
                            covered[a]=hospitals[selection[m][i]-1]->citiesServed[j];
                            a++;
                        }
                    }
            
        }

        for(i=0;i<6;i++){
            for(j=0;j<15;j++){
                if(covered[j]=='Z') break;
                int flag2=0;
                if(cities[i]==covered[j]){
                    for(k=0;k<j;k++){
                        if(covered[j]==covered[k]) flag2=1; /*aynı şehirleri tekrar sayma*/
                    }
                    if(flag2!=1) counter++;
                }
            }
        }
        if(counter==6) {
            printf("Yes, can offer health care to all!\n");
            for(i=0;i<numhospital;i++){
                printf("Hospital-%d\n",selection[m][i]);
                printf("Hospital location: %s\n",hospitals[selection[m][i]-1]->citiesServed);
            }
            return;
        }
        else{
            char z='Z';
             for(j=0;j<6;j++){
                covered[j]=z;
            }
            m++;
            Ispossible(cities,numhospital,count,m,hospitals,selection,covered);
        }
    }
    


int main() {
    char cities[] = "ABCDEF";
    Hospital hospitals[4][4] = {{"Hospital1", "ABC"}, {"Hospital2", "ACD"}, {"Hospital3", "BF"}, {"Hospital4", "CEF"}};
    int numhospital,i,j;
    do{
    printf("Enter the maximum number of hospitals that can be constructed: ");
    scanf("%d", &numhospital);

    if (numhospital < 1 || numhospital > 4) {
        printf("Invalid number of hospitals. Must be between 1 and 4.\n");
    }
    }while((numhospital < 1 || numhospital > 4));

    int numbers[] = {1, 2, 3, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int selection[10][numhospital]; 
    int count = 0;
    int temp[numhospital];
    char covered[15]="ZZZZZZZZZZZZZZZ";
    combination(numbers, size, numhospital, selection, &count, temp, 0, 0);
    Ispossible(cities,numhospital,count,0,hospitals,selection,covered);



    return 0;
}
