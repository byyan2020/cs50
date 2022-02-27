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
            BYTE gray_value = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);
            image[i][j].rgbtRed = gray_value;
            image[i][j].rgbtGreen = gray_value;
            image[i][j].rgbtBlue = gray_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // get a new array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red;
            int sum_green;
            int sum_blue;
            float counter = 0;
            for (int k = i-1; k < i+2; k++)
            {
                for (int l = j-1; l < j+2; j++)
                {
                    if (k < 0 || l < 0 || k >= width || l >= width)
                    {
                        continue;
                    }
                    sum_red += image[k][l].rgbtRed;
                    sum_green += image[k][l].rgbtGreen;
                    sum_blue += image[k][l].rgbtBlue;
                    counter++;
                }
            }

            copy[i][j].rgbtRed = round(sum_red/counter);
            copy[i][j].rgbtGreen = round(sum_green/counter);
            copy[i][j].rgbtBlue = round(sum_blue/counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
