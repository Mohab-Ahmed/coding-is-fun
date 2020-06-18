#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
    assert(c.value>=2&&c.value<=VALUE_ACE);
    assert(c.suit>=SPADES&&c.suit<=CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
    if (r==0) 
        return("STRAIGHT_FLUSH");

    if (r==1) 
        return("FOUR_OF_A_KIND");

    if (r==2) 
        return("FULL_HOUSE");

    if (r==3) 
        return("FLUSH");

    if (r==4) 
        return("STRAIGHT");

    if (r==5) 
        return("THREE_OF_A_KIND");

    if (r==6) 
        return("TWO_PAIR");

    if (r==7) 
        return("PAIR");
    
    return("NOTHING");  
}

char value_letter(card_t c) {
    if (c.value==10) 
        return('0');

    if (c.value==VALUE_JACK) 
        return('J');

    if (c.value==VALUE_QUEEN) 
        return('Q');

    if (c.value==VALUE_KING) 
        return('K');

    if (c.value==VALUE_ACE) 
        return('A');
    
    return('0'+c.value);
}


char suit_letter(card_t c) {
    if (c.suit==SPADES) 
        return('s');

    if (c.suit==HEARTS) 
        return('h');

    if (c.suit==DIAMONDS) 
        return('d');
 
    return('c');

}

void print_card(card_t c) {
    printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
    card_t temp;
    if (value_let=='0') 
        temp.value=10;

    else if (value_let=='J') 
        temp.value=VALUE_JACK;

    else if (value_let=='Q') 
        temp.value=VALUE_QUEEN;

    else if (value_let=='K') 
        temp.value=VALUE_KING;

    else if (value_let=='A') 
        temp.value=VALUE_ACE;
    
    else 
        temp.value=value_let-'0';

    if (suit_let=='s') 
        temp.suit=SPADES;

    else if (suit_let=='h') 
        temp.suit=HEARTS;

    else if (suit_let=='d') 
        temp.suit=DIAMONDS;
 
    else 
        temp.suit=CLUBS;
    

    assert_card_valid(temp);
    return temp;
}

card_t card_from_num(unsigned c) {
    int temp=c%13;
    card_t data;
    if (temp+2==10)
        data.value=10;

    else if (temp+2==VALUE_JACK)
        data.value=VALUE_JACK;

    else if (temp+2==VALUE_QUEEN)
        data.value=VALUE_QUEEN;

    else if (temp+2==VALUE_KING)
        data.value=VALUE_KING;

    else if (temp+2==VALUE_ACE)
        data.value=VALUE_ACE;

    else
        data.value=temp+2;


    if(c<13)
        data.suit=SPADES;

    if(c>=13&&c<26)
        data.suit=HEARTS;

    if(c>=26&&c<39)
        data.suit=DIAMONDS;

    if(c>=39&&c<52)
        data.suit=CLUBS;
        
    return(data);
}