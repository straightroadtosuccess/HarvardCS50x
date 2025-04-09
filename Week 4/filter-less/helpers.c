#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Scan each row
    for (int i = 0; i < height; i++)
    {
        // Scan each column
        for (int j = 0; j < width; j++)
        {
            // Convert pixels to float
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            // Find the average
            int ave = round((R + G + B) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Scan each row
    for (int i = 0; i < height; i++)
    {
        // Scan each column
        for (int j = 0; j < width; j++)
        {
            // Convert pixels to float
            float oR = image[i][j].rgbtRed;
            float oG = image[i][j].rgbtGreen;
            float oB = image[i][j].rgbtBlue;

            // Find updated pixel values
            int sepiaR = round(0.393 * oR + 0.769 * oG + 0.189 * oB);
            int sepiaG = round(0.349 * oR + 0.686 * oG + 0.168 * oB);
            int sepiaB = round(0.272 * oR + 0.534 * oG + 0.131 * oB);

            // Update pixel values if they exceed 255
            if (sepiaR > 255)
            {
                sepiaR = 255;
            }
            if (sepiaG > 255)
            {
                sepiaG = 255;
            }
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }

            // Update final pixel value
            image[i][j].rgbtRed = sepiaR;
            image[i][j].rgbtGreen = sepiaG;
            image[i][j].rgbtBlue = sepiaB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Scan each row
    for (int i = 0; i < height; i++)
    {
        // Scan each column
        for (int j = 0; j < width / 2; j++)
        {
            // Store data in a TMP location, switch places in the array
            RGBTRIPLE TMP = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = TMP;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create an image copy
    RGBTRIPLE TMP[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            TMP[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Valid neighboring pixels
            int totalR, totalB, totalG;
            totalR = totalB = totalG = 0;
            float counter = 0.00;

            // Get neighboring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if neighboring pixels are valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 ||
                        currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalR += image[currentX][currentY].rgbtRed;
                    totalG += image[currentX][currentY].rgbtGreen;
                    totalB += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                // Calculate average of neighbouring pixels
                TMP[i][j].rgbtRed = round(totalR / counter);
                TMP[i][j].rgbtGreen = round(totalG / counter);
                TMP[i][j].rgbtBlue = round(totalB / counter);
            }
        }
    }

    // Copy new pixels into image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = TMP[i][j].rgbtRed;
            image[i][j].rgbtGreen = TMP[i][j].rgbtGreen;
            image[i][j].rgbtBlue = TMP[i][j].rgbtBlue;
        }
    }
    return;
}
