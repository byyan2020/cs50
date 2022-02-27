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
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            float counter = 0;
            for (int k = i-1; k < (i + 2); k++)
            {
                for (int l = j-1; l < (j + 2); l++)
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
            // printf("%i, %i, %i\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
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
    // get a new array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_red = 0;
            int Gx_green = 0;
            int Gx_blue = 0;
            int Gy_red = 0;
            int Gy_green = 0;
            int Gy_blue = 0;
            float counter = 0;
            for (int k = i-1; k < (i + 2); k++)
            {
                for (int l = j-1; l < (j + 2); l++)
                {
                    if (k < 0 || l < 0 || k >= width || l >= width)
                    {
                        image[k][l].rgbtRed = 0;
                        image[k][l].rgbtGreen = 0;
                        image[k][l].rgbtBlue = 0;
                    }
                    Gx_red += image[k][l].rgbtRed * Gx[counter];
                    Gx_green += image[k][l].rgbtGreen * Gx[counter];
                    Gx_blue += image[k][l].rgbtBlue * Gx[counter];

                    Gy_red += image[k][l].rgbtRed * Gy[counter];
                    Gy_green += image[k][l].rgbtGreen * Gy[counter];
                    Gy_blue += image[k][l].rgbtBlue * Gy[counter];
                    
                    counter++;
                }
            }

            copy[i][j].rgbtRed = round(sum_red/counter);
            copy[i][j].rgbtGreen = round(sum_green/counter);
            copy[i][j].rgbtBlue = round(sum_blue/counter);
            // printf("%i, %i, %i\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
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
