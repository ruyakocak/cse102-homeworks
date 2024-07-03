#include <stdio.h>
#include <string.h>

int to_binary(int decimal_number){
    int binary = 0;
    int base = 1;
    while (decimal_number > 0) {
        int remainder = decimal_number % 2;
        binary = binary + remainder * base;
        decimal_number/=2;
        base = base * 10;
    }

    return binary;
}

int to_decimal(char binary_number[]){
    int decimal = 0,i,bit;
    int base = 1;
    int length = strlen(binary_number);

    for (i = length - 1; i >= 0; i--) {
        bit = binary_number[i] - '0';
        decimal += bit * base;
        base *= 2;
    }

    return decimal;
 }

void binaryToCharArray(int binaryNumber, char* charArray) {

    if (binaryNumber == 0) { /*binarynumber 0 ise sadece bir '0' karakteri atanır*/
        charArray[0] = '0';
        charArray[1] = '\0'; 
        return;
    }
    int index=0, mod;
    while (binaryNumber > 0) {
        mod=binaryNumber%10;
        binaryNumber/=10;
        if(mod==1) charArray[index]= '1';
        else charArray[index]= '0';
        index++;
    }
    charArray[index] = '\0';
    char copyarray[10];
    strcpy(copyarray,charArray);
    int i, j=index-1;
    for (i=0;i<index; i++) { /*aynı array ters çevrilerek doğru hale getirilir*/
        charArray[i] = copyarray[j];
        j--;
    }
}

typedef struct {
    char memory[300][10]; /* 300 tane her biri 8 karakterden oluşan integerlar */
} stack;

int main() {
    char name[20], temp[30], temp2[30], readline[300], opcode[30], c1, c2, c3, c4,c5,c6,c7,newline;
    FILE *file, *file2;
    stack program;
    int i;
    for(i=0;i<200;i++){
      strcpy(program.memory[i],"00000000"); /*memorynin tüm ilk değerleri 0 ayarlandı*/
    }
    strcpy(program.memory[100],"00000101"); /*memorye istenen başlangıç değerleri konuldu*/
    strcpy(program.memory[101],"00000110");

    int pa=102; /*a registerının konumu 102 seçildi*/
    pa=to_binary(pa);
    int a_decimal;
    int pb=103; /*b registerının konumu 103 seçildi*/
    pb=to_binary(pb);
    int b_decimal;
    int j = 0, flag=0, line = 0, junk, station, temp_binary, result, decimal_number, tempnumber;
    
    do{
    printf("Enter filename: ");
    scanf("%s", name);

    file = fopen(name, "r");
    if (file == NULL) {
        printf("File opening error\n");
        return 0;
    }

    file2 = fopen("instructions 1.txt", "r");
    if (file2 == NULL) {
        printf("File opening error\n");
        return 0;
    }
    a_decimal=0;
    b_decimal=0;
    while(fscanf(file, "%d%c%s", &junk, &c1, temp)!=EOF){
        while (fgets(readline, sizeof(readline), file2) != NULL) {
           
            for (i = 11, j = 0; i < 17; i++, j++) {
                if (readline[i] == ' ') {
                    temp2[j] = '\0'; /* kopyalanan instructionun sonuna null karakter eklenir */
                    break;
                } else {
                    temp2[j] = readline[i];
                }
            }

            if (strcmp(temp, temp2) == 0) {
                strncpy(opcode,readline,8);
                opcode[8]='\0';
                strcpy(program.memory[line],opcode);
                line++;
                int num= to_decimal(opcode);
                if(num==26) {
                  fscanf(file,"%c%c",&c1,&c2);
                  if(c2=='A') 
                  binaryToCharArray(pa,program.memory[line]);
                  else binaryToCharArray(pb,program.memory[line]);

                  line++;
                }
                else if(num==30) {
                  flag=1;
                  break;
                }
 
                  else if(num==28){
                  fscanf(file,"%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5);
                  if(c4=='B'){ 
                  temp_binary=to_binary(b_decimal);
                  strcpy(program.memory[line],program.memory[temp_binary]);
                  }
                  else { 
                  temp_binary=to_binary(a_decimal);
                  strcpy(program.memory[line],program.memory[temp_binary]);
                  }

                  line++;
                }  
                else if(num==13 || num==14 || num==27){
                  fscanf(file,"%c%d",&c1,&tempnumber);
                  tempnumber=to_binary(tempnumber);
                  binaryToCharArray(tempnumber,program.memory[line]);

                  line++;
                }     
                  else if(readline[9]=='G'){
                  fscanf(file,"%c%c%c%c",&c1,&c2,&c3,&c4);
                  if(c2=='A') 
                  binaryToCharArray(pa,program.memory[line]);
                  
                  else binaryToCharArray(pb,program.memory[line]);

                  line++;
                  if(c4=='B') 
                  binaryToCharArray(pb,program.memory[line]);
                  
                  else binaryToCharArray(pa,program.memory[line]);

                  line++;
                }   
                else if(readline[9]=='T'){
                  fscanf(file,"%c%c%c%d",&c1,&c2,&c3,&tempnumber);                
                  if(c2=='A') 
                  binaryToCharArray(pa,program.memory[line]);
                  else binaryToCharArray(pb,program.memory[line]);

                  line++;
                  if(num==29 && c2=='A') a_decimal=tempnumber;
                  else if(num==29 && c2=='B') b_decimal=tempnumber; 
                  tempnumber=to_binary(tempnumber);
                  binaryToCharArray(tempnumber,program.memory[line]);
                  line++;
                                 
                }     
                 
                else if(readline[9]=='U'){
                  fscanf(file,"%c%c%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5,&c6,&c7);
                  if(c2=='A') 
                  binaryToCharArray(pa,program.memory[line]);
                  
                  else binaryToCharArray(pb,program.memory[line]);

                  line++;
                  if(c6=='B') {
                    strcpy(program.memory[line],program.memory[b_decimal]);
                  }
                  else {
                    strcpy(program.memory[line],program.memory[a_decimal]);
                  }


                  line++;
                }

                do{
                  fscanf(file,"%c",&c1); /*satır sonu karakterleri de okumak ama hesaba katmamak için*/
                }while(c1!='\n');

                
                rewind(file2);
                break;
            }
        }
        if(flag==1) break;
}   
    int linesfirst[70];
    strcpy(program.memory[105],"00000000");/*program counterın ilk değeri ayarlandı*/
    strcpy(program.memory[line],"00011110"); /*verilen kodda exit opcodunun olmaması ihtimaline karşı sona tekrar exit kodu konur*/
    strcpy(program.memory[line+1],"00011110");

          j=0;
          flag=0;
          int line_binary,currentline=0,flag2=0,next;
          while(1){

            if(flag2==2){
              j=to_decimal(program.memory[105]);
              linesfirst[currentline]=j;
              strcpy(program.memory[106],program.memory[j]);
              strcpy(program.memory[107],program.memory[j+1]);
              line_binary=to_binary(j+2);
              binaryToCharArray(line_binary,program.memory[105]);
              currentline++;
              flag2=0;
            }
            else{
             
              j=to_decimal(program.memory[105]);
              linesfirst[currentline]=j; /*her line için başlangıç j değerini  tutar*/
              strcpy(program.memory[106],program.memory[j]); /*memoryde 106 107 ve 108 instruction register olarak ayrıldı*/
              strcpy(program.memory[107],program.memory[j+1]);
              strcpy(program.memory[108],program.memory[j+2]);
              line_binary=to_binary(j+3);
              binaryToCharArray(line_binary,program.memory[105]);
              currentline++;
              
            }
            
              int decimal_opcode=to_decimal(program.memory[106]);
              if(decimal_opcode==30) break;

              next=to_decimal(program.memory[105]);
              next=to_decimal(program.memory[next]);

              if(next==13 || next==14 || next==26 ||next==27 || next==28){
                flag2=2;
              }
              
              int a=to_decimal(program.memory[107]); 
              int b=to_decimal(program.memory[108]);
              int adec= to_decimal(program.memory[a]);
              int bdec= to_decimal(program.memory[b]);
              
              switch(decimal_opcode){
                case 1: adec+=bdec;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 2: adec+=b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 3: adec+=b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 4: adec= adec & bdec;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;
                
                case 5: adec= adec & b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 6: adec= adec & b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 7: adec= adec | bdec;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 8: adec= adec | b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 9:  adec= adec | b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 10: adec= adec - bdec;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 11: adec= adec - b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 12: adec= adec - b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 13: adec+=1;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 14: adec-=1;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 15: adec= adec<<b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 16: adec=adec>>b;
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 17: if(adec==bdec) 
                adec=to_binary(linesfirst[adec-1]);
                binaryToCharArray(adec,program.memory[105]);
                break;

                case 18: if(adec!=bdec) 
                adec=to_binary(linesfirst[adec-1]);
                binaryToCharArray(adec,program.memory[105]);
                break;

                case 19: if(adec==bdec) 
                adec=to_binary(linesfirst[adec+bdec-1]);
                binaryToCharArray(adec,program.memory[105]);
                break;

                case 20: adec= ~(adec | bdec);
                adec= to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 21: strcpy(program.memory[a],program.memory[108]);
                break;

                case 22: strcpy(program.memory[a],program.memory[108]);
                break;

                case 23: strcpy(temp,program.memory[a]);
                strcpy(program.memory[a],program.memory[b]);
                strcpy(program.memory[b],temp);
                break;

                case 24: 
                if(adec<bdec) adec=1;
                else adec=0;
                adec=to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;

                case 25: 
                if(adec>bdec) adec=1;
                else adec=0;
                adec=to_binary(adec);
                binaryToCharArray(adec,program.memory[a]);
                break;
                
                case 26: printf("Value= %d\n",adec); result=adec;
                break;

                case 27: printf("Value= %d",a); result=a;
                break;

                case 28: printf("Value= %d",a); result=a;
                break;

                case 29:
                strcpy(program.memory[a],program.memory[108]);
                break;

                case 30: flag=1; break;
              }
            
              
              if(flag==1) break;
          }
          printf("Result of the execution: %d\n",result);
          line = 0;
          flag=0;
          j=0;
          fclose(file);
          fclose(file2);
          printf("Do you want to execute another assembly code: Press (1) for yes, Press (0) for exit: ");
          scanf(" %d",&station);
    }while(station!=0);
}

  
