#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
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
            int red = image[i][width - j - 1].rgbtRed;
            int green = image[i][width - j - 1].rgbtGreen;
            int blue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;

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


    for (int i = 1; i < height-1; i++)
    {
        for (int j = 1; j < width-1; j++)
        {
            RGBTRIPLE buffer[height][width];
            int counter = 0;
            int red = 0, green = 0, blue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                        red += image[i+k][j+m].rgbtRed;
                        green += image[i+k][j+m].rgbtGreen;
                        blue += image[i+k][j+m].rgbtBlue;
                        counter++;
                }
            }

            image[i][j].rgbtRed = round(red/counter);
            image[i][j].rgbtGreen = round(green/counter);
            image[i][j].rgbtBlue = round(blue/counter);


        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
