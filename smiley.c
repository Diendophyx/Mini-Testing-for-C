// solution by liffeg
#include helpers.h
#include <math.h>

// Convert picture to grayscale
void grayscale(int height, int width, RGBTRIPLE picture[height][width])
{
    double avrg;

    //cycle rows
    for (int i = 0; i < height; i++)
    {
         //cycle columns
        for (int j = 0; j < width; j++)
        {
            //find average value
            avrg = ((picture[i][j].rgbtBlue + picture[i][j].rgbtGreen + picture[i][j].rgbtRed) / 3.0000);

            //round average value
            avrg = round(avrg);

            //assign average value to all colors aka change pixels to grayscale
            picture[i][j].rgbtBlue = avrg;
            picture[i][j].rgbtGreen = avrg;
            picture[i][j].rgbtRed = avrg;
        }
    }
    return;
}

// Convert picture to sepia
void sepia(int height, int width, RGBTRIPLE picture[height][width])
{
    // declare variables
    float sepiaRed, sepiaGreen, sepiaBlue;
    int originalRed, originalGreen, originalBlue;

    //cycle rows
    for (int i = 0; i < height; i++)
    {
        //cycle columns
        for (int j = 0; j < width; j++)
        {
          //assign values to variables
          originalRed = picture[i][j].rgbtRed;
          originalGreen = picture[i][j].rgbtGreen;
          originalBlue = picture[i][j].rgbtBlue;

          //used original formula to avoid mistakes or typos.
          sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
          sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
          sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

          //round numbers
          sepiaRed = round(sepiaRed);
          sepiaGreen = round(sepiaGreen);
          sepiaBlue = round(sepiaBlue);

          // check if any value exeed 255, and if so set to 255 else leave as it is
          sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
          sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
          sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

          picture[i][j].rgbtRed = sepiaRed;
          picture[i][j].rgbtGreen = sepiaGreen;
          picture[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect picture horizontally
void reflect(int height, int width, RGBTRIPLE picture[height][width])
{
    // make temp storage variable
    RGBTRIPLE tmp[1][1];
    int last = width;
    int first = 0;

    //cycle through the rows
    for (int i = 0; i < height; i++)
    {
        // counters for swaps, reset after each row
       last = width - 1;
       first = 0;

        //swap pixels
        for (int j = 0; j < width/2; j++)
        {
            tmp[0][0] = picture[i][first];
            picture[i][first]= picture[i][last];
            picture[i][last] = tmp[0][0];

            last--;
            first++;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE picture[height][width])
{
    RGBTRIPLE picture_blur[height][width];
    double avgRed, avgGreen, avgBlue;
    float counter;
    for (int i = 0; i < height; i++)
    {
        // cycle columns
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;
            for (int s = -1; s < 2; s++)
            {
                for(int n = -1; n < 2; n++)
                {
                    int d = i + s;
                    int k = j + n;

                    if (d < height && k < width && d >= 0 && k >= 0)
                    {

                        avgRed = avgRed + picture[d][k].rgbtRed;
                        avgGreen = avgGreen + picture[d][k].rgbtGreen;
                        avgBlue = avgBlue + picture[d][k].rgbtBlue;
                        counter++;
                    }
                }
            }

               // avg to intg
            avgRed = round(avgRed / counter);
            avgGreen = round(avgGreen / counter);
            avgBlue = round(avgBlue / counter);

            picture_blur[i][j].rgbtRed = avgRed;
            picture_blur[i][j].rgbtGreen = avgGreen;
            picture_blur[i][j].rgbtBlue = avgBlue;

        }

    }

    // Overwirte variable?

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            picture[i][j] = picture_blur[i][j];
        }
    }

    return;
}