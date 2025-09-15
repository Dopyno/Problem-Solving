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
    int minimumIndex;

    printf("This is the playlist with top songs from this week: \n");

    // Printing the array before sorting
    printf("\nPlaylist before sorting: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("Nr: %d - '%s'\n", i + 1, playList[i]); // display each song from playlist
    }

    // using a bubble sort algorithm
    for (int i = 0; i < 8 - 1; i++) // iterate from the first element unsorted
    {                               // On each pass of the outer loop, we place the smallest remaining string at index i.
                                    // After each pass,the elements before i are sorted, and the elements after i are unsorted
        {
            minimumIndex = i;               // Assume the first unsorted element is the smallest
            for (int j = i + 1; j < 8; j++) // compare each remaining unsorted element with the current minimum
            {
                if (strcmp(playList[j], playList[minimumIndex]) < 0)
                {
                    minimumIndex = j; // Found a smaller string and update minIndex
                }
            }
            // Swap the first unsorted element with the smallest found
            if (minimumIndex != i)
            {
                temp = playList[i];
                playList[i] = playList[minimumIndex];
                playList[minimumIndex] = temp;
            }
        }
    }

    // Printing the array after sorting
    printf("\nPlaylist after sorting: \n"); // display the current song
    for (int i = 0; i < 8; i++)
    {
        printf("Nr: %d - '%s'\n", i + 1, playList[i]); // display each song from playlist alphabetically
    }

    return 0;
}