#include <stdio.h>

int  find_size_of_array(int arr[]){
    int i=0;
    while(arr[i]!=-1){
        i++;
    }
    return i; 
}

int max(int frequency[], int n){
    int maks=0, i;
    for(i=0; i<n; i++){
        if(frequency[i]>=maks) maks=frequency[i];
    }
    return maks;   
}

void print(int frequency[], int a, int k){/*k alt satır zamanını(eleman sayısı=k), a toplam satır sayısını belirler*/
    int i, j;  /*a en çok tekrar eden sayıdır*/
    int a2=a; /*for döngüsünde kullanılan a değeri değişmemeli, bu yüzden a yı kopyaladım*/
    printf("\n");
    for(j=0; j<a; j++){
        for(i=0; i<k; i++){
            if(frequency[i]>=a2) printf("*");
            else printf(" ");
        }
        a2--;
        printf("\n");
    }
}

void mod(int number_array[],int arr[]){

    int boyut=find_size_of_array(arr); 
    int boyut2=find_size_of_array(number_array);
    int counter,k=0,m=0,j;
    int frequency[boyut]; /*verilen arrayde her bir elemanın kaç defa tekrarladığını kaydeden array*/
    int i;
    for(i=0;i<boyut;i++){
        counter=0;
        for(j=0;j<boyut2;j++){
            if(arr[i]==number_array[j]) counter++;
        }
        frequency[k]=counter;
        k++;
    }

    int maxtekrar=max(frequency,k);
    printf("Mods: ");
    for(i=0;i<boyut;i++){
       if(frequency[i]==maxtekrar) printf("%d ",arr[i]);
    } 
    printf("\n");

}

void median(int number_array[],int a,int b){
    int n=find_size_of_array(number_array);
    int new_array[151];
    int i,j,k=0,temp;
    double sum;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(number_array[i]<number_array[j]){
                temp=number_array[i];
                number_array[i]=number_array[j];
                number_array[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++){
        if(number_array[i]>=a && number_array[i]<=b){ /*Sayi istenen aralıktaysa bunu yeni arraye aktar*/
            new_array[k]=number_array[i];
            k++;
        }
    }

    if(k%2==0){
        sum=(new_array[(k-2)/2]+new_array[((k-2)/2)+1])/2.0;
    }
    else{
        sum=new_array[(k-1)/2];
        
    }
    printf("Median: %.2f\n",sum);
}

void compare(int arr[], int number_array[]){
    int boyut=find_size_of_array(arr); 
    int boyut2=find_size_of_array(number_array);
    int counter, k=0,j;
    int frequency[boyut]; /*verilen arrayde her bir elemanın kaç defa tekrarladığını kaydeden array*/
    int i;
    for(i=0; i<boyut; i++){
        counter=0;
        for(j=0; j<boyut2; j++){
            if(arr[i]==number_array[j]) counter++;
        }
        frequency[k]=counter;
        k++;
    }
    int maxtekrar=max(frequency, k); /*son eleman (k-1.)indexte*/
    print(frequency, maxtekrar, k);
}

void part2(int number_array[]){
    int n=find_size_of_array(number_array);
    int k=0,temp;
    printf("Enter additional values:\n");
    while(k<5){
        scanf(" %d",&temp);
        if(temp==-1) break;
        number_array[n]=temp;
        n++;
        k++;
    } 
    number_array[n]=-1;  
}

double mean(int number_array[], int boyut,int a, int b){
    int i,n=0;
    double sum=0.0;
    for(i=0; i<boyut; i++){
        if(number_array[i]>=a && number_array[i]<=b){
        sum+=number_array[i];
        n++;
        }
    }
    return sum/(n);
}


int main() {
    int a, b, i, j=0, choice;
    int arr[151];
    double ort;
    int number_array[] = {3, 8, 9, 9, 5, 2, 4, 7, 4, 8, 9, 10, 2, 4, 5, -1}; 
 
    do{
        printf("Enter A value: ");
        scanf(" %d", &a);
        if(a<50) printf("A must be 50 minimum!\n");
    }while(a<50);

    do{
        printf("Enter B value: ");
        scanf(" %d", &b);
        if(b>200) printf("B must be 200 maximum!\n");
    }while(b>200);

    for (i= a; i<= b; i++) {
        arr[j] = i;
        j++;
    }
    arr[j]=-1;
    compare(arr, number_array);
    int boyut=find_size_of_array(number_array);
    printf("Would you like to add new numbers? Yes(1)/No(0): ");
    scanf(" %d", &choice);
    if (choice == 1)
    {

        int number_array_2[boyut + 10];

        for (i = 0; i <= boyut; i++)
        {
            number_array_2[i] = number_array[i]; /*Arraye yeni sayılar eklenirken olası hataları önlemek için yeni sayılar aynı arrayin kopyasına alınır*/
        }

        part2(number_array_2);
        boyut = find_size_of_array(number_array_2);
        compare(arr, number_array_2);
        ort = mean(number_array_2, boyut,a,b);
        printf("Average: %.2lf\n", ort);
        mod(number_array_2, arr);
        median(number_array_2,a,b);
    }
    if (choice == 0)
    {
        ort = mean(number_array, boyut,a,b);
        printf("Average: %.2lf\n", ort);
        mod(number_array, arr);
        median(number_array,a,b);
    }    
    
    return 0;
}
