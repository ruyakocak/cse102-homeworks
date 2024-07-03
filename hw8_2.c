#include <stdio.h>
#include <string.h>
#define MAX_COL_COUNT 34 


void search_p1(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int *num_matches) {
    char shape[] = "***++++***++++***";
    int i, j,flag=0;
    int final[2];
    int n=strlen(shape);
    *num_matches = 0; /*Matches arrayindeki eşleşme sayısını sıfırla*/
    for (num_rows = 0; num_rows < 5; num_rows++) {
        for (i = 0; i < MAX_COL_COUNT - n; i++) {
            /*Her satırın her karakterinden başlayarak pattern kontrolü yap*/
            if (strncmp(shape, strs[num_rows] + i, n) == 0) {
                flag=1;
                final[0]=num_rows;
                final[1]=i;
                printf("P1 @ (%d,%d)\n",final[0]+1,final[1]+1);
                for(j=0;j<n;j++){
                matches[*num_matches][0] = num_rows;
                matches[*num_matches][1] = i;
                i++;
                (*num_matches)++; /*Eşleşme sayısını arttır*/
                }
            }
        }
    }
        if(flag==0) printf("No matching\n");

}

void search_p2(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int * num_matches){
    char shape2[]="+*+*+";
    int i,j,b,k=0,flag=0;
    int final[2];
    int n=strlen(shape2);
    for(j=0;j<MAX_COL_COUNT;j++){
        k=0;
            for(i=0;i<5;i++){

                if(strs[i][j]==shape2[k]){
                    k++;
                }
                if(k==n-1){
                    flag=1;
                    final[0]=i-n+2;
                    final[1] = j;
                    printf("P2 @ (%d,%d)\n",final[0]+1,final[1]+1);
                    for(b=0; b<5;b++){
                    matches[*num_matches][0]=i-n+2;
                    matches[*num_matches][1] = j;
                    (*num_matches)++;
                    i++; 
                    }
                }



            }

        }
        if(flag==0) printf("No matching\n");
    }
    

void search_p3(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int * num_matches){
    char shape3[]="+**+++****+++**+";
    int n=strlen(shape3);
    int k,a,b,i,j,s,counter,flag=0;
            for(j=0;j<MAX_COL_COUNT-n;j++){ 
                i=0;
                a=0;
                k=j;
                counter=0;
                for(s=0;s<n;s++){
                    if(strs[i][k]==shape3[a]){
                        a++;
                        counter++;
                        i++;
                        k++;

                    }
                    if(counter==n){

                        printf("P3 @ (%d,%d)\n",1,k-n+1);

                        for(b=0;b<n;b++){
                        flag=1;
                        matches[*num_matches][0]= 1;
                        matches[*num_matches][1]= k-n+1 ;
                        k++;
                        (*num_matches)++;
                        }

                    }
                }
            }

    
    if(flag==0) printf("For P3 no matching!\n");

    
}


int main() {
    int i=0;
    FILE *file=fopen("input2.txt","r");
    char strs[5][MAX_COL_COUNT],temp[5];
    while(feof(file)!=1){
        fgets(strs[i],MAX_COL_COUNT,file);
        fgets(temp,5,file); /*null değer için*/
        i++;

    }
    fclose(file);
    int num_rows,matches[100][2],num_matches=0;
    search_p1(strs,num_rows,matches, &num_matches);
    search_p2(strs,num_rows,matches, &num_matches);
    search_p3(strs,num_rows,matches, &num_matches);
}
