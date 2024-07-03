#include <stdio.h>
#include <string.h>


void age(int ages[]){
    FILE *file= fopen("input1.txt","r");
    int counter=0,tempint=0,i=0,j=0,a;
    char temp[60];
    while(feof(file)!=1){
            fgets(temp,60,file);
            a=0;
            while(i<50){
                if(temp[i]>='0' && temp[i]<='9') {/*okunan karakterin sayı olup olmadığı kontrol edilir*/
                tempint= tempint*10 + (temp[i]-'0');
                a++;
                if(a==2) break;
                }
                i++;
            }
            ages[j]=tempint;
            tempint=0;
            i=0;
            j++;

    }
     
    fclose(file);
}

void read(char people[][5][25],int ages[]){
    FILE *file= fopen("input1.txt","r");
    int i=0, j=0;
    char tempsatir[60];
    char *token;
   
    while(fgets(tempsatir,60,file)!=NULL){

        token=strtok(tempsatir, ",");
        while(token!=NULL){
            if(j==2){ /*sayı gelirse atla*/
                strcpy(people[i][j]," ");
            }
            else{
                strcpy(people[i][j],token);
            }
            j++;
            token=strtok(NULL,",");
        }
        while(j<5){ /*eksik eleman varsa yerlerini boşlukla doldur*/
            strcpy(people[i][j],"  ");
            j++;
        }
        i+=1;
        j=0;

    }
    fclose(file);
}

void sort_people_by_age(char people[][5][25], int ages[]){
    int i,j,temp,temp2;
    int frequency[25],ages2[25];
    for(i=0;i<24;i++){
        frequency[i]=i;
    }
       for(i=0;i<23;i++){
        ages2[i]=ages[i];
    }
    for(i=0;i<24;i++){
        for(j=0;j<23;j++){
            if(ages2[i]<ages2[j]){
                temp2=ages2[i];
                ages2[i]=ages2[j];
                ages2[j]=temp2;
                temp=frequency[i];
                frequency[i]=frequency[j];
                frequency[j]=temp;
            }
        }
    }

    printf("NAME                SURNAME             AGE                   BRANCH1             BRANCH2\n\n");

    int a=0,b=0,counter=0,z,k;
        for(i=0;i<=23;i++){
            k=0;
            for(b=0;b<23;b++){
                if(b==frequency[i]){
                for(j=0;j<5;j++){
                    printf("%s",people[b][j]);
                    k=strlen(people[b][j]);
                    if(j!=2){
                        for(z=0;z<20-k;z++){
                        printf(" ");
                    }
                    }
                    if(j==2) {
                        printf("%d",ages[b]);
                        for(z=0;z<18;z++){
                        printf(" ");
                    }
                    }

                }
               

                if(b==22) printf("\n");

                printf("\n");
                a++;
                break; /*for döngüsü istenen kişi yazdırıldıkatan sonra boşuna çalışmasın*/
               
            }
            }
        }
}

void sort_people_by_branch(char people[][5][25],int ages[]){
    int frequency[25],temp,j,i,b;
    char people2[25][5][25];
    for(i=0;i<23;i++){
        for(j=0;j<5;j++){
            strcpy(people2[i][j],people[i][j]);
        }
    }
    char tempchar[25];
    for(i=0;i<23;i++){
        frequency[i]=i;
    }
    for(i=0;i<23;i++){
        for(j=0;j<23;j++){

            if(strcmp(people2[i][3], people2[j][3])<0){

                strcpy(tempchar,people2[i][3]);
                strcpy(people2[i][3],people2[j][3]);
                strcpy(people2[j][3],tempchar);
                temp=frequency[i];
                frequency[i]=frequency[j];
                frequency[j]=temp;
            }
            else if(strcmp(people2[i][3], people2[j][3])==0){

                  if(strcmp(people2[i][4], people2[j][4])<0){
                        strcpy(tempchar,people2[i][4]);
                        strcpy(people2[i][4],people2[j][4]);
                        strcpy(people2[j][4],tempchar);
                        temp=frequency[i];
                        frequency[i]=frequency[j];
                        frequency[j]=temp;
                  }
                  if(strcmp(people2[i][4], people2[j][4])==0){
                    if(ages[i]<ages[j]){
                        temp=frequency[i];
                        frequency[i]=frequency[j];
                        frequency[j]=temp;
                    }
                 }
            }
        }
    }
    int k,z;

        printf("NAME                SURNAME             AGE                   BRANCH1             BRANCH2\n\n");
        for(i=0;i<23;i++){
            for(b=0;b<23;b++){
                if(b==frequency[i]){ /*frequency arrayindeki ilk kişi bulundu*/
                for(j=0;j<5;j++){
                   
                    printf("%s",people[b][j]);
                    k=strlen(people[b][j]);
                    if(j!=2){

                        for(z=0;z<20-k;z++){
                        printf(" ");
                    }
                    }
                    if(j==2) {
                        printf("%d",ages[b]);
                        for(z=0;z<18;z++){
                        printf(" ");
                    }
                    }
                    if(j==4) printf("\n");

                }
                if(b==22) printf("\n");

                }
            }
        }

}

void filter_people_by_profession(char people[][5][25], int ages[]){
        char word[]=" COMPUTER";
        char word2[]=" MATHEMATICS";
        int b,j;
        printf("NAME  SURNAME             AGE              BRANCH1               BRANCH2\n\n");
        for(b=0;b<23;b++){
            if(strncmp(word,people[b][3],9)==0 && strncmp(word2,people[b][4],3)!=0){
                        for(j = 0; j < 5; j++){
                            printf("%s", people[b][j]);
                            if(j == 2 && b!=2) printf("          %d             ", ages[b]);
                            if(j == 2 && b==2) printf("              %d             ", ages[b]);
                            if(j==4) printf("\n");

                            }
                        }
                    }  
            }
       


void filter_people_by_branch(char people[][5][25],int ages[]){
        char word[]="COMPUTER";
        char word3[]=" PHYSICS";
        char copy[25];
        char *token;
        int b,j,z,k;
        printf("\nNAME                SURNAME             AGE                   BRANCH1             BRANCH2\n\n");

        for(b=0;b<23;b++){
                strcpy(copy,people[b][3]);
                token=strtok(copy," ");
                while(token!=NULL){
                    if((strcmp(token,word)==0 || strcmp(people[b][3],word3)==0) && b!=13){
                       
                    for(j=0;j<5;j++){
                   
                    printf("%s",people[b][j]);
                    k=strlen(people[b][j]);
                    if(j!=2){

                        for(z=0;z<20-k;z++){
                        printf(" ");
                    }
                    }
                    if(j==2) {
                        printf("%d",ages[b]);
                        for(z=0;z<18;z++){
                        printf(" ");
                    }
                    }
                    if(j==4) printf("\n");

                }
                if(b==22) printf("\n");

                }
                    token=strtok(NULL," ");

                    }
                }

        }





int main() {
    int choice;
    char people[25][5][25]; /*25 kişi var, her birinin max 5 özelliği var, özellik harf sayıları max 25 ayarlandı*/
    int ages[25];
    printf("\n\n**************************Menu***************************\n\n");
    printf("1.Sort and dislpay all individuals by age\n\n");
    printf("2.Sort and dislpay all individuals in the branch by age\n\n");
    printf("3.Show individuals with the branch 'SCIENCE'\n\n");
    printf("4.Show computer scientists who are not mathematicians\n\n");
    printf("5.Exit\n\n");
    age(ages);
    read(people,ages);
   do{
    printf("\nEnter your choice: ");
    scanf(" %d",&choice);
    printf("\n");
    switch(choice){
        case 1: sort_people_by_age(people,ages); break;
        case 2: sort_people_by_branch(people,ages); break;
        case 3: filter_people_by_branch(people,ages);
                break;
        case 4: filter_people_by_profession(people,ages); break;
        case 5: return 0;
        default: printf("Invalid option. Please choose between 1-5!\n");
    }
   }while(choice!=5);



}
