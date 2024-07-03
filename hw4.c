#include <stdio.h>

    float midterm(float mavrg, float maverage){ /*function for returning midterm grade*/
    float k,kontrol,kontrol2;
     if(mavrg<40 && mavrg<maverage) k=1;
     if(mavrg>40 && mavrg<maverage) {
        kontrol= mavrg-40;
        kontrol2= maverage-mavrg;
        if(kontrol<kontrol2) k=2.5; /*grade is checked for proximity to 40 or average, assign 2.5 if close to 40, assign 3 if close to average(because of the two same condition)*/
        else k=3;
     }
  
     if(mavrg>40 && mavrg>maverage) k=3.5;
     if(mavrg>90) k=4;
     return k;
}
float final(float f, float faverage){ /*function for final grade*/
    float k;
    if(f<40 && f<faverage) k=1;
    if(f>40 && f<faverage) k=2.5;
    if(f>40 && f>faverage) k=3;
    if(f<90 && f>faverage) k=3.5;
    if(f>90) k=4;
    return k;
}
char yuvarla(float ort){ /*function for converting grade numbers not in the given list to letter grade*/
    float min,k,minfinal=90,kfinal;
    char grade;
    k=4.0;
    while(k>=1){ /*rounds the grade to the nearest value for cases where the average is not 1, 2.5, 3, 3.5, or 4*/
        min=k-ort;
        if(min<0) min*=-1;
        if(min<minfinal){
            minfinal=min;
            kfinal=k; 
        } 
        if(k==2.5) k-=1.5;
        else k-=0.5;
       
    }
    if(kfinal==4) grade='A';
    if(kfinal==3.5) grade='B';
    if(kfinal==3) grade='C';
    if(kfinal==2.5) grade='D';
    if(kfinal==1) grade='F';
    return grade;
}
 
    char first_initial(FILE *fp, int id){
        char fi;
        int id2,counter,flag,temp;
        while(fscanf(fp,"%d",&id2)==1){
        counter=0; /*counter to count semicolon number*/
        flag=0;
        fscanf(fp,";%c",&fi);
        if(id2==id) return fi;
        else { /*if read id is not equal to given id, read reamining characters from the current line*/
            while(flag!=1){
            fscanf(fp,"%c",&fi);
            if(fi==';') counter++;
            if(counter==3){
                fscanf(fp,"%d",&temp); /*after last semicolon read the integer value*/
                flag=1; /*this flag is required for reading the new line from beginning*/
            }
            }
        }
        }
    }

    char last_initial(FILE *fp, int id){
        char li,temp;
        int id2,counter,flag,tempint;
        while(fscanf(fp," %d",&id2)==1){
        counter=0;
        flag=0;
        if(id==id2){
            
            while(fscanf(fp,"%c",&li)==1){
            if(li==';') counter++; 
            if(counter==2){
                 fscanf(fp,"%c",&li); /*after reading 2 semicolons, read again and return it*/
                 return li;
            }
            }
        }
       else{ /*if read id is not equal to given id, read the remaining current line*/
            while(flag!=1){
                fscanf(fp,"%c",&temp);
                if(temp==';') counter++;
                if(counter==4){
                    fscanf(fp,"%d",&tempint);
                    flag=1; /*breaks while loop and code goes the new line*/
            }
        }
       }
    
    }
    }
    int get_id_fi(FILE *fp, char first_initial){
        char fi,temp;
        int id,flag,counter,tempint;
        while(fscanf(fp,"%d",&id)==1){
            flag=0;
            counter=0;
            fscanf(fp,";%c",&fi); /*reads first semicolon and character, after id,*/
            if(fi==first_initial){
                 while(flag!=1){ /*reads until the beginning of each line*/
                    fscanf(fp,"%c",&temp);
                    if(temp==';') counter++;
                    if(counter==3){ /*there are 3 semicolons after the first semicolon*/
                        fscanf(fp,"%d",&tempint);
                        return id;
            } 
                 }
            }
                 
            else{
                while(flag!=1){ /*reads until the beginning of each line*/
                    fscanf(fp,"%c",&temp);
                    if(temp==';') counter++;
                    if(counter==3){ 
                        fscanf(fp,"%d",&tempint);
                        flag=1;
                    }
                }
            }
        }
       

    
        }
    

    int get_id_li(FILE *fp, char last_initial){
        char li,temp;
        int id,flag,counter,tempint;
         while(fscanf(fp,"%d",&id)==1){
            flag=0;
            counter=0;
            while(flag!=1){
            fscanf(fp,"%c",&temp);
            if(temp==';') counter++;
            if(counter==2){ /*if the last read character is the second semicolon, next character must be the last inital*/
                fscanf(fp,"%c",&li);
                if(li==last_initial){
                    while(flag!=1){
                    fscanf(fp,"%c",&temp);
                    if(temp==';') counter++;
                    if(counter==4){ 
                         fscanf(fp,"%d",&tempint); /*read the current line until its end*/
                        flag=1;
                    } 
                    }
                     return id;
                }
                else{
                    while(flag!=1){ 
                    fscanf(fp,"%c",&temp);
                    if(temp==';') counter++;
                    if(counter==4){ /*after 4th semicolon, read temp integer and continiue with new line*/
                         fscanf(fp,"%d",&tempint); 
                        flag=1;
                    } 
                }
            }
            
            }

        

    }
         
    }
    }

    float average_grade(FILE *fp, int id){ /*function for calculating average grade for the given id*/
        int i,m1,m2,f,cid,id2;
        int mtoplam=0,ftoplam=0,mtoplam2=0,ftoplam2=0;
        float faverage,maverage,faverage2,maverage2;
        int counter=0, counter2=0;
        for(i=0; i<25; i++){
          fscanf(fp,"%d;%d;%d;%d;%d",&id2,&m1,&m2,&f,&cid);
          mtoplam+=(m1+m2)/2;
          ftoplam+=f;
          if(id2==id) {
             mtoplam2+=(m1+m2)/2;
             ftoplam2+=f;
           counter2++;
          }
          counter++;
        }
     
        
        for(i=0; i<25; i++){
          fscanf(fp,"%d;%d;%d;%d",&id2,&m1,&f,&cid);
          mtoplam+=m1;
          ftoplam+=f;
          if(id2==id) {
             mtoplam2+=m1;
             ftoplam2+=f;
             counter2++;
          }
          counter++;
        }

        float gpa1;
        maverage2= mtoplam2/counter2;
        faverage2=ftoplam2/counter2;
        maverage=mtoplam/counter;
        faverage=ftoplam/counter;
 

             float mid=midterm(maverage2,maverage);/*finds corresponding grade number for midterm*/
             float fnl= final(faverage2,faverage); /*finds corresponding grade number for final*/
             gpa1= (mid+fnl)/2;

            
             
             return gpa1;

   
    }

void topla(FILE *fp, int cid, float *maverag, float *faverag){ /*finds midterm and final average for the given course id*/
     int i,m1,m2,f,cid2,id2; 
        int mtoplam=0,ftoplam=0,mtoplam2=0,ftoplam2=0;
        float faverage,maverage,faverage2,maverage2;
        int counter=0, counter2=0;
        for(i=0; i<25; i++){
          fscanf(fp,"%d;%d;%d;%d;%d",&id2,&m1,&m2,&f,&cid2);
          
          if(cid2==cid) { /*check whether the student's course id matches with the given course id*/
             mtoplam2+=(m1+m2)/2;
             ftoplam2+=f;
             counter2++; /*counts number of students*/
          }
      
        }
     
        
        for(i=0; i<25; i++){
          fscanf(fp,"%d;%d;%d;%d",&id2,&m1,&f,&cid2);
         
          if(cid2==cid) {
             mtoplam2+=m1;
             ftoplam2+=f;
             counter2++;
          }
    
        }
        maverage=mtoplam2/counter2;
        faverage=ftoplam2/counter2;
        *maverag= maverage;
        *faverag= faverage;
        fclose(fp);
   
}


int main(){
    char choice,fn,ln,role,role2;
    printf("p: Print all the users pass or fail.\n");
    printf("n: Print only the user with a specific first initial.\n");
    printf("g: Calculate the GPA of a given student.\n");
    printf("c: Print whether each user passed or failed the same class.\n");
    printf("t: Print the number of classes for the instructor.\n");
    printf("d: Print the department of all persons according to the role.\n");
    printf("l: Print the course_id of a given student.\n");
    printf("e: Quit the program.\n");
     printf("Enter your choice: ");
    scanf("%c",&choice);
    FILE *dosya,*dosya2;
    while(1){
    dosya= fopen("first.txt","r");
    int i,id;
    float mid,fnl,ort;
    float mavrg=0;
    int cid2;
    int m1,m2,f,cid,faverage,maverage,faverage2,maverage2;
    float mtoplam=0,ftoplam=0, mtoplam2=0,ftoplam2=0;
    int counter=0,counter2=0;
    switch(choice){

         case '0': /*testing for first_initial function*/
         printf("Enter id: ");
         scanf("%d",&id);
         dosya=fopen("second.txt","r");
         role=first_initial(dosya,id);
         printf("%c\n",role);
         fclose(dosya);
         break;

         case '1': /*testing for last_initial function*/
         printf("Enter id: ");
         scanf("%d",&id);
         dosya=fopen("second.txt","r");
         role=last_initial(dosya,id);
         printf("%c\n",role);
         fclose(dosya);
         break;

         case '2': /*testing for get_id_fi function*/
         printf("Enter letter: ");
         scanf(" %c",&role);
         dosya=fopen("second.txt","r");
         while(feof(dosya)==0){ /*call get_id_fi function until end of file*/
         m1=get_id_fi(dosya,role);
         if(m1!=-1)  printf("%d\n",m1); 
         }
         fclose(dosya);
         break;

         case '3':  /*testing for get_id_li function*/
         printf("Enter letter: ");
         scanf(" %c",&role);
         dosya=fopen("second.txt","r");
         while(feof(dosya)==0){
         
         m1=get_id_li(dosya,role);
         if(m1!=-1)  printf("%d\n",m1); 
        
        }
         fclose(dosya);
         break;

        case 'p': 
        char sonuc;
        faverage=0,maverage=0,faverage2=0,maverage2=0;
        mtoplam=0,ftoplam=0,counter=0, mtoplam2=0,ftoplam2=0,counter2=0;
        mavrg=0;
        for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d;%d",&id,&m1,&m2,&f,&cid);
            mtoplam+=(m1+m2)/2;
            ftoplam+=f;
            counter++;
        }
        for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d",&id,&m1,&f,&cid);
            mtoplam2+=m1;
            ftoplam2+=f;
            counter2++;
        }
        maverage=mtoplam/counter;
        faverage=ftoplam/counter;
        maverage2=mtoplam2/counter2;
        faverage2=ftoplam2/counter2;
        fclose(dosya);
        dosya= fopen("first.txt","r");
        printf("\n102 GRADES\n\n");
        for(i=0; i<25; i++){
             fscanf(dosya," %d;%d;%d;%d;%d ",&id,&m1,&m2,&f,&cid);
             mavrg= (m1+m2)/2;
             if(mavrg<40 && mavrg<maverage && f<40 && f<faverage){
                printf("%d F \n",id);
             }
              else if(mavrg>40 && mavrg<maverage && f>40 && f<faverage){
                 printf("%d D \n",id);
             }
                         
             else if(mavrg>40 && mavrg<maverage && f>40 && f>faverage){
                 printf("%d C \n",id);
             }
            
             else if(mavrg>40 && mavrg>maverage && f<90 && f>faverage){
                 printf("%d B \n",id);
            }

             else if(mavrg>90 && f>90){
                 printf("%d A \n",id);

            }

             else {

             mid=midterm(mavrg,maverage);
          
             fnl= final(f,faverage);
            
             ort= (mid+fnl)/2;
             sonuc=yuvarla(ort);
      
             printf("%d %c\n", id,sonuc);
             }  
             
        }
        printf("\n108 GRADES\n\n");
            for(i=0; i<25; i++){
                fscanf(dosya," %d;%d;%d;%d",&id,&m1,&f,&cid);
 
             if(m1<40 && m1<maverage2 && f<40 && f<faverage2){
                 printf("%d F\n",id);
                }
            else if(m1>40 && m1<maverage2 && f>40 && f<faverage2){
                printf("%d D\n",id);
            }
             else if(m1>40 && m1<maverage2 && f>40 && f>faverage2){
                 printf("%d C\n",id);
             }
             else if(m1>40 && m1>maverage2 && f<90 && f>faverage2){
                 printf("%d B\n",id);
             }
            else if(m1>90 && f>90){
                 printf("%d A\n",id);

            }
            else { /*do this else statement if none of them above is suitable for grades*/
             mid=midterm(m1,maverage2);
          
             fnl= final(f,faverage2);
            
             ort= (mid+fnl)/2;
             sonuc=yuvarla(ort); /*returns letter grade*/
      
             printf("%d %c\n", id,sonuc);
            }

    }
     fclose(dosya);
     break;
        case 'n': 
        char letter,fn;
        dosya2= fopen("second.txt","r");
        
        printf("Input a letter: ");
        scanf(" %c",&letter);
        int flag3;
        float gpa4;
       while(fscanf(dosya2," %d",&id)==1){
      
        flag3=0;
        counter=0;
        fscanf(dosya2,";%c",&fn);
        if(fn==letter){
            if(id/100000000==2){ /*for not considering instructors*/
            dosya=fopen("first.txt","r");
            gpa4=average_grade(dosya,id);
            printf("%d--GPA: %.2f\n",id,gpa4);
            fclose(dosya);
            }
        }
        while(flag3!=1){
          
        fscanf(dosya2,"%c",&fn);
        if(fn==';') counter++;
        if(counter==3) {
           
            fscanf(dosya2,"%d",&cid);
            flag3=1;
        }
        }
       }
    
    fclose(dosya2);
    break;
    
    case 'g': 
        dosya= fopen("first.txt","r");
        printf("Enter user id: ");
        scanf("%d",&id);
        float gpa= average_grade(dosya,id);
        printf("GPA of the student: %.2f\n",gpa);
        fclose(dosya);
        break;


        
        case 'd':
        int department;
        int flag,j;
        char karakter;
        char yeni;
       
        FILE *dosya3;
        dosya3= fopen("second.txt","r");
        printf("Enter a letter for role: ");
        scanf(" %c",&role);
       
    while (fscanf(dosya3, "%d",&id)==1){
       
            flag=0;
            counter=0;
        while(flag!=1){
           
            fscanf(dosya3, "%c",&karakter);
            if(karakter==';') counter+=1;
            if(counter==3){
              
                fscanf(dosya3, "%c",&karakter); /*after 3rd semicolon, next character must be the initial letter for role*/
          
                if(karakter==role) {
                   
                    while(fscanf(dosya3, "%c",&karakter)==1){
                        if(karakter==';'){
                        fscanf(dosya3, "%d",&department); 
                        printf("ID:%d---Department:%d\n",id,department);
                        flag=1;
                        break;
                        }
                      
                    }
                }
               else {
                while(fscanf(dosya3, "%c",&karakter)==1){ /*reads until end of the line*/
                        if(karakter==';'){
                             fscanf(dosya3, "%d",&department); 
                             flag=1;
                             break;
                        }
               
               }
            }
            
        }
       
        }
    }
        fclose(dosya3);
        break;

        case 't': 
        int sharp,id2;
        dosya= fopen("first.txt","r");
        printf("Enter user id: ");
        scanf(" %d",&id2);
       
              for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d;%d",&id,&m1,&m2,&f,&cid);
       
        }
         for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d",&id,&m1,&f,&cid); /*ignore first 25+25 lines*/
            
        }
          for(i=0; i<10; i++){
            fscanf(dosya,"%d;%d;%d",&id,&sharp,&cid);
            if(id2==id) printf("Class is %d for the instructor\n",sharp);
        }
            
        
        fclose(dosya);
        break;

        case 'l':
        int flag2=0;
        dosya= fopen("first.txt","r");
        printf("Enter user id: ");
        scanf(" %d",&id2);
        for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d;%d",&id,&m1,&m2,&f,&cid);
          if(id2==id) { printf("Course id of the student: %d\n",cid);flag2=1;}
          
        }
        for(i=0; i<25; i++){
            fscanf(dosya,"%d;%d;%d;%d",&id,&m1,&f,&cid);
            if(id2==id){ printf("Course id of the student: %d\n",cid); flag2=1;}
        }
        for(i=0; i<10; i++){
            fscanf(dosya,"%d;%d;%d",&id,&m1,&cid); /*gives warning when the id matches with an instructor id*/
            if(id2==id) { printf("This person is not a student!\n",cid); flag2=1;}
        }
        if(flag2==0) printf("There is no student matching the given ID!\n");
        fclose(dosya);
        break;

        case 'c':
        float temp,ftemp;
        float mavrge=0;
        cid2;
        float maverage22=0,faverage22=0;
        mtoplam=0,ftoplam=0,counter2=0;
        dosya=fopen("first.txt","r");
        printf("Enter course id: ");
        scanf(" %d",&cid2); 
        topla(dosya,cid2,&maverage22,&faverage22); /*this function closes the opened file*/
        dosya=fopen("first.txt","r"); /*same file opened again*/
        float sonuc33=(maverage22+faverage22)/2;
        printf("Average grade for course: %.2f\n",sonuc33); /*average for the given course*/
        fclose(dosya);
        dosya=fopen("first.txt","r");
        if(cid2==102){ /*if course is 102 read first 25 lines*/
            for(i=0;i<25;i++){
                fscanf(dosya,"%d;%d;%d;%d;%d",&id,&m1,&m2,&f,&cid);
                mavrg=(m1+m2)/2;
          if(mavrg<40 && mavrg<maverage22 && f<40 && f<faverage22){
                printf("%d F \n",id);
             }
              else if(mavrg>40 && mavrg<maverage22 && f>40 && f<faverage22){
                 printf("%d D \n",id);
             }
                         
             else if(mavrg>40 && mavrg<maverage22 && f>40 && f>faverage22){
                 printf("%d C \n",id);
             }
            
             else if(mavrg>40 && mavrg>maverage22 && f<90 && f>faverage22){
                 printf("%d B \n",id);
            }

             else if(mavrg>90 && f>90){
                 printf("%d A \n",id);

            }
            
             else {

             mid=midterm(mavrg,maverage22);
          
             fnl= final(f,faverage22);
            
             ort= (mid+fnl)/2;
             sonuc=yuvarla(ort);
      
             printf("%d %c\n", id,sonuc);
             }  
            }
             
        }
        else if(cid2==108){ /*if course id is 108 ignore first 25 lines*/
            for(i=0; i<25; i++){
                fscanf(dosya," %d;%d;%d;%d;%d",&id,&m1,&m2,&f,&cid); /*ignoring part*/
            }
            for(i=0; i<25; i++){
                fscanf(dosya," %d;%d;%d;%d",&id,&m1,&f,&cid);
 
             if(m1<40 && m1<maverage22 && f<40 && f<faverage22){
                 printf("%d F\n",id);
                }
            else if(m1>40 && m1<maverage22 && f>40 && f<faverage22){
                printf("%d D\n",id);
            }
             else if(m1>40 && m1<maverage22 && f>40 && f>faverage22){
                 printf("%d C\n",id);
             }
             else if(m1>40 && m1>maverage22 && f<90 && f>faverage22){
                 printf("%d B\n",id);
             }
            else if(m1>90 && f>90){
                 printf("%d A\n",id);

            }
            else { 
             mid=midterm(m1,maverage22);
          
             fnl= final(f,faverage22);
            
             ort= (mid+fnl)/2;
             sonuc=yuvarla(ort);
      
             printf("%d %c\n", id,sonuc);
            }
        }
        }
        
        fclose(dosya);
        break;

        case 'e': return 0;


    }
    printf("Enter your choice: ");
    scanf(" %c",&choice);
}
        
    }
