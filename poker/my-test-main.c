#include "cards.h"
#include"deck.h"
#include"eval.h"
#include"input.h"
#include"future.h"
#include<stdio.h>
#include<stdlib.h>

int main(void) {
    //c3prj1 testing
    
    deck_t* full_deck=malloc(sizeof(deck_t));
    full_deck->n_cards=52;
    full_deck->cards=malloc(full_deck->n_cards*sizeof(card_t*));
    for (size_t i = 0; i < full_deck->n_cards; i++)
    {
        full_deck->cards[i]=malloc(sizeof(card_t));
        *full_deck->cards[i]=card_from_num(i);
    }
    assert_full_deck(full_deck);
    printf("Full deck is.............\n");
    print_hand(full_deck);
    printf("\n");
    
    shuffle(full_deck);
    assert_full_deck(full_deck);
    printf("After shuffling.............\n");
    print_hand(full_deck);
    printf("\n");
    
    
    //c3prj2 testing
    /*
    deck_t* hand=malloc(sizeof(deck_t));
    hand->n_cards=7;
    hand->cards=malloc(hand->n_cards*sizeof(card_t*));
    for (size_t i = 0; i < hand->n_cards; i++)
    {
        hand->cards[i] =malloc(sizeof(card_t));
    }
    //0s 9s 8c 7h 6d ; Js 0c 9s 8d 7c
    //As 5c 4h 3s 2c ; 6c 5h 4s 3s 2d
    //Qh Qs Jd Js 0c 0s 9d 8c ; Kc Qh Qs Jd Js 0c 0s 9d
    //As Jd 9h 8c 7d 6c 5d ; Kc Qh 8c 7h 6c 5d 4s
    //As Kd Qs Jd 0s ; Ac 5s 4c 3s 2s
    //Jh 0s 9c 8s 7c 4c 3d ; Jh 0s 9c 8s 7c 6c 5d
    //Ac Kc Jh 9c 8s 2s
    //As 5c 4h 3s 2c
    //As Jd 9h 8c 7d 6c 5d
    //As Kd Qs Jd 0s
    //Jh 0s 9c 8s 7c 4c 3d
    *hand->cards[0]=card_from_letters('A','s');
    *hand->cards[2]=card_from_letters('J','d');
    *hand->cards[3]=card_from_letters('5','d');
    *hand->cards[1]=card_from_letters('7','d');
    *hand->cards[4]=card_from_letters('6','c');
    *hand->cards[5]=card_from_letters('8','c');
    *hand->cards[6]=card_from_letters('9','h');
    printf("Printing the hand...........\n");
    print_hand(hand);
    printf("\n");

    qsort(hand->cards,hand->n_cards,sizeof(card_t*),card_ptr_comp);
    printf("Printing the hand after sorting...........\n");
    print_hand(hand);
    printf("\n");
    
    printf("The suit flush is %d\n",flush_suit(hand));
    printf("is straight %d\n",is_straight_at(hand,2,NUM_SUITS));

    hand_eval_t ans;
    ans=build_hand_from_match(hand,5,STRAIGHT,2);

    deck_t* sol=malloc(sizeof(deck_t));
    sol->n_cards=5;
    sol->cards=malloc(sol->n_cards*sizeof(card_t*));
    for (size_t i = 0; i < sol->n_cards; i++)
    {
        sol->cards[i]=ans.cards[i];
    }
    printf("Printing the Evaluated hand...........\n");
    print_hand(sol);
    printf("\n");
    */

    //c4prj2 testing
    FILE* f=fopen("input.txt","r");
    future_cards_t *fc=malloc(sizeof(future_cards_t));
    fc->n_decks=0;
    size_t n=0;
    deck_t** test=read_input(f,&n,fc);

    printf("Hand b4 drawing.....\n");
    for (size_t i = 0; i < n; i++)
    {
        print_hand(test[i]);
        printf("\n");
    }
    
    future_cards_from_deck(full_deck,fc);

    printf("Hand after drawing.....\n");
    for (size_t i = 0; i < n; i++)
    {
        print_hand(test[i]);
        printf("\n");
    }
    
   printf("%ld\n",fc->n_decks);
   for (size_t i = 0; i < fc->n_decks; i++)
   {
       printf("%ld\n",fc->decks[i].n_cards);
   }
   

    return EXIT_SUCCESS;
}