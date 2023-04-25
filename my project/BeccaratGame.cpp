#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for the suits
const string SUITS[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

// Structure to represent a playing card
struct Card
{
    int value;
    string suit;
};

// Class to represent a deck of cards
class Deck
{
private:
    // Array to store the cards
    Card cards[52];
    // Index of the next card to be dealt
    int nextCard;

public:
    // Constructor to initialize the deck
    Deck()
    {
        int index = 0;
        for (int suit = 0; suit < 4; suit++)
        {
            for (int value = 1; value <= 13; value++)
            {
                cards[index].value = value;
                cards[index].suit = SUITS[suit];
                index++;
            }
        }
        nextCard = 0;
    }

    // Method to shuffle the deck
    void shuffle()
    {
        srand(time(NULL));
        for (int i = 0; i < 52; i++)
        {
            int j = rand() % 52;
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
        nextCard = 0;
    }

    // Method to deal a card
    Card deal()
    {
        Card card = cards[nextCard];
        nextCard++;
        return card;
    }
};

// Function prototype for the getValue function
int getValue(Card hand[], int numCards);

int main()
{
    // Create a deck of cards
    Deck deck;

    // Shuffle the deck
    deck.shuffle();

    // Play the game
    while (true)
    {
        // Deal the cards
        Card playerHand[2];
        Card bankerHand[2];
        playerHand[0] = deck.deal();
        bankerHand[0] = deck.deal();
        playerHand[1] = deck.deal();
        bankerHand[1] = deck.deal();

        // Display the hands
        cout << "Player's hand: " << playerHand[0].value << " of " << playerHand[0].suit << " ";
        cout << playerHand[1].value << " of " << playerHand[1].suit << " ";
        cout << "(" << getValue(playerHand, 2) << " points)" << endl;
        cout << "Banker's hand: " << bankerHand[0].value << " of " << bankerHand[0].suit << " ";
        cout << bankerHand[1].value << " of " << bankerHand[1].suit << " ";
        cout << "(" << getValue(bankerHand, 2) << " points)" << endl;

        // Determine the winner
        int playerValue = getValue(playerHand, 2);
        int bankerValue = getValue(bankerHand, 2);
        if (playerValue > bankerValue)
        {
            cout << "Player wins!" << endl;
        }
        else if (bankerValue > playerValue)
        {
            cout << "Banker wins!" << endl;
        }
        else
        {
            cout << "Tie!" << endl;
        }

        // Prompt the player to play again
        cout << "Play again (y/n)? ";
        char playAgain;
        cin >> playAgain;
        if (playAgain == 'n')
        {
            break;
        }
    }

    return 0;
}

// Function to calculate the value of a hand
int getValue(Card hand[], int numCards)
{
    int value = 0;
    for (int i = 0; i < numCards; i++)
    {
        if (hand[i].value > 10)
        {
            value += 10;
        }
        else
        {
            value += hand[i].value;
        }
    }
    if (value > 10)
    {
        value -= 10;
    }
    return value;
}