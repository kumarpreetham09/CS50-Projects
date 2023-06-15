#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int16_t buffer;

    while (fread(&buffer, 1, 1, input))
    {


        
        fwrite(&buffer, 1, 1, output);
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image.rgbtBlue)/3)
            image[i][j].rgbtRed = average
            image[i][j].rgbtGreen = average
            image[i][j].rgbtBlue = average

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
