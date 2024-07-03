#include <stdio.h>
#include <time.h>

struct Deck{
     const char *face;
     const char *suit;
};

void shuffle(struct Deck cards[52]){
    struct Deck temp;

    int i,j,a,b;
    for(i=0;i<60;i++){
      a=rand()%52;
      b=rand()%52;

      temp=cards[a];
      cards[a]=cards[b];
      cards[b]=temp;

    }
  printf("Shuffled deck:\n");
   for(i=0;i<51;i+=2){
    
      printf("%10s of %-10s",cards[i].face,cards[i].suit);
      printf("%10s of %s\n",cards[i+1].face,cards[i+1].suit);

  }

    

}

int main(){
  srand(time(NULL));
  int i,j;
  struct Deck cards[52];
  char suits[][10]={"Hearts", "Diamonds", "Clubs", "Spades"};
  for(i=0;i<52;i++){
    if(i<13) cards[i].suit=suits[0];
    else if(i<26) cards[i].suit=suits[1];
    else if(i<39) cards[i].suit=suits[2];
    else if(i<52) cards[i].suit=suits[3];
  }

   char faces[][10]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };

  for(i=0,j=0;i<52;i++,j++){
    cards[i].face=faces[j];
    if(j==12) j=0;
  }

  shuffle(cards);
}
