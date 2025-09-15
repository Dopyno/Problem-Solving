#include <stdio.h>

int main()
{
    // use array of strings pointers to store multiple titles
    // each pointer points to the first character of a string literal
    // use of pointers instead of a 2D array is more memory efficient and flexible 
    char *playList[8] = {"The Dead Dance", "Golden", "Sapphire", "Man I Need", "Ordinary",
                         "Tears", "If He Wanted To He Would", "Pink Pony Club"};

    printf("This is the playlist with top songs from this week: \n");

    // iterate the array
    for (int i = 0; i < 8; i++)
    {
        printf("Current song: '%s'", playList[i]); // display the current song
        printf(" | ");
        printf("First song: '%s'", playList[0]); // display the first song
        printf("\n");
    }
    return 0;
}
