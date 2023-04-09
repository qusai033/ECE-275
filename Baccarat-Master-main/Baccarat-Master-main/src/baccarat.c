//
// Created by Qusai Almustafa on 2/1/22.
//

#include "baccarat.h"

void start_baccarat(baccarat_game_t* barcg, unsigned int numdeck){ //maybe the numdeck
    //(*barcg).num_decks = numdeck;
    barcg->num_decks = numdeck;
    (*barcg).deck = make_card_deck(numdeck); // function takes # of decks as argument and returnd card_deck_t*
    shuffle_card_deck(barcg->deck, (*barcg).num_decks);

    (*barcg).num_dealer_cards = 0;
    (*barcg).num_player_cards = 0;
    (*barcg).player_score = 0;
    (*barcg).dealer_score = 0;
}

void deal_init_baccarat(baccarat_game_t* barcg){
// Will give each player two cards
    int i = 0;
    while (i < 2){
        (*barcg).player_cards[i] = draw_card((*barcg).deck, (*barcg).num_decks);
        //(*barcg).num_player_cards = (*barcg).num_player_cards + 1;
        i++;
    }
    (*barcg).num_player_cards = 2;

    i = 0;
    while (i < 2) {
        (*barcg).dealer_cards[i] = draw_card((*barcg).deck, (*barcg).num_decks);
        //(*barcg).num_dealer_cards = (*barcg).num_dealer_cards + 1;
        i++;
    }

/*    for (int i = 0; i != 2; ++i) {
      (*barcg).dealer_cards[i] = draw_card((*barcg).deck, (*barcg).num_decks);
      }*/
    barcg->num_dealer_cards = 2;
}

void deal_finalize_baccarat(baccarat_game_t* barcg){

    //player
    if (deal_player_third_card (barcg)){
        (*barcg).num_player_cards += 1;
        (*barcg).player_cards[2] = draw_card((*barcg).deck, (*barcg).num_decks);
    }
    else if (deal_dealer_third_card(barcg)){
        (*barcg).num_dealer_cards += 1;
        (*barcg).dealer_cards[2] = draw_card((*barcg).deck, (*barcg).num_decks);
    }
}

bool deal_player_third_card(baccarat_game_t* barcg){
(*barcg).player_score = score_baccarat_hand((*barcg).player_cards, (*barcg).num_player_cards);
(*barcg).dealer_score = score_baccarat_hand((*barcg).dealer_cards, (*barcg).num_dealer_cards);
    //unsigned int third = score_baccarat_rank((*barcg).player_cards[2].rank);

    if (((*barcg).player_score == 8) || ((*barcg).player_score == 9)){
        return false;
        // also do this for the dealer's score. here though we can assume (correctly) that the dealer only has 2 cards
    }
    else if (((*barcg).dealer_score == 8) || ((*barcg).dealer_score == 9)){
        return false;
    }
    else if (((*barcg).player_score >= 0) && ((*barcg).player_score <= 5)){
        return true;
    }
    else if (((*barcg).player_score == 6) || ((*barcg).player_score == 7)){
        return false;
    }
    else {
    return false;
    }
    //check on the player cards
    //chack on the player score before deting thired card
}

bool deal_dealer_third_card(baccarat_game_t* barcg){
    (*barcg).dealer_score = score_baccarat_hand((*barcg).dealer_cards, (*barcg).num_dealer_cards);
    unsigned int third = score_baccarat_rank((*barcg).player_cards[2].rank);


    if (((*barcg).dealer_score == 8) || ((*barcg).dealer_score == 9)){
            return false;
        // May also want to check if the player had a score of 8 or 9 in the first two cards
        // if player_score is 8 or 9 we also need to check that num_player_cards is 2 and not 3
    }
    else if ((*barcg).dealer_score == 7){
        return false;
    }
    else if ((*barcg).dealer_score == 6) {
        if ((third == 6) || (third == 7)) {
            return true;
        }
        return false;
    }
    else if ((*barcg).dealer_score == 5) {
        if ((third >= 4 ) || (third <= 7)) {
            return true;
        }
        return false;
    }
    else if ((*barcg).dealer_score == 4) {
        if ((third >= 2 ) || (third <= 7)){
        }
        return false;
    }
    else if ((*barcg).dealer_score == 3) {
        if ((third <= 9) || (third != 8)) {
            return true;
        }
        return false;
    }
    else {
        return true; // maybe this should be false?
    }
}

baccarat_outcome_t get_baccarat_outcome(const baccarat_game_t* barcg){
    if (barcg->player_score > barcg->dealer_score) {
        return player_win;
    }
    else if (barcg->dealer_score > barcg->player_score) {
        return dealer_win;
    }
    else {//if (barcg->player_score == barcg->dealer_score){ // The compiler doesn't realize that you've enumerated the only possible outcomes for these numerical values
        return tie;
    }
}
 
unsigned int score_baccarat_rank(card_rank_t hand){
    //return the value of one card
    unsigned int score = 0;
    switch (hand) {
        case Ace:
            score = 1;
            break;
        case King:
        case Queen:
        case Jack:
        case Ten:
            score = 0;
            break;
        case Nine:
            score = 9;
            break;
        case Eight:
            score = 8;
            break;
        case Seven:
            score = 7;
            break;
        case Six:
            score = 6;
            break;
        case Five:
            score = 5;
            break;
        case Four:
            score = 4;
            break;
        case Three:
            score = 3;
            break;
        case Two:
            score = 2;
            break;
        default: score = 0; break; // this may not be the "best" but it gets the job done for the compiler errors
    }
    return score;
}

// You can add the [const] if you like to say the each element of the array is const
unsigned int score_baccarat_hand(const card_t n[const], unsigned int barcg){
    unsigned int results = 10;
    for (unsigned int q = 0; q < barcg; q++){
        results = results + score_baccarat_rank(n[q].rank);
        if (results > 9){
            results -= 10; // results = results = 10;
        }
    }
    return results;
}
