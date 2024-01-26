#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // make a loop that prints # for the right amount of lines
    // height of pyramid
    for(int i = 0; i < height; i++)
    {
        // make spaces
        for(int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        for(int j = 0; j <= i ; j++)
        {
            printf("#");
        }

        printf("\n");
   }
}