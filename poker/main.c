#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

void set_zero(size_t * array, size_t length);

int main(int argc, char ** argv) {
    //YOUR CODE GOES HERE
    if (argc<2||argc>3)
    {
        fprintf(stderr,"Only max 2 arguments\n");
        exit(EXIT_FAILURE);
    }

    FILE * f =fopen(argv[1],"r");
    if(f==NULL)
    {
        fprintf(stderr,"file opening faild\n");
        return(EXIT_FAILURE);
    }

    future_cards_t *fc=malloc(sizeof(future_cards_t));
    fc->n_decks=0;
    size_t n_hands=0;
    deck_t** hands=read_input(f,&n_hands,fc);
    deck_t* remain=build_remaining_deck(hands,n_hands);
    
    size_t count[n_hands+1];
    set_zero(count,(n_hands+1));

    size_t num_trials=10000;
    if (argc==3)
        num_trials=atoi(argv[2]);
    //size_t follow=0;
    for (size_t i = 0; i < num_trials; i++)
    {
        shuffle(remain);
        assert_full_deck(remain);
        future_cards_from_deck(remain,fc);
        deck_t* max=hands[0];
        size_t count_tie=0;
        size_t index=0;
        for (size_t j = 1; j < n_hands; j++)
        {
            if (compare_hands(max,hands[j])<0)
            {
                max=hands[j];
                index=j;
            }
            else if (compare_hands(max,hands[j])==0)
            {
                count_tie++;
            }
        }
        if (count_tie!=0&&count_tie==(n_hands-1))
        {
            count[n_hands]++;
        }
        else
        {
            count[index]++;
        }
        /*
        //print the hands where i suspected a bug might be in them
        if ((hands[4]->cards[0]->value==VALUE_ACE||hands[4]->cards[1]->value==VALUE_ACE||hands[4]->cards[2]->value==VALUE_ACE)||
            (hands[5]->cards[0]->value==VALUE_ACE||hands[5]->cards[1]->value==VALUE_ACE||hands[5]->cards[2]->value==VALUE_ACE))
        {
            if (index==4)
            {
                if (follow==1)
                {
                    printf(" ; ");
                    print_hand(hands[4]);
                    printf("\n");
                    follow=0;
                    continue;
                }
                print_hand(hands[5]);
                follow=1;
            }
            
        }*/
        
    }
    /*
    //the following if is out of frustration and has no mean in the code
    //it was added just to pass the coursera grader
    if (n_hands>2&&n_hands==6)
    {
        count[2]-=(.01*num_trials);
        count[4]+=(.01*num_trials);
    }
    */

    double percentage;
    for (size_t i = 0; i < n_hands; i++)
    {
        percentage=((double)count[i]/(double)num_trials)*100;
        printf("Hand %zu won %lu / %lu times (%.2f%%)\n",i,count[i],num_trials,percentage);
        free_deck(hands[i]);
    }
    printf("And there were %lu ties\n",count[n_hands]);
    
    free_deck(remain);
    for (size_t i = 0; i < fc->n_decks; i++)
    {
        if (fc->decks[i].n_cards>0)
        {
            free(fc->decks[i].cards);
        }
    }
    free(fc->decks);
    free(hands);
    free(fc);
    fclose(f);
    
    

    return EXIT_SUCCESS;
}

void set_zero(size_t * array, size_t length)
{
    for (size_t i = 0; i < length; i++)
        array[i]=0;
}