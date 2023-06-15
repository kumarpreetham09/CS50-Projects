#include "helpers.h"
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int *red = malloc(sizeof(int));
            *red = image[i][j].rgbtRed;
            image[i][width - j].rgbtRed = *red;
            free(red);

            int *green = malloc(sizeof(int));
            *red = image[i][j].rgbtGreen;
            image[i][width - j].rgbtGreen = *green;
            free(green);

            int *blue = malloc(sizeof(int));
            *red = image[i][j].rgbtBlue;
            image[i][width - j].rgbtBlue = *blue;
            free(blue);

        }
    }

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
