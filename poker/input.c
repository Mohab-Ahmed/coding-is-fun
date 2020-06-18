#include <stdio.h>
#include <stdlib.h>
#include "input.h"
__ssize_t getline(char **lineptr, size_t *n, FILE *stream);
deck_t * hand_from_string(const char * str, future_cards_t * fc)
{
    deck_t* hand=malloc(sizeof(deck_t));
    hand->n_cards=0;
    hand->cards=malloc(sizeof(card_t*));
    card_t hold;
    size_t temp=0;
    for (size_t i = 0; str[i] != '\n'; i++)
    {
        if (str[i]=='\0')
            break;

        if (str[i]==' ')
            continue;
        
        if (str[i]=='?')
        {
            i++;
            if (is_a_number(str[i+1]))
            {
                temp=str[i]-'0';
                temp*=10;
                i++;
                temp+=(str[i]-'0');
            }
            else
                temp=str[i]-'0';
            
            add_future_card(fc,temp,add_empty_card(hand));
            continue;
        }
        hold=card_from_letters(str[i],str[i+1]);
        i++;
        add_card_to(hand,hold);
       
    }

    return(hand);
}

size_t is_a_number(char num)
{
    if((num>='0'&&num<='9'))
        return(1);

    return(0);
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc)
{
    deck_t** ans=malloc(sizeof(deck_t*));
    size_t count=0;
    fc->n_decks=0;
    char *temp=NULL;
    size_t size=0;
    while (getline(&temp,&size,f)>0)
    {
        count++;
        ans=realloc(ans,(count)*sizeof(deck_t*));
        ans[count-1]=hand_from_string(temp,fc);
        if (ans[count-1]->n_cards<5)
        {
            fprintf(stderr,"Hand %ld isn't 5 cards\n",count);
            exit(EXIT_FAILURE);
        }
    }
    
    free(temp);
    *n_hands=count;
    return(ans);
}
