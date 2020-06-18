#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for (size_t i = 0; i < hand->n_cards; i++)
  {
    print_card(*hand->cards[i]);
    printf(" ");
  }
  
}

int deck_contains(deck_t * d, card_t c) {
  for (size_t i = 0; i < d->n_cards; i++)
  {
    if (d->cards[i]->value==c.value&&d->cards[i]->suit==c.suit)
    {
      return 1;
    }
    
  }
  
  return 0;
}

void shuffle(deck_t * d){
  int random;
  card_t* temp;
  for (size_t i = 0; i < d->n_cards; i++)
  {
    random=rand()%(d->n_cards-1);
    temp=d->cards[i];
    d->cards[i]=d->cards[random];
    d->cards[random]=temp;
  }
  
}

void assert_full_deck(deck_t * d) {
  int check;
  for (size_t i = 0; i < d->n_cards; i++)
  {
    assert_card_valid(*d->cards[i]);
    if ((check=deck_contains(d,*d->cards[i]))==0)
    {
      fprintf(stderr,"Error in contain card %ld\n",i);
      assert(check==1);
    }
    else if ((check=count_repeat(d,*d->cards[i]))!=1)
    {
      fprintf(stderr,"Error in count card %ld\n",i);
      assert(check==1);
    }
  }
  
}

int count_repeat(deck_t * d, card_t c) 
{
  int count=0;
  for (size_t i = 0; i < d->n_cards; i++)
  {
    if (d->cards[i]->value==c.value&&d->cards[i]->suit==c.suit)
    {
      count++;
    }
    
  }
  
  return count;
}

void add_card_to(deck_t * deck, card_t c)
{
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(card_t*));
  deck->cards[deck->n_cards]=malloc(sizeof(card_t));
  deck->cards[deck->n_cards]->value=c.value;
  deck->cards[deck->n_cards]->suit=c.suit;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck)
{
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(card_t*));
  deck->cards[deck->n_cards]=malloc(sizeof(card_t));
  deck->cards[deck->n_cards]->value=0;
  deck->cards[deck->n_cards]->suit=0;
  deck->n_cards++;
  return(deck->cards[deck->n_cards-1]);
}

deck_t * make_deck_exclude(deck_t * excluded_cards)
{
  deck_t* full_deck=malloc(sizeof(deck_t));
  full_deck->n_cards=0;
  full_deck->cards=malloc(sizeof(card_t*));
  card_t temp;
  for (size_t i = 0; i < 52; i++)
  {
    temp=card_from_num(i);
    if (deck_contains(excluded_cards,temp)==0)
      add_card_to(full_deck,temp);
  }
  
  return(full_deck);
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{
  deck_t* temp=malloc(sizeof(deck_t));
  temp->n_cards=0;
  temp->cards=malloc(sizeof(card_t*));
  for (size_t i = 0; i < n_hands; i++)
  {
    for (size_t j = 0; j < hands[i]->n_cards; j++)
    {
      add_card_to(temp,*hands[i]->cards[j]);
    }
  }
  deck_t* ans=make_deck_exclude(temp);
  free_deck(temp);

  return(ans);
}

void free_deck(deck_t * deck) 
{
  for (size_t i = 0; i < deck->n_cards; i++)
  {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}