//Written by 04-0134-0007
//Date: 12-15-12018

#include <string>
#include <cstdio>

char getNumFromLetter(char letter)
{
    //Each array index represents a button on a phone (begins from the 2 button)
    //+1 is for the \0 exit code
    char buttons[8][4+1] =
    {
    "ABC ",
    "DEF ",
    "GHI ",
    "JKL ",
    "MNO ",
    "PQRS",
    "TUV ",
    "WXYZ",
    };

    //Convert lowercase letter to uppercase:
    if(letter > 90)
        letter -= 32;

    //Check for a match in the array
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(letter == buttons[i][j])
                //Add 2 because the array begins at the 2 button, add 48 to convert number to char
                return ((i + (48 + 2)));
        }
    }
}

void convert(char *number)
{
    for(int i = 0; i < 14; ++i)
    {
        //If the character is a dash or represents a number (e.g. '1')
        if(number[i] == '-' || number[i] < 65)
            continue;
        number[i] = getNumFromLetter(number[i]);
    }
}

int main()
{
//Holds the phone number throughout the entire process in the format: X-XXX-XXX-XXXX
char number[14];

while(true)
{
    printf("Input phone number: ");
    //Allow an input of 14 characters max
    scanf("%14s", number);

    //Break out of the loop if the country code is 9
    if(number[0] == '9')
        break;

    //Convert the number
    convert(number);
    printf("The real phone number is: ");
    printf("%s\n\n", number);
}

return 0;
}
