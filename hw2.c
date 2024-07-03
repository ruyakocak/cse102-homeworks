#include <stdio.h>
int main(){
	int x,y,z;
	int xmax=0,xmax1=0;
	int ymax=0,ymax1=0;
	int xmin=100,xmin1=100;
	int ymin=100,ymin1=100;
	int xfinal, yfinal;
	int bestr1, bestr2, bestr3, bestr4;

	int choice;
	printf("Menu:\n 1.Explore Data\n 2.Train Model\n 3.Test Model\n 4.Exit\n");
	do{

	printf("Please choose from the menu\n");
	scanf("%d",&choice);

	if(choice==1){
	
	FILE *data= fopen("data.txt","r");
	 if (data == NULL) {
        printf("Error opening file\n");
        return 1;
    }
	while(fscanf(data, "%d %d %d",&x,&y,&z)==3){

		if(z==0){
			if(x>xmax){
				
				xmax=x;
			}
	
			if(x<xmin){
				
				xmin=x;
			}
	
			if(y>ymax){
				
				ymax=y;
			}
	
			 if(y<ymin){
				
				ymin=y;
			}
		}
		if(z==1){
			if(x>xmax1){
				
				xmax1=x;
			}

			if(x<xmin1){
				
				xmin1=x;
			}
	
			if(y>ymax1){
			
				ymax1=y;
			}
	
			 if(y<ymin1){
			
				ymin1=y;
	
		}
		}

		}
	

	

fclose(data);
	
	printf("Minimum and maximum x and y values:\n");
	printf("Class 0: X in [%d,%d], Y in [%d,%d]\n",xmin,xmax,ymin,ymax);
	printf("Class 1: X in [%d,%d], Y in [%d,%d]\n",xmin1,xmax1,ymin1,ymax1);
	
	}
else if(choice==2){
		FILE *data= fopen("data.txt","r"); 
	 if (data == NULL) {
        printf("Error opening file\n");
        return 1;
    }
	
	
	int xsep=0;
	int ysep=0;
	int r1,r2,r3,r4;
	int toplamhata=0;
	int all=0;
	int hata1,hata2,hata3,hata4;
	int minhata=1000;
	int r10,r20,r30,r40; /* classın 0 geldiği sayılar */
	int r11,r21,r31,r41; /* 1 geldiği sayılar */

	while(xsep<xmax){
		 r10 = r11 = r20 = r21 = r30 = r31 = r40 = r41 = 0;
		
		while(ysep<ymax){
			 r10 = r11 = r20 = r21 = r30 = r31 = r40 = r41 = 0;
			
		while(fscanf(data, "%d %d %d",&x,&y,&z)==3){
			
			
		if(x<=xsep && y>ysep){ /* R1 */
			if(z==0) r10++;
			else r11++;
		}
		else if(x>xsep && y>ysep){ /* R2 */
			if(z==0) r20++;
			else r21++;
		}
		else if(x<=xsep && y<=ysep){ /* R3 */
			if(z==0) r30++;
			else r31++;
		}
		else if(x>xsep && y<=ysep) { /* R4 */
			if(z==0) r40++;
			else r41++;
		}


	}
	if(r10>r11) {
		r1=0;
		hata1=r11;
	}
	else {
		r1=1;
		hata1=r10;	
	}

	if(r20>r21) {
		r2=0;
		hata2=r21;
	}
	else {
		r2=1;
		hata2=r20;	
	}
	if(r30>r31) {
		r3=0;
		hata3=r31;
	}
	else {
		r3=1;
		hata3=r30;	
	}
	if(r40>r41) {
		r4=0;
		hata4=r41;
	}
	else {
		r4=1;
		hata4=r40;	
	}
	toplamhata= hata1+hata2+hata3+hata4;
	if(toplamhata<minhata){
		minhata=toplamhata;
		xfinal=xsep;
		yfinal=ysep;
		bestr1=r1;
		bestr2=r2;
		bestr3=r3;
		bestr4=r4;


	} 
		ysep++;
		rewind(data); /*dosyanın başına dön*/
		}
		
		ysep=0; /*her seferinde ysep değerini sıfırla*/
		xsep++;
		
		rewind(data);
	}
	

	


	printf("Seperator coordinates: X=%d, Y=%d\n",xfinal,yfinal);
	printf("Training error of the model %d\n",minhata);
	printf("Labels of the regions: R1=%d, R2=%d, R3=%d, R4=%d\n",bestr1,bestr2,bestr3,bestr4);
	fclose(data); 
}	
	

 else if(choice==3){

	
	FILE *data= fopen("test 1.txt","r");
	 if (data == NULL) {
        printf("Error opening file\n");
        return 1;
    }
	
	int yanlis=0;
	int all=0;
	
		while(fscanf(data, "%d %d %d",&x,&y,&z)==3){
			

		if(x<=xfinal && y>yfinal){ /* R1 */
			
			if(z!=bestr1) {
				yanlis++;
			}

		}
		else if(x>xfinal && y>yfinal){ /* R2 */
			
			if(z!=bestr2) {
				yanlis++;
			}
	
		}
		else if(x<=xfinal && y<=yfinal){ /* R3 */
			
			if(z!=bestr3) {
				yanlis++;
			}
		
		}
		else if(x>xfinal && y<=yfinal) { /* R4 */
			
			if(z!=bestr4) {
				yanlis++;
			}
			
		}
		all++;
		


	}
	
	
	
	fclose(data);
	printf("Predicted classes for test-final.txt file\n");
	FILE *data2= fopen("test-final.txt","r");
	 if (data2 == NULL) {
        printf("Error opening file\n");
        return 1;
    }

	while(fscanf(data2, "%d %d",&x,&y)==2){
		if(x<=xfinal && y>yfinal){ /* R1 */
			printf("%d %d %d\n",x,y,bestr1);
			

		}
		else if(x>xfinal && y>yfinal){ /* R2 */
			printf("%d %d %d\n",x,y,bestr2);
		
	
		}
		else if(x<=xfinal && y<=yfinal){ /* R3 */
			printf("%d %d %d\n",x,y,bestr3);
		
		
		}
		else if(x>xfinal && y<=yfinal) { /* R4 */
			printf("%d %d %d\n",x,y,bestr4);
			
			
		}
	
		

 }
 printf("Success: %d%%\n",((100*(all-yanlis))/all));
 fclose(data2);

 }
 else if(choice<1 || choice>4) printf("Please enter a valid number\n");

}while(choice!=4);
printf("The program is terminated\n");
 return 0;
}
