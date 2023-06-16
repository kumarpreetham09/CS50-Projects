#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
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
    int k = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int red = image[i][width - j].rgbtRed;
            int green = image[i][width - j].rgbtGreen;
            int blue = image[i][width - j].rgbtBlue;

            image[i][width - j].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][width - j].rgbtGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k < 2; k++)
            {
  
                for (int m = -1; m < 2; m++)
                {
                    red += image[i + k][j + m].rgbtRed;
                    green += image[i + k][j + m].rgbtGreen;
                    blue += image[i + k][j + m].rgbtBlue;
                }
            }

            image[i][j].rgbtRed = red/9;
            image[i][j].rgbtGreen = green/9;
            image[i][j].rgbtBlue = blue/9;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
