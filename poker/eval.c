#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"cards.h"

int card_ptr_comp(const void * vp1, const void * vp2) {
    const card_t * const * cp1=vp1;   
    const card_t * const * cp2=vp2;
    if (cp1[0]->value==cp2[0]->value)
    {
        if (cp1[0]->suit>cp2[0]->suit)
            return(-1);
        else if (cp1[0]->suit<cp2[0]->suit)
            return(1);
    }
    else if (cp1[0]->value>cp2[0]->value)
        return(-1);
    else if (cp1[0]->value<cp2[0]->value)
        return(1);

  return 0;
}

suit_t flush_suit(deck_t * hand) {
    suit_t suit[NUM_SUITS];
    suit[0]=SPADES;
    suit[1]=HEARTS;
    suit[2]=DIAMONDS;
    suit[3]=CLUBS;
    int count[4]={0};
    for (size_t i = 0; i < hand->n_cards; i++)
    {
        for (size_t j = 0; j < NUM_SUITS; j++)
        {
            if (hand->cards[i]->suit==suit[j])
            {
                count[j]++;
                break;
            }
        }
    }
    for (size_t i = 0; i < NUM_SUITS; i++)
    {
        if (count[i]>=5)
            return(suit[i]);        
    }
    
  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {
    if (n==0)
        return 0;
    
    unsigned max=arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i]>max)
            max=arr[i]; 
    }
    
  return max;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
    for (size_t i = 0; i < n; i++)
    {
      if (match_counts[i]==n_of_akind)
        return(i);   
    }
    
    fprintf(stderr,"Error in n_of_a_kind\n");
    exit(EXIT_FAILURE);
}
ssize_t  find_secondary_pair(deck_t * hand,
                             unsigned * match_counts,
                             size_t match_idx) {
  for (ssize_t i = 0; i < hand->n_cards; i++)
  {
    if (match_counts[i]>1)
    {
      if (hand->cards[i]->value!=hand->cards[match_idx]->value)
        return(i);
    }  
  }
  
  return -1;
}

int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  int check=0;
  suit_t suit=fs;
  //if (hand->cards[index]->suit!=fs)
    //suit=NUM_SUITS;
  if (fs==NUM_SUITS)
    suit=hand->cards[index]->suit;

  if (hand->cards[index]->suit!=suit)
    return(0);
  
  if (hand->cards[index]->value==VALUE_ACE&&hand->cards[index]->suit==suit)
  {
    size_t size=hand->n_cards-index-1;
    card_t temp[size];
    for (size_t i = 0; i <size; i++)
    {
      temp[i].value=hand->cards[index+i+1]->value;
      temp[i].suit=hand->cards[index+i+1]->suit;
    }
    check=is_ACE_low_at(temp,size,fs);
  }

  int count=1;
  unsigned int max=hand->cards[index]->value;
  for (size_t i = index+1; i < hand->n_cards; i++)
  {
    if (fs==NUM_SUITS)
      suit=hand->cards[i]->suit;
    
    if (hand->cards[i]->value!=max&&hand->cards[i]->suit==suit)
    {
      if (hand->cards[i]->value==(max-1)&&hand->cards[i]->suit==suit)
      {
        count++;
        max--;
      }
      else
      {
        break;
      }
      if (count==5)
        return(1);
    }
    
  }
  
  
  return check;
}

int is_ACE_low_at(card_t * hand, size_t size, suit_t fs) {
  size_t guide=0;
  while (hand[guide].value!=5)
  {
    guide++;
    if (guide==size)
    {
      return(0);
    } 
  }
  
  int count=1;
  unsigned int max=hand[guide].value;
  suit_t suit=fs;
  for (size_t i = guide; i < size; i++)
  {
    if (fs==NUM_SUITS)
      suit=hand[i].suit;
    if (hand[guide].suit!=suit)
    {
      return(0);
    }
    
    if (hand[i].value!=max&&hand[i].suit==suit)
    {
      if (hand[i].value==(max-1)&&hand[i].suit==suit)
      {
        count++;
        max--;
      }
      else
      {
        break;
      }
      if (count==4)
        return(-1);
    }
    
  }
  
  return 0;
}

hand_eval_t build_hand_from_match(deck_t * hand,
                                  unsigned n,
                                  hand_ranking_t what,
                                  size_t idx) {
  hand_eval_t ans;
  ans.ranking=what;
  size_t i=0;
  for ( i = 0; i < n; i++)
  {
    ans.cards[i]=hand->cards[idx+i];
  }
  if (i==5)
    return ans;
  for (size_t j = 0; j < hand->n_cards; j++)
  {
    if (j==idx&&n!=0)
    {
      j+=(n-1);
    }
    else
    {
      ans.cards[i]=hand->cards[j];
      i++;
    }

    if (i==5)
      break;
  }
    
  return ans;
}

int compare_value(unsigned v1,unsigned v2)
{
  return(v1-v2);
}

int compare_hands(deck_t * hand1, deck_t * hand2) {
  qsort(hand1->cards,hand1->n_cards,sizeof(card_t*),card_ptr_comp);
  qsort(hand2->cards,hand2->n_cards,sizeof(card_t*),card_ptr_comp);
  /*print_hand(hand1);
  printf("\t");
  print_hand(hand2);
  printf("\n");*/
  hand_eval_t h1=evaluate_hand(hand1);
  hand_eval_t h2=evaluate_hand(hand2);
  if (h1.ranking==h2.ranking)
  {
    int check;
    for (size_t i = 0; i < 5; i++)
    {
      check=compare_value(h1.cards[i]->value,h2.cards[i]->value);
      if (check!=0)
        return(check);
    }
  }
  else
  {
    return(h2.ranking-h1.ranking);
  }

  return 0;
}



//You will write this function in Course 4.                                                       
//For now, we leave a prototype (and provide our                                                  
//implementation in eval-c4.o) so that the                                                        
//other functions we have provided can make                                                       
//use of get_match_counts.                                                                        
unsigned * get_match_counts(deck_t * hand) 
{
  unsigned* array=malloc(hand->n_cards *sizeof(unsigned));
  for (size_t i = 0; i < hand->n_cards; i++)
  {
    array[i]=match_count(hand,*hand->cards[i]);
  }
  
  return(array);
}

int match_count(deck_t * d, card_t c) 
{
  int count=0;
  for (size_t i = 0; i < d->n_cards; i++)
  {
    if (d->cards[i]->value==c.value)
    {
      count++;
    }
    
  }
  
  return count;
}

// We provide the below functions.  You do NOT need to modify them                                
// In fact, you should not modify them!                                                           


//This function copies a straight starting at index "ind" from deck "from".                       
//This copies "count" cards (typically 5).                                                        
//into the card array "to"                                                                        
//if "fs" is NUM_SUITS, then suits are ignored.                                                   
//if "fs" is any other value, a straight flush (of that suit) is copied.                          
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
        (fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)                          
// in "hand".  It calls the student's is_straight_at for each possible                            
// index to do the work of detecting the straight.                                                
// If one is found, copy_straight is used to copy the cards into                                  
// "ans".                                                                                         
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight                                                             
        //assert(hand->cards[i]->value == VALUE_ACE &&
               //(fs == NUM_SUITS || hand->cards[i]->suit == fs));
        ans->cards[4] = hand->cards[i];
        size_t cpind = i+1;
        while(hand->cards[cpind]->value != 5 ||
              !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
          cpind++;
          assert(cpind < hand->n_cards);
        }
        copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
        copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.                                      
//This function is longer than we generally like to make functions,                               
//and is thus not so great for readability :(                                                     
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind                                                           
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house                            
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush                                                              
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
        ans.cards[copy_idx] = hand->cards[i];
        copy_idx++;
        if (copy_idx >=5){
          break;
        }
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight                                   
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind                                                      
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair                                                   
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01                      
      //if other_pair_idx > 2, then, e.g. A A K Q Q                                               
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q                                                                
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}