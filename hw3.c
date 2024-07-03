#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int xposition= 256,flag=0;
int p= 137, ects1=0, ects2=0;
int counter=0;
int satir1[4],sutun1[4],satir2[3],sutun2[3];
int diskareler[]= {69, 70, 71, 72, 73, 74, 75, 76, 77, 85, 93, 101, 109, 117, 125, 133, 141, 149, 157, 165, 173, 181, 189, 197, 198, 199, 200, 201, 202, 203, 204, 205};
int ickareler[]= {103, 104, 105, 106, 107, 119, 123, 135, 139, 151, 155, 167, 168, 169, 170, 171,172};
void initialize_game(int size){
    int i,j;
    srand(time(NULL));
    
    /* önce 2 için*/
    for(i=0; i<3; i++){
        satir2[i]= rand() % 7 + 6; /*satir olarak 6 ile 12 arası sayi seçer*/
        if(satir2[i]==6) sutun2[i]=rand() %7 + 86; /*86 92 arası sayı seç*/
        if(satir2[i]==12) sutun2[i]= rand() %7 + 182; /*182 188 arası sayı seç*/

        else sutun2[i]= rand() % 2 == 0 ? 86+(size*(satir2[i]-6)) : 92+(size*(satir2[i]-6));

        if(i==1){ /*aynı nokta gelmesin diye kontrol edilir*/
        while(sutun2[i]==sutun2[i-1]){
            if(satir2[i]==6) sutun2[i]=rand()%7 + 86; /*86 92 arası sayı seç*/
            if(satir2[i]==12) sutun2[i]= rand()%7 + 182; /*182 188 arası sayı seç*/
            else sutun2[i]= rand() % 2 == 0 ? 86+(size*(satir2[i]-6)) : 92+(size*(satir2[i]-6));
        } 
        }
        else if(i==2){
          while(sutun2[i]==sutun2[i-1] || sutun2[i]==sutun2[i-2]){
            if(satir2[i]==6) sutun2[i]=rand()%7 + 86; /*86 92 arası sayı seç*/
             if(satir2[i]==12) sutun2[i]= rand()%7 + 182; /*182 188 arası sayı seç*/
            else sutun2[i]= rand() % 2 == 0 ? 86+(size*(satir2[i]-6)) : 92+(size*(satir2[i]-6));
        }
        }

         }
    
    /*şimdi 1 için*/
    for(j=0; j<4; j++){
         satir1[j]= rand() %3 +8 ;/*satir olarak 8 ile 10 arası seç */
         if(satir1[j]==9) sutun1[j]= rand() % 2 == 0 ? 136 : 138; /*burda 2 sayıdan birini seçtirme kodu için yardım aldım*/
         else sutun1[j]= rand() %3 + (136+(16*(satir1[j]-9)));
           if(j==1){
           while( sutun1[j]==sutun1[j-1]){
            satir1[j]= rand() %3 +8 ;/*satir olarak 8 ile 10 arası seç */
         if(satir1[j]==9) sutun1[j]= rand() % 2 == 0 ? 136 : 138; 
         else sutun1[j]= rand() %3 + (136+(16*(satir1[j]-9)));
            
           }
           }
           else if(j==2){
           while( sutun1[j]==sutun1[j-1] ||  sutun1[j]==sutun1[j-2] ){
             satir1[j]= rand() %3 +8 ;/*satir olarak 8 ile 10 arası seç */
         if(satir1[j]==9) sutun1[j]= rand() % 2 == 0 ? 136 : 138; 
         else sutun1[j]= rand() %3 + (136+(16*(satir1[j]-9)));
           }
           }
            else if(j==3){
                while( sutun1[j]==sutun1[j-1] ||  sutun1[j]==sutun1[j-2] || sutun1[j]==sutun1[j-3]){
                    satir1[j]= rand() %3 +8 ;/*satir olarak 8 ile 10 arası seç */
             if(satir1[j]==9) sutun1[j]= rand() % 2 == 0 ? 136 : 138; 
             else sutun1[j]= rand() %3 + (136+(16*(satir1[j]-9)));

                }

            }
           
        }

}

void print_board() {
    int i, k = 0,m=0;
    int flag;
    printf("\n");
    for (i = 1; i < 257; i++) {
       
        for(m=0; m<4; m++){
        if(p==sutun1[m]){ 
        sutun1[m]=300;
        ects1+=8;
        
        }
        }

       
        for(k=0; k<3; k++){
        if(p==sutun2[k]){
        sutun2[k]=300;
        ects2+=8;
             }
         
        }
         flag=0;;
        if (i == p && i%16==0) printf("P\n");
        else if(i==p) printf("P ");

        else{

        for(k=0; k<32; k++){
            if(i==diskareler[k]){ printf("# ");
            flag=1;
            }
        }
         for(k=0; k<16; k++){
            if(i==ickareler[k]){ printf("# ");
            flag=1;
            }
        }
       
        if(flag==0){
       
        if (i == 256) printf("X\n");
      
        else if (i % 16 == 0) {
            printf(".\n");
        }
      
        else if (i == sutun2[0] || i == sutun2[1] || i == sutun2[2]) printf("2 ");
        else if (i == sutun1[0] || i == sutun1[1] || i == sutun1[2] || i == sutun1[3]) printf("1 ");
       
        else printf(". ");
    }
        }
    }
}



void move_player(char move){
  
    int r;
	 if (move=='w' || move=='W') p=p-16;
     if (move=='a' || move=='A') p= p-1; 
     if (move=='s' || move=='S') p= p+16;
     if (move=='d' || move=='D') p= p+1;
    

if (ects1 == 32 && ects2 < 24){
    for(r=0; r<32; r++){
        if(p==diskareler[r])  {
     printf("You don't have enough ects!\n");
     if (move=='w' || move=='W') p=p+16;
     if (move=='a' || move=='A') p= p+1; 
     if (move=='s' || move=='S') p= p-16;
     if (move=='d' || move=='D') p= p-1;
     break;
        }
    }
   
 }  
 else if (ects1<32){
    for(r=0; r<32; r++){
        if(p==ickareler[r]){
     printf("\nYou don't have enough ects!\n");
     if (move=='w' || move=='W') p=p+16;
     if (move=='a' || move=='A') p= p+1; 
     if (move=='s' || move=='S') p= p-16;
     if (move=='d' || move=='D') p= p-1;
     break;
 }
 }


}
     counter++;
}


int main(){
    char move;
    
    initialize_game(16);
    print_board();
    while(p!=xposition){
   
    printf("Total ECTS: %d\n",ects1+ects2);
    printf("Enter your move: ");
    scanf(" %c",&move);
    move_player(move);
    print_board();
    }
    printf("You won!\nCount of movements: %d\nTotal ECTS= %d\n",counter,ects1+ects2);
    return 0;
}
