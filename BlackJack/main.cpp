/* 
 * File:   main.cpp
 * Author: Marcus Burton   
 * Created on November 3rd 2017       
 * Purpose:  Virtual blackjack!       
 */

#include <fstream>      //Write to File
#include <iostream>     //Input/Output Stream Library
#include <cstdlib> //for rand and srand
#include <ctime> //for the time function   //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void result(int tot, int dtot, int bet);
//Execution Begins Here!
int main(int argc, char** argv) {
   unsigned seed = time(0); // for the random number
    srand(seed); 
    
    bool dealer = rand() & 1; // generate random choice for dealer to hit or not past 14
    int player; // variable for the player
    int comp; // variable for the dealer
    int hit, card1, card2,total,dealc1,dealc2; //variables for cards nad hits and total
    char hitme,dubdown; // variables to get a hit and to double down
    int bet; // initial bet
    //Initialize Variables
    player=0; // start the values with zeroes
    comp=0;
    hit=(rand() % (11 - 1)) + 1; // generates a number between 1 and 10
    card1=(rand() % (11 - 1)) + 1;
    card2=(rand() % (11 - 1)) + 1;
    dealc1=(rand() % (11 - 1)) + 1;
    dealc2=(rand() % (11 - 1)) + 1;
    int tot=card1+card2; // inital cards for player
    int dtot=dealc1+dealc2; // initial card for dealer
    const string victory = "Player wins! at ";
    const string dvict = "Dealer wins! at"; // create strings for victory or defeat messages to make things easier
    
    cout<<"How much would you like to bet?"<<endl; // ask user for bet
    cin>>bet;
    cout<<"You have bet a total of $"<<bet<<endl;
    cout<<"Your cards are such"<<endl;
    cout<<card1<<" and "<<card2<<", totaling "<<tot<<endl;// hand out the cards to the player and add them up
    
    cout<<"Would you like another card?"<<endl; // ask player for another card
    cout<<"Type Y for a hit, and N for no hit"<<endl; // any character but N would work
    cin>>hitme;
    // loop playing every time the player asks for a new card
    while(hitme=='Y') //only give a hit when the player hits Y
    {
            // adding new hit
            int newc=(rand()%(11-1))+1;
            cout<<"You get a "<<newc<<endl;
            tot+=newc;
            // showing total
            cout<<"total is "<<tot<<endl;
            
            if(tot>21) // if over 21, player automatically loses
            {
             cout<<"Dealer wins by default!!"<<endl;
             cout<<"I'm afraid you lose your clever bets of $"<<bet<<endl;
             result(tot,dtot,bet);
             return 0; // end program
            }
            
            
            
        // add another hit question
            
        cout<<"Another card?"<<endl;
        cin>>hitme;
            
                
        
    }
    // offering the player a double down
    cout<<"Would you like to double down? You are at "<<tot<<endl;
    cin>>dubdown;
    cout<<endl;
    if(dubdown=='Y')
    {
        bet*=2; // if yes, updating their bet amount
        cout<<"Your bet is now "<<bet<<endl;
        
    }
    else // if not, bet stays the same
        cout<<"Your bet remains at "<<endl;
    cout<<endl;
    
    // dealer begins to show cards
    cout<<"Dealer gets a "<<dealc1<<" and a "<<dealc2<<endl;
    cout<<"Dealer is at "<<dtot<<endl;
    cout<<endl;
    if(dtot<15) // dealer ALWAYS hits at less than 15(general casino rules)
    {
        do // perform the following only if the dealer is less than 15
    {
        int newc=(rand()%(11-1))+1; // new card variable initialized
        cout<<"Dealer gets a "<<newc<<endl;
        dtot+=newc; //adding new value
        cout<<"Dealer's total is "<<dtot<<endl;
        if(dtot>21) // dealer automatically loses at bust
        {   
            cout<<victory<<tot<<endl; // standard victory message along with the total
            if(tot==21) // only display if the player is at 21 for 3:2 odds
            {
            cout<<"Your intelligent betting today has won you a handsome prize"<<endl;
            bet = bet/2*3; // 21 wins a 2:3 ratio
            cout<<"You have earned $"<<bet<<" at a 3:2 ratio due to getting 21!"<<
                    "congratulations!"<<endl;
            result(tot,dtot,bet);
            }
            else{
            bet=bet*2;
            cout<<"Your intelligent betting has won you $"<<bet<<endl;
            result(tot,dtot,bet);
        }
        
            return 0; // end program as dealer would have lost
        }
        
    }  
    while(dtot<=14); // only continue do loop if dtot<=14
    }
    
     if(dtot>14 && dealer) // dealer may or may not hit above 15, leave it up to random true or false
    {
        do // perform the following only if the dealer is less than 15
    {
        int newc=(rand()%(11-1))+1;
        cout<<"Dealer gets a "<<newc<<endl;
        dtot+=newc; //adding new value
        cout<<"Dealer's total is "<<dtot<<endl;
        if(dtot>21) // dealer automatically loses at bust
        {
            
            cout<<victory<<tot<<endl;
            if(tot==21)
            {
            cout<<"Your intelligent betting today has won you a handsome prize"<<endl;
            bet = bet/2*3;
            cout<<"You have earned $"<<bet<<" at a 3:2 ratio due to getting 21!"<<
                    "congratulations!"<<endl;
            result(tot,dtot,bet);
            }
            else{
            bet=bet*2;
            cout<<"Your intelligent betting has won you $"<<bet<<endl;
            result(tot,dtot,bet);
        }
        
            return 0;
        }  
    }
    //50/50 odds for dealer to hig
    while(dtot<=18 && dealer); // don't want the dealer randomly hitting on a high value so I close 18 for the high point. boolean decides randomly if dealer will take the odds
    }
    cout<<"Dealer stays at "<<dtot<<endl;
    // final score, player only wins if tot>dtot
    if(tot>dtot)
    {
        cout<<victory<<tot<<endl;
        if(tot==21) // only run following if the player is at 
        {
            cout<<"Your intelligent betting today has won you a handsome prize"<<endl;
            bet = bet/2*3;
            cout<<"You have earned $"<<bet<<" at a 3:2 ratio due to getting 21!"<<
                    "congratulations!"<<endl;
            result(tot,dtot,bet);
           
        }else{
            bet=bet*2;
            cout<<"Your intelligent betting has won you $"<<bet<<endl;
       }
              
    }
    else if(dtot>tot)
    {
        cout<<dvict<<dtot<<endl;
        cout<<"I'm afraid you lost your clever bets of $"<<bet<<endl;
        result(tot,dtot,bet);
    }
    else
        cout<<"It's a draw! Dealer wins by default"<<
                "\nAll bets are returned to the player, totaling $"<<bet<<endl;
    result(tot,dtot,bet);
    
    return 0;
}

void result(int tot, int dtot, int bet)
{
    ofstream out;
    out.open("BlackjackWinOrLost.dat");
    out<<"The player has a grand total of! "<<tot<<endl;
    out<<"The dealer has a grand total of! "<<dtot<<endl;
    
    if(tot>dtot)
    {
        out<<"The player is victorious! Huzzah!"<<endl;
        if(tot==21)
        {
            out<<"Congrautlations, you won a bet of "<<bet<<endl;
        }
    }
    else if(dtot>tot)
    {
        out<<"The dealer is victorious! Huzzah!"<<endl;
    }
    else
        out<<"It's a tie! ouch!"<<endl;
    
}