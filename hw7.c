#include <stdio.h>

void printboard(int player, int computer, int board[2][6]) {
    int i, satir = 1;
    printf("-----");
    for (i = 1; i <= 6; i++) {
        printf("  %d ", i);
    }
    printf("-----\n");
    printf("+-");
    for (i = 0; i < 7; i++) {
        printf("---+");
    }
    printf("----+\n");
    satir++;
    if (satir == 2) {
        printf("|");
        for (i = 0; i < 4; i++) {
            printf(" ");
        }
        for (i = 0; i < 6; i++) {
            if (board[1][i] >= 10) printf("|%d ", board[1][i]); /*2 basamaklı sayı gelirse bir boşlukla sayıyı yaz*/
            else printf("| %d ", board[1][i]);
        }
        printf("|    |\n");
        satir++;
    }
    if (satir == 3) {
        if (computer >= 10) {
            printf("| %d |", computer);
        } else {
            printf("| %d  |", computer); /*Soldaki kese ve üst board bilgisayar*/
        }
        for (i = 0; i < 5; i++) {
            printf("---+");
        }
        if (player >= 10) {
            printf("---| %d |", player);
        } else {
            printf("---| %d  |", player); /*Sağdaki kese ve alt board oyuncu*/
        }
        printf("\n");
        satir++;
    }
    if (satir == 4) {
        printf("|");
        for (i = 0; i < 4; i++) {
            printf(" ");
        }
        for (i = 0; i < 6; i++) {
            if (board[0][i] >= 10) printf("|%d ", board[0][i]);
            else printf("| %d ", board[0][i]);
        }
        printf("|    |\n");
        satir++;
    }
    printf("+-");
    for (i = 0; i < 7; i++) {
        printf("---+");
    }
    printf("----+\n");
}

void initializegame(int n, int board[2][6]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            board[i][j] = n;
        }
    }
}

int move(int board[2][6], int choice, char oyuncu[1], int computer, int player) {
    int j,b,c,current,flag=0,kopya;
    if (oyuncu[0] == 'c') {
        current = choice - 1;
        int ccontrol=computer;
        int bcontrol=board[0][0];
        int finalcup=0;
        int fcurrent1=1,fcurrent2;
        while(finalcup!=1){
        b=c=0;
        for (j = 0; j < 6; j++) {
            if (board[0][j] == 0) b++;
        }
        for (j = 0; j < 6; j++) {
            if (board[1][j] == 0) c++;
        }
        if(b==6 || c==6) return computer;


            flag=0;
            if(computer!=ccontrol && board[0][0]==bcontrol){
                oyuncu[0]='c';
                printboard(player,computer,board);
                return computer;
            }
            
            else {
                ccontrol=computer;
                bcontrol=board[0][0];
                }

            if(fcurrent1==1){ /*1.satırdaysa*/

                
                if(current==0 && board[1][current]==1  && fcurrent1==1){
                    board[1][current]-=1;
                    computer++;
                    printboard(player,computer,board);
                    return computer;
                }
                else if( board[1][current] > current+1  && fcurrent1==1) { /*Kendi cuplarını aşıyorsa*/
                    
                    while(current>0){
                            board[1][current-1]+=1;
                            finalcup=board[1][current-1];
                            fcurrent1=1;
                            fcurrent2=current-1;
                            board[1][choice-1]-=1;
                            current--;
                    }
                    if(current<=0){
                        computer++;
                        board[1][choice-1]-=1;
                            current=0;
                            while(board[1][choice-1]!=0){
                                board[0][current]+=1;
                                finalcup=board[0][current];
                                fcurrent1=0;
                                fcurrent2=current;
                                board[1][choice-1]-=1;
                                if(current==5) break;
                                else current++;
                            }
                        
                        if(board[1][choice-1]!=0){ /*Kendisine geri dönerse*/
                                current=5;
                                while(board[1][choice-1]!=0){
                                    if(current==choice-1){
                                        kopya=board[1][choice-1];
                                        while(kopya!=0){
                                            board[1][current]+=1;
                                            board[1][choice-1]-=1;
                                            kopya--;
                                            finalcup=board[1][current];
                                            fcurrent1=1;
                                            fcurrent2=current;
                                            flag=1;
                                            current--;
                                        }
                                    }
                                    else{
                                    board[1][current]+=1;
                                    finalcup=board[1][current];
                                    fcurrent1=1;
                                    fcurrent2=current;
                                    board[1][choice-1]-=1;
                                    current--;
                                    }
                                    if(flag==1) break;
                     }

                }
                            }

                        }

                
                else if((current+1==board[1][current]) && fcurrent1==1){ /*Tam kendi cubında bitiyor*/
                    computer++;
                    board[1][choice-1]-=1; /*Bir tane computera konulunca kese 1 azaldı*/
                    while(board[1][choice-1]!=0){
                            board[1][current-1]+=1;
                            board[1][choice-1]-=1;
                            finalcup=board[1][current-1];
                            fcurrent1=1;
                            fcurrent2=current-1;
                            current--;
                    }
                    printboard(player,computer,board);
                    return computer;
                }
                else if((current+1 > board[1][current])  && fcurrent1==1){ /*Aşmıyorsa*/
                    if(board[1][choice-1]==1 && current!=0){
                        board[1][choice-1]=0;
                        board[1][current-1]+=1;
                        finalcup=board[1][current-1];
                        fcurrent1=1;
                        fcurrent2=current-1;
                    }
                    else{
                      while(board[1][choice-1]!=0){
                            board[1][current-1]+=1; 
                            board[1][choice-1]-=1;
                            finalcup=board[1][current-1];
                            fcurrent1=1;
                            fcurrent2=current-1;
                            current--;
                    }
                    }
                    
                }
                printboard(player,computer,board);
                current=fcurrent2;
                choice=current+1;
            }
            else if(fcurrent1==0){ /*0.satırdaysa*/
                if(current==5 && board[0][choice-1]==1  && fcurrent1==0){
                    board[1][5]+=1;
                    board[0][choice-1]=0;
                    finalcup=board[1][5];
                    fcurrent1=1;
                    fcurrent2=5;
                }
                else if((board[0][current] + current<6) && fcurrent1==0){/*Aşağı indi ve aşmıyorsa*/
                    
                    if(board[0][choice-1]==1 && current!=5){
                        board[0][choice-1]=0;
                        board[1][current+1]+=1;
                        finalcup=board[1][current+1];
                        fcurrent1=1;
                        fcurrent2=current+1;
                    }
                    else if(board[0][choice-1]==1 && current==5){
                        board[0][choice-1]=0;
                        board[1][5]+=1;
                        finalcup=board[1][5];
                        fcurrent1=1;
                        fcurrent2=5;
                    }
                    
                    else{
                        while(board[0][choice-1]!=0){
                        board[0][current+1]+=1;
                        finalcup=board[0][current+1];
                        fcurrent1=0;
                        fcurrent2=current+1;
                        board[0][choice-1]-=1;
                        current++;
                    }
                    }
                }
                else if(board[0][current]+current>=6  && fcurrent1==0){/*Aşağı indi ve burda da aşıyor*/
                    while(current<5){
                        board[0][current+1]+=1;
                        finalcup=board[0][current+1];
                        fcurrent1=0;
                        fcurrent2=current+1;
                        board[0][choice-1]-=1;
                        current++;
                    }
                    current=5;
                     while(board[0][choice-1]!=0){
                        if(current>=0){
                        board[1][current]+=1;
                        finalcup=board[1][current];
                        fcurrent1=1;
                        fcurrent2=current;
                        board[0][choice-1]-=1;
                        current--;
                        }
                        else {
                            current=0; /*Kendi sırasına geri döndü*/
                            computer++;
                            board[0][choice-1]-=1;
                            while(board[0][choice-1]!=0){
                            if(current==choice-1){
                                kopya=board[0][choice-1];
                                while(kopya!=0){
                                    board[0][current]+=1;
                                    board[0][choice-1]-=1;
                                    kopya--;
                                    finalcup=board[0][current];
                                    fcurrent1=0;
                                    fcurrent2=current;
                                    current++;
                                    
                                }
                                flag=1;
                                break;
                            }
                            else{
                            board[0][current]+=1;
                            board[0][choice-1]-=1;
                            finalcup=board[0][current];
                            fcurrent1=0;
                            fcurrent2=current;
                            current++;
                            }
                            }
                        }
                        if(flag==1) break;
                     }
                     

                }
                current=fcurrent2;
                choice=current+1;
                printboard(player,computer,board);

            }

            
        }
        
        oyuncu[0]='p';
        return computer;
                
            }
    
    if (oyuncu[0] == 'p') {
        current = choice - 1;
        int pcontrol=player;
        int bcontrol=board[1][5];
        int finalcup=0;
        int fcurrent1=0,fcurrent2;
        while(finalcup!=1){
             b=c=0;
        for (j = 0; j < 6; j++) {
            if (board[0][j] == 0) b++;
        }
        for (j = 0; j < 6; j++) {
            if (board[1][j] == 0) c++;
        }
        if(b==6 || c==6) return player;


            flag=0;
            if(player!=pcontrol && board[1][5]==bcontrol) {
                oyuncu[0]='p';
                printboard(player,computer,board);
                return player;
            }
            
            else {
                pcontrol=player;
                bcontrol=board[1][5];
                }
            if(fcurrent1==0){
                
                if(current==5 && board[0][current]==1  && fcurrent1==0){
                    board[0][current]-=1;
                    player++;
                    printboard(player,computer,board);
                    return player;
                }
                else if(current+ board[0][current]>6  && fcurrent1==0) { /*Kendi cuplarını aşıyorsa*/
                    
                    while(current<5){
                            board[0][current+1]+=1;
                            finalcup=board[0][current+1];
                            fcurrent1=0;
                            fcurrent2=current+1;
                            board[0][choice-1]-=1;
                            current++;
                        
                    }
                    if(current>=5){
                        player++;
                        board[0][choice-1]-=1;
                            current=5;
                            while(board[0][choice-1]!=0){
                                board[1][current]+=1;
                                finalcup=board[1][current];
                                fcurrent1=1;
                                fcurrent2=current;
                                board[0][choice-1]-=1;
                                if(current==0) break;
                                else current--;
                               
                            }
                        
                        if(board[0][choice-1]!=0){ /*Kendisine geri dönerse*/
                                current=0;
                                while(board[0][choice-1]!=0){
                                    if(current==choice-1){ /*Kendisini de arttırması gerekirse*/
                                        kopya=board[0][choice-1];
                                        while(kopya!=0){
                                            board[0][current]+=1;
                                            board[0][choice-1]-=1;
                                            kopya--;
                                            finalcup=board[0][current];
                                            fcurrent1=0;
                                            fcurrent2=current;
                                            current++;
                                        }
                                        flag=1;
                                    }
                                    else{
                                        board[0][current]+=1;
                                        finalcup=board[0][current];
                                        fcurrent1=0;
                                        fcurrent2=current;
                                        board[0][choice-1]-=1;
                                        current++;
                                    }
                            
                            if(flag==1) break;
                     }

                }
                            }

                        }

                
                else if((current+board[0][current]==6) && fcurrent1==0){
                    player++;
                    board[0][choice-1]-=1; /*Bir tane playera konulunca kese 1 azaldı*/
                    while(board[0][choice-1]!=0){
                            board[0][current+1]+=1;
                            board[0][choice-1]-=1;
                            finalcup=board[0][current+1];
                            fcurrent1=0;
                            fcurrent2=current+1;
                            current++;
                    }
                    printboard(player,computer,board);
                    return player;
                }
                else if((current+board[0][current]<6)  && fcurrent1==0){
                    if(board[0][choice-1]==1 && current!=5){
                        board[0][choice-1]=0;
                        board[0][current+1]+=1;
                        finalcup=board[0][current+1];
                        fcurrent1=0;
                        fcurrent2=current+1;
                    }
                    else{
                      while(board[0][choice-1]!=0){
                            board[0][current+1]+=1;
                            board[0][choice-1]-=1;
                            finalcup=board[0][current+1];
                            fcurrent1=0;
                            fcurrent2=current+1;
                            current++;
                    }
                    }
                    
                }
                printboard(player,computer,board);
                current=fcurrent2;
                choice=current+1;
            }
            else if(fcurrent1==1){
                if(current==0 && board[1][choice-1]==1  && fcurrent1==1){
                    board[0][0]+=1;
                    board[1][choice-1]=0;
                    finalcup=board[0][0];
                    fcurrent1=0;
                    fcurrent2=0;
                   
                }
                else if(board[1][current]<current+1 && fcurrent1==1){/*Yukarı çıktı ve aşmıyorsa*/
                    
                    if(board[1][choice-1]==1 && current!=0){
                        board[1][choice-1]=0;
                        board[0][current-1]+=1;
                        finalcup=board[0][current-1];
                        fcurrent1=0;
                        fcurrent2=current-1;
                    }
                    else if(board[1][choice-1]==1 && current==0){
                        board[1][choice-1]=0;
                        board[0][0]+=1;
                        finalcup=board[0][0];
                        fcurrent1=0;
                        fcurrent2=0;
                    }
                    
                    else{
                        while(board[1][choice-1]!=0){
                        board[1][current-1]+=1;
                        finalcup=board[1][current-1];
                        fcurrent1=1;
                        fcurrent2=current-1;
                        board[1][choice-1]-=1;
                        current--;
                    }
                    }
                }
                else if(board[1][current]>=current+1  && fcurrent1==1){/*Yukarı taştı ve burda da aşıyor*/
                    while(current>0){
                        board[1][current-1]+=1;
                        finalcup=board[1][current-1];
                        fcurrent1=1;
                        fcurrent2=current-1;
                        board[1][choice-1]-=1;
                        current--;
                    }
                    current=0;
                     while(board[1][choice-1]!=0){
                        if(current<=5){
                        board[0][current]+=1;
                        finalcup=board[0][current];
                        fcurrent1=0;
                        fcurrent2=current;
                        board[1][choice-1]-=1;
                        current++;
                        }
                        else {
                            current=5; /*Kendi sırasına geri döndü*/
                            player++;
                            board[1][choice-1]-=1;
                            while(board[1][choice-1]!=0){
                            if(current==choice-1){
                                 kopya=board[1][choice-1];
                                while(kopya!=0){
                                    board[1][current]+=1;
                                    board[1][choice-1]-=1;
                                    kopya--;
                                    finalcup=board[1][current];
                                    fcurrent1=1;
                                    fcurrent2=current;
                                    current--;
                                    
                                }
                                flag=1;
                                break;
                            }
                            else{
                            board[1][current]+=1;
                            board[1][choice-1]-=1;
                            finalcup=board[1][current];
                            fcurrent1=1;
                            fcurrent2=current;
                            current--;
                            }
                            }
                        }
                        if(flag==1) break;
                     }

                }
                current=fcurrent2;
                choice=current+1;
                printboard(player,computer,board);

            }

            
        }
        oyuncu[0]='c';
        return player;
                
            }
             
        }

    


int gameplay(int board[2][6],char oyuncu[1]) {
    int choice, player = 0, computer = 0, b, c, j,cchoice=-1,temp;
    printf("Computer: Left cup and top board\n");
    printf("Player: Right cup and buttom board\n");
    while (1) {
        if(cchoice>=5) cchoice--;
        else cchoice++;
        b = 0, c = 0;
        for (j = 0; j < 6; j++) {
            if (board[0][j] == 0) b++;
        }
        for (j = 0; j < 6; j++) {
            if (board[1][j] == 0) c++;
        }
        if (b == 6 || c == 6) {
            printf("GAME OVER\n");
            printf("Total point of player: %d\nTotal point of computer: %d\n", player, computer);
            if (player > computer) printf("Player wins\n");
            else if(player < computer) printf("Computer wins\n");
            else printf("The game ended in a draw\n");
            return 0;
        }
        if (oyuncu[0] == 'c') {
            printf("Computer's turn! Selected cup: ");
            do{
                if(cchoice==5) cchoice=0;
                else cchoice++;
            }while(board[1][cchoice]==0);
            choice=cchoice+1; 
            printf("%d\n",choice);
            
            computer = move(board, choice, oyuncu, computer, player);

        }
        if (oyuncu[0] == 'p') {
            printf("Player's turn! Please select a cup: ");
            scanf(" %d", &temp);
            if(board[0][temp-1]==0 || temp<1 || temp>6){
                do{
                    printf("Invalid cup. Please select another cup: ");
                    scanf(" %d", &temp);

                }while(board[0][temp-1]==0  || temp<1 || temp>6);
            }
            choice=temp;
            player = move(board, choice, oyuncu, computer, player);

        }
    }
}

int main() {
    int player = 0, computer = 0, board[2][6],n;
    char oyuncu[1]="p";
    printf("Enter the number for each cup: ");
    scanf(" %d",&n);
    initializegame(n, board);
    printboard(player, computer, board);
    gameplay(board,oyuncu);
    return 0;
}
