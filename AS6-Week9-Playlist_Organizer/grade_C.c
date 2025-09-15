#include <stdio.h>

int main()
{
    // use array of strings pointers to store multiple titles
    char *playList[8] = {"The Dead Dance", "Golden", "Sapphire", "Man I Need", "Ordinary", "Tears", "If He Wanted To He Would"};
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
