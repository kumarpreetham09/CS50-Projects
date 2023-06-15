#include "helpers.h"
#include "stdlib.h"

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
            int *red[i][j] = malloc(sizeof(int));
            *red[i][j] = image[i][j].rgbtRed;

            int *green[i][j] = malloc(sizeof(int));
            *green[i][j] = image[i][j].rgbtGreen;

            int *blue[i][j] = malloc(sizeof(int));
            *blue[i][j] = image[i][j].rgbtBlue;
        }
    }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][width - j].rgbtRed = *red_[i][j];
                image[i][width - j].rgbtGreen = *green_[i][j];
                image[i][width - j].rgbtBlue = *blue_[i][j];
                free(red_[i][j]);
                free(green_[i][j]);
                free(blue_[i][j]);

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
