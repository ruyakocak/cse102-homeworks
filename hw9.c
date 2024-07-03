#include <stdio.h>

typedef struct{
    int board[100][100];
    int weidth;
    int height;
    int flower_x[100];
    int flower_y[100];

}Forest;

typedef struct{
    int cord_x;
    int cord_y;
    int number_of_bottle;
}Botanist;

void displayforest(Forest forest,Botanist botanist,int collected){
    int i,j;
    for(i=0;i<forest.height;i++){
        for(j=0;j<forest.weidth;j++){
             printf(" %c ",forest.board[i][j]); /*genişlik ve boyuta göre tüm ormanı bastır*/
        }
    printf("\n");
    }
    printf("Collected flower: %d\n", collected);
    printf("Not used bottle number: %d\n",botanist.number_of_bottle-collected); /*toplam şişeden kullanılanı çıkar*/
}

void search(Botanist *botanist, Forest forest, int flowernumber, int collected, int totalflower){
    FILE *file;
    char move;
    int tempx=botanist->cord_x,i,j,k;
    int tempy=botanist->cord_y;
    printf("Enter next move (Press e for exit): ");
    scanf(" %c",&move);
    printf("\n");
    switch(move){
        case 'w': tempx=(botanist->cord_x)-1; break;
        case 'a': tempy=(botanist->cord_y)-1; break;
        case 's': tempx=(botanist->cord_x)+1; break;
        case 'd': tempy=(botanist->cord_y)+1; break;
        case 'e': file=fopen("last.txt","w+"); /*e seçilirse last.txt dosyasını oluştur ve son konumu kaydet*/
                fprintf(file,"%d,%d\n",forest.height,forest.weidth);
                fprintf(file,"%d,%d,%d\n",botanist->cord_x,botanist->cord_y,botanist->number_of_bottle-collected);
                for(j=0;j<forest.weidth;j++){
                    for(k=0;k<forest.height;k++){
                        fprintf(file,"%c ",forest.board[j][k]);
                    }
                    fprintf(file,"\n");
                }
                fprintf(file,"Collected flower: %d\n",collected);
                fprintf(file,"Not used bottle number: %d\n",botanist->number_of_bottle-collected);
                fclose(file);
                return ;
        default: printf("Invalid move!\n"); /*yanlış yön girilirse uyarı ver ve tekrar hareket istemesi için search fonksiyonunu çağır*/
    }
    if(forest.board[tempx][tempy]=='T') { /*ağaçların üzerine hareket edilemez*/
        printf("Invalid move!\n");
    }
    
    else{
        forest.board[botanist->cord_x][botanist->cord_y]=' '; /*önceki konumlar boşluğa çevrilir*/
        forest.board[tempx][tempy]='B'; /*koordinat güncelleme*/
        botanist->cord_x=tempx;
        botanist->cord_y=tempy;
    }
    
    for(i=0;i<totalflower;i++){ /*gelinen konum herhangi bir çiçeğin konumu mu kontrol edilir*/
            if((botanist->cord_x)==forest.flower_x[i] && (botanist->cord_y)==forest.flower_y[i]) {
                forest.flower_x[i]=-1; /*aynı konumdaki çiçeğe tekrar gelindiğinde çiçek sayısı arttırılmasın diye koordinatları -1le değiştir*/
                forest.flower_y[i]=-1;
                collected++; /*her çicek bulunduğunda toplanan çiçek sayısını arttır*/
                flowernumber--; /*bulunması gereken çiçek sayısını azalt*/
                printf("I've found it\n");
            }
    }
    if(flowernumber==0) { /*tüm çiçekler toplandığında son konumları kaydet ve sonlandır*/
        file=fopen("last.txt","w+"); /*last dosyasına son görüntüyü kaydet*/
        fprintf(file,"%d,%d\n",forest.height,forest.weidth);
        fprintf(file,"%d,%d,%d\n",botanist->cord_x,botanist->cord_y,botanist->number_of_bottle-collected);
        for(j=0;j<forest.weidth;j++){
            for(k=0;k<forest.height;k++){
                fprintf(file,"%c ",forest.board[j][k]);
            }
            fprintf(file,"\n");
        }
        fprintf(file,"Collected flower: %d\n",collected);
        fprintf(file,"Not used bottle number: %d\n",(botanist->number_of_bottle)-collected);
        fclose(file);
        displayforest(forest,*botanist,collected);
        return ; /*tüm çiçekler toplandıysa sonlandır*/
    }
    else{
    displayforest(forest,*botanist,collected);
    search(botanist,forest,flowernumber,collected,totalflower);
    }

}

void init_game(Forest *forest, Botanist *botanist){
    FILE *file= fopen("init.txt","r");
    char temp;
    int commacounter=0;
    int tempx=0,tempy=0,i=0;
    fscanf(file,"%d,%d ",&forest->height,&forest->weidth);
    fscanf(file,"%d,%d,%d ",&botanist->cord_x,&botanist->cord_y,&botanist->number_of_bottle);
    while(fscanf(file,"%c",&temp)!=EOF){
        if(temp=='X'){ /*her X okunduğunda flower arrayine kaydet*/
            forest->board[tempx][tempy]=temp;
            forest->flower_x[i]=tempx;
            forest->flower_y[i]=tempy;
            i++;
        }
        if(temp==',') { /*her virgül geldiğinde koordinatı bir sağa kaydır*/
            tempy++;
            commacounter++;
        }
        
        if(commacounter==forest->weidth-1){ /*son virgüle ulaşılmış ise*/
            fscanf(file,"%c ",&temp);/*satır sonu karakter için kontrol*/
                if(temp=='X'){
                    forest->flower_x[i]=tempy;
                    forest->flower_y[i]=tempx;
                    i++;
                }
                forest->board[tempx][tempy]=temp;
                commacounter=0;
                tempx++;
                tempy=0; /*okuma yaparken aşağı inilince koordinatı sıfırla*/
                
        }
        else{
                forest->board[tempx][tempy]=temp;

        }

    }
    displayforest(*forest,*botanist,0);
    search(botanist,*forest,i,0,i);
}

int main(){
    Forest forest;
    Botanist botanist;
    init_game(&forest,&botanist);    
}
