#include <stdio.h>
#include <locale.h>

void printreadednews();
void printnews();
void menu();
void check();

double fx(double x){
    double a=(x*x*x)-(x*x)+2;
    return a;
}

double gx(double x){
    double a=x*x;
    return a;
}

void decrypt(){
    int choice;
    double sum=0.0,gvalue,number;
    char temp;
    FILE *file;
    printf("Which news would you like to decrypt?\n");
    scanf(" %d",&choice);
    switch(choice){
        case 1:
        file=fopen("1.txt","r");
        while(fscanf(file,"%c",&temp)!=EOF){
            printf("%c",temp);
             if(temp=='#'){
                fscanf(file," %lf",&number);
                printf("%d",number);
                gvalue=fx(number);
                sum+=gx(gvalue);
            }
        }
        printf("\nFirst experiment key: %.2lf\n\n",sum);
        fclose(file);
        break;
        case 2:
        file=fopen("2.txt","r");
        while(fscanf(file,"%c",&temp)!=EOF){
            printf("%c",temp);
             if(temp=='#'){
                fscanf(file," %lf",&number);
                printf("%d",number);
                gvalue=fx(number);
                sum+=gx(gvalue);
            }
        }
        printf("\nSecond experiment key: %.2lf\n\n",sum);
        fclose(file);
        break;
        case 3:
        file=fopen("3.txt","r");
        while(fscanf(file,"%c",&temp)!=EOF){
            printf("%c",temp);
             if(temp=='#'){
                fscanf(file," %lf",&number);
                printf("%d",number);
                gvalue=fx(number);
                sum+=gx(gvalue);
            }
        }
        printf("\nThird experiment key: %.2lf\n\n",sum);
        fclose(file);
        break;
        case 4:
        file=fopen("4.txt","r");
        while(fscanf(file,"%c",&temp)!=EOF){
            printf("%c",temp);
             if(temp=='#'){
                fscanf(file," %lf",&number);
                printf("%d",number);
                gvalue=fx(number);
                sum+=gx(gvalue);
            }
        }
        printf("\n\nFourth experiment key: %.2lf\n\n",sum);
        fclose(file);
        break;
    }
    check();
}

void headline(int i){
    
    FILE *file;
    char temp;
    switch(i){
        case 1: file = fopen("1.txt", "r");
        do{
            fscanf(file,"%c",&temp);
            printf("%c",temp);
        }while(temp!='\n');
        break;

        case 2: file=fopen("2.txt","r");
         do{
            fscanf(file,"%c",&temp);
            printf("%c",temp);
        }while(temp!='\n');
        break;
        case 3: file=fopen("3.txt","r");
         do{
            fscanf(file,"%c",&temp);
            printf("%c",temp);
        }while(temp!='\n');
        break;
        case 4: file=fopen("4.txt","r");
         do{
            fscanf(file,"%c",&temp);
            printf("%c",temp);
        }while(temp!='\n');
        break;
    }
    fclose(file);
}

void menu2(){
    printf("*********Daily Press***********\n\n");
    printf("Today's news are listed for you\n\n");
    printf("Title of 1. news: "); headline(1);
    printf("Title of 2. news: "); headline(2);
    printf("Title of 3. news: "); headline(3);
    printf("Title of 4. news: "); headline(4);
    menu();
} 

void check(){ 
    int choice;
    printf("\nDo you want to continue? Yes(1)/No(0)\n");
    scanf(" %d",&choice);
    if(choice==1) menu();
}

int readedcontrol(int news){
    int control;
    FILE *file= fopen("readed_news_id.txt","r");
    while(fscanf(file,"%d",&control)!=EOF){
        if(control==news) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void printreadednews(){
    int temp;
    FILE *file=fopen("readed_news_id.txt","r");
    while(fscanf(file,"%d",&temp)!=EOF){
        printf("%d. news is readed\n",temp);
    }
    fclose(file);
    check();
}

void printnews(){
    
    FILE *file;
    int news, choice, choice2, control;
    char temp;
    printf("Which news do you want to read?\nPlease enter: ");
    scanf(" %d",&news);
    control = readedcontrol(news);

    if(control==1){ 
        printf("This news is readed. Do you want to read again? Yes(1)/No(0)\n");
        scanf(" %d",&choice);
        if(choice==0){
            printf("Would you like to continue reading a different news item? Yes(1)/No(0)\n");
            scanf(" %d",&choice2);
            if(choice2==1) menu();
            else {
                printf("Goodbye\n");
                return;
            }
        }
        else if(choice==1){
            if(news==1){
                file=fopen("1.txt","r");
                while(fscanf(file,"%c",&temp)!=EOF){
                    printf("%c",temp);
                }
            }
            if(news==2){
                file=fopen("2.txt","r");
                while(fscanf(file,"%c",&temp)!=EOF){
                    printf("%c",temp);
                }
            }
            if(news==3){
                file=fopen("3.txt","r");
                while(fscanf(file,"%c",&temp)!=EOF){
                    printf("%c",temp);
                }
            }
            if(news==4){
                file=fopen("4.txt","r");
                while(fscanf(file,"%c",&temp)!=EOF){
                    printf("%c",temp);
                }
            }
            fclose(file);
        }
    }
    else if(control==0){ 
        if(news==1){
            file=fopen("1.txt","r");
            while(fscanf(file,"%c",&temp)!=EOF){
                printf("%c",temp);
            }
        }
        if(news==2){
            file=fopen("2.txt","r");
            while(fscanf(file,"%c",&temp)!=EOF){
                printf("%c",temp);
            }
        }
        if(news==3){
            file=fopen("3.txt","r");
            while(fscanf(file,"%c",&temp)!=EOF){
                printf("%c",temp);
            }
        }
        if(news==4){
            file=fopen("4.txt","r");
            while(fscanf(file,"%c",&temp)!=EOF){
                printf("%c",temp);
            }
        }
        fclose(file);
        file=fopen("readed_news_id.txt","a");
        fprintf(file,"%d\n",news);
        fclose(file);
    }
    check();
}

void menu(){
    int choice;
    printf("What do you want to do?\n1.Read a new\n2.List the readed news\n3.Get decrypted information from the news\nPlease choose: ");
    scanf(" %d",&choice);
    switch(choice){
        case 1: printnews(); break;
        case 2: printreadednews(); break;
        case 3: decrypt(); break;
    }
}

int main(){
    setlocale(LC_ALL, "tr_TR.UTF-8");
    menu2();
    return 0;
}
