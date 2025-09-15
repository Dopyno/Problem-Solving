#include <stdio.h>
#include <string.h> // use to allow us to use strcmp

int main()
{
    // use array of strings pointers to store multiple titles
    // each pointer points to the first character of a string literal
    // use of pointers instead of a 2D array is more memory efficient and flexible
    char *playList[8] = {"The Dead Dance", "Golden", "Sapphire", "Man I Need", "Ordinary",
                         "Tears", "If He Wanted To He Would", "Pink Pony Club"};
    char *temp; // use a temporary variable to help you swap the songs
                // the pointer will help us to point to the memory address where the songs are stored

    printf("This is the playlist with top songs from this week: \n");

    // Printing the array before processing
    printf("\nPlaylist before processing: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("Nr: %d - '%s'\n", i + 1, playList[i]); // display each song from playlist
    }

    // Loop to find the alphabetically first song and swap it with index 0
    for (int i = 1; i < 8; i++) // iterate from the second array element to be compare with the first one
    {
        if (strcmp(playList[i], playList[0]) < 0)
        {
            temp = playList[0]; // store the
            playList[0] = playList[i];
            playList[i] = temp;
        }
    }

    // Printing the array after processing
    printf("\nPlaylist after processing: \n"); // display the current song
    for (int i = 0; i < 8; i++)
    {
        printf("Nr: %d - '%s'\n", i + 1, playList[i]); // display each song from playlist alphabetically
    }
    return 0;
}
