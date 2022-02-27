#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; i++)
        {
            RGBTRIPLE pixel = image[i][j];
            BYTE gray_value = (pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3;
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
