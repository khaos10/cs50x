#include <math.h>
#include <stdlib.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average pixel value
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set each color value to the average value
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
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on horizontally opposite sides
            RGBTRIPLE *x = &image[i][j];
            RGBTRIPLE *y = &image[i][width - 1 - j];

            RGBTRIPLE tmp = *x;
            *x = *y;
            *y = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image into memory
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    // Define the new color
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate sum of pixels' colors
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        sum_red += copy[k][l].rgbtRed;
                        sum_green += copy[k][l].rgbtGreen;
                        sum_blue += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            // Calculate average
            image[i][j].rgbtRed = round((float)sum_red / (float)count);
            image[i][j].rgbtGreen = round((float)sum_green / (float)count);
            image[i][j].rgbtBlue = round((float)sum_blue / (float)count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image into memory
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    // Apply the Sobel operator
    int gx_filter[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_filter[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

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
            for (int k = i - 1, m = 0; k <= i + 1; k++, m++)
            {
                for (int l = j - 1, n = 0; l <= j + 1; l++, n++)
                {
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        // Calculate Gx for each channel
                        Gx_red += copy[k][l].rgbtRed * gx_filter[m][n];
                        Gx_green += copy[k][l].rgbtGreen * gx_filter[m][n];
                        Gx_blue += copy[k][l].rgbtBlue * gx_filter[m][n];

                        // Calculate Gy for each channel
                        Gy_red += copy[k][l].rgbtRed * gy_filter[m][n];
                        Gy_green += copy[k][l].rgbtGreen * gy_filter[m][n];
                        Gy_blue += copy[k][l].rgbtBlue * gy_filter[m][n];
                    }
                }
            }
            // Combine Gx and Gy for each channel
            int edge_red = round(sqrt((Gx_red * Gx_red) + (Gy_red * Gy_red)));
            int edge_green = round(sqrt((Gx_green * Gx_green) + (Gy_green * Gy_green)));
            int edge_blue = round(sqrt((Gx_blue * Gx_blue) + (Gy_blue * Gy_blue)));

            // Ensure the resulting value is capped at 255
            if (edge_red > 255)
            {
                edge_red = 255;
            }

            if (edge_green > 255)
            {
                edge_green = 255;
            }

            if (edge_blue > 255)
            {
                edge_blue = 255;
            }
            // Set each color value to the edge value
            image[i][j].rgbtRed = edge_red;
            image[i][j].rgbtGreen = edge_green;
            image[i][j].rgbtBlue = edge_blue;
        }
    }
    return;
}
