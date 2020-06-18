#include <stdio.h>
#include <stdlib.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr)
{
    if (fc->n_decks==0)
    {
        fc->n_decks++;
        fc->decks=malloc(fc->n_decks*sizeof(deck_t));
        fc->decks[0].n_cards=0;
    }
    
    if (fc->n_decks<=index)
    {
        fc->decks=realloc(fc->decks,(index+1)*sizeof(deck_t));
        if (index+1-fc->n_decks>1)
        {
            for (size_t i = fc->n_decks; i < index; i++)
            {
                fc->decks[i].n_cards=0;
            }
            
        }
        
        fc->decks[index].n_cards=0;
        fc->n_decks=index+1;
    }
    
    if (fc->decks[index].n_cards==0)
    {
       fc->decks[index].cards=malloc(sizeof(card_t*)); 
    }
    fc->decks[index].n_cards++;
    fc->decks[index].cards=realloc(fc->decks[index].cards,(fc->decks[index].n_cards)*sizeof(card_t*));
    fc->decks[index].cards[fc->decks[index].n_cards-1]=ptr;
    
    
    

}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc)
{
    for (size_t i = 0; i < fc->n_decks; i++)
    {
        if (fc->decks[i].n_cards>0)
        {
            for (size_t j = 0; j < fc->decks[i].n_cards; j++)
            {
                fc->decks[i].cards[j]->value=deck->cards[i]->value;
                fc->decks[i].cards[j]->suit=deck->cards[i]->suit;
            }
            
        }
        
    }
    
}
