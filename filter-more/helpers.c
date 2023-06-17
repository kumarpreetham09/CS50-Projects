#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
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
    RGBTRIPLE buffer[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    float counter = 0;
    float red = 0, green = 0, blue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int row = i - 1; row < i + 2; row++)
            {
                for (int col = j - 1; col < j + 2; col++)
                {
                    if (col < width && row < height && col >= 0 && row >= 0)
                    {
                        red += buffer[row][col].rgbtRed;
                        green += buffer[row][col].rgbtGreen;
                        blue += buffer[row][col].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(red / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtBlue = round(blue / counter);
            counter = 0;
            red = 0, green = 0, blue = 0;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //create Gx matrix
    int Gx[3][3];
    int Gy[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1)
            {
                Gx[i][j] = 2 * (j-1);
            }
            else
            {
               Gx[i][j] = j - 1;
            }

        }
    }

    //create Gy matrix

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1)
            {
                Gy[j][i] = 2 * (j-1);
            }
            else
            {
               Gy[j][i] = j-1;
            }

        }
    }


    //copy infile

    RGBTRIPLE buffer[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    //for every pixel, multiply surrounding wrt to Gx matrix

    int redx = 0;
    int redy = 0;
    int greenx = 0;
    int greeny = 0;
    int bluex = 0;
    int bluey = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = j - 1; col <= j + 1; col++)
                {
                    if (col < width && row < height && col >= 0 && row >= 0)
                    {
                        redx += buffer[row][col].rgbtRed * Gx[row - i + 1][col - j + 1];
                        redy += buffer[row][col].rgbtRed * Gy[row - i + 1][col - j + 1];
                        greenx += buffer[row][col].rgbtGreen * Gx[row - i + 1][col - j + 1];
                        greeny += buffer[row][col].rgbtGreen * Gy[row - i + 1][col - j + 1];
                        bluex += buffer[row][col].rgbtBlue * Gx[row - i + 1][col - j + 1];
                        bluey += buffer[row][col].rgbtBlue * Gy[row - i + 1][col - j + 1];
                    }

                }
            }
            float Gred = sqrt(((redx) * (redx)) + ((redy) * (redy)));
            if (Gred > 255)
            {
                Gred = 255;
            }

                image[i][j].rgbtRed = Gred;


            float Ggreen = sqrt(((greenx) * (greenx)) + ((greeny) * (greeny)));
            if (Ggreen > 255)
            {
                Ggreen = 255;
            }

                image[i][j].rgbtGreen = Ggreen;


            float Gblue = sqrt(((bluex) * (bluex)) + ((bluey) * (bluey)));
            if (Gblue > 255)
            {
                Gblue = 255;
            }

            image[i][j].rgbtBlue = Gblue;

            redx = redy = greenx = greeny = bluex = bluey = Gred = Ggreen = Gblue = 0;

        }
    }
    //for every pixel, multiply surrounding wrt to Gy matrix

    //calculate pythagoras and input
    return;
}
