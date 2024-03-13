#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average value of RGB components
            BYTE avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set each RGB component to the average value
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels horizontally
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    // Iterate over the image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int totalRed = 0, totalGreen = 0, totalBlue = 0;

            // Iterate over the surrounding pixels (3x3 grid)
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    // Check if the surrounding pixel is within bounds
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        totalRed += image[new_i][new_j].rgbtRed;
                        totalGreen += image[new_i][new_j].rgbtGreen;
                        totalBlue += image[new_i][new_j].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate average RGB values and assign to temporary image
            temp[i][j].rgbtRed = round((float) totalRed / count);
            temp[i][j].rgbtGreen = round((float) totalGreen / count);
            temp[i][j].rgbtBlue = round((float) totalBlue / count);
        }
    }

    // Copy temporary image back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel operators for edge detection
    int Gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    // Iterate over the image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_red = 0, Gy_red = 0, Gx_green = 0, Gy_green = 0, Gx_blue = 0, Gy_blue = 0;

            // Iterate over the surrounding pixels (3x3 grid)
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    // Check if the surrounding pixel is within bounds
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        Gx_red += Gx_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtRed;
                        Gy_red += Gy_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtRed;

                        Gx_green += Gx_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtGreen;
                        Gy_green += Gy_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtGreen;

                        Gx_blue += Gx_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtBlue;
                        Gy_blue += Gy_kernel[k + 1][l + 1] * image[new_i][new_j].rgbtBlue;
                    }
                }
            }

            // Calculate final gradient values using Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap values at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // Assign final RGB values to temporary image
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    // Copy temporary image back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
