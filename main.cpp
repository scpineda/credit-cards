#include <iostream>
#include <sstream>

using namespace std;

void getInput(int cardNum[]);
bool validCard(int cardNum[]);
void print(int cardNum[]);

int main()
{
    // Validate a credit card
    int cardNum[16];

    // get the right input
    getInput(cardNum);

    // display
    print(cardNum);

    // Send it through hashing algorithm
    string str = "This is";

    if(!validCard(cardNum))
        str += " not";

    str += " a valid credit card number.";

    cout << str << endl;

}

void getInput(int cardNum[])
{
    cout << "Insert a 16 digit Credit Card Number seperated by spaces." << endl;

    string str;
    stringstream ss;
    size_t length;

    char c;
    char junk;

    bool invalid = true;

    while(invalid)
    {
        getline(cin, str);

        length = str.length();

        ss << str;

        if(length != 19)
            cout << "Invalid. Try again." << endl;

        else
            break;

    }

    // place every int into the array of ints
    for(size_t i = 0; i < 16; ++i)
    {
        if(ss.peek() != ' ')
        {
            ss.get(c);
            cardNum[i] = c - '0';
        }

        else
        {
            ss.get(junk);
            --i;
        }
    }

}

bool validCard(int cardNum[])
{
    for(size_t i = 0; i < 16; i += 2)
    {
        // For every other digit, double its value
        cardNum[i] *= 2;

        // if the result is a two digit number, add up the digits
        if(cardNum[i] > 9)
        {
            int tensPlace, onesPlace;
            onesPlace = cardNum[i] % 10;
            cardNum[i] /= 10;
            tensPlace = cardNum[i];
            cardNum[i] = tensPlace + onesPlace;
        }
    }

    // The second loop adds everything together
    size_t checkSum = 0;

    for(size_t i = 0; i < 16; ++i)
        checkSum += cardNum[i];

    // See if checksum is divisible by 10
    if(checkSum % 10 == 0)
        return true;

    // else, return false

    return false;
}


void print(int cardNum[])
{
    cout << "Card Number: " ;

    for(size_t i = 0; i < 16; ++i)
    {
        cout << cardNum[i];

        if((i + 1) % 4 == 0)
            cout << " " ;
    }

    cout << endl;
}
