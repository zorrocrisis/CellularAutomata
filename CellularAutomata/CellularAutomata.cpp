#include <iostream>
#include "MapGrid.cpp"
#include <vector>

// Define map features
int mapHeight;
int mapWidth;
int mapWallDensity;

// Cellular automaton
int automatonIterations;

// Multiple generation variables
bool continueGenerating = true;
std::string repeatAnswer;

int main()
{
    while (continueGenerating)
    {
        // Get user input -> try 20, 60, 35 and 5
        std::cout << "What should be the map's height (units)? ";
        std::cin >> mapHeight;

        std::cout << "What should be the map's width (units)? ";
        std::cin >> mapWidth;

        std::cout << "What should be the map's wall density (1 - 100)? ";
        std::cin >> mapWallDensity;

        // Creating grid
        MapGrid grid = MapGrid(mapHeight, mapWidth, mapWallDensity);

        // Cellular automaton
        std::cout << std::endl;
        std::cout << "Gow many iterations should the cellular automaton consider? ";
        std::cin >> automatonIterations;

        for (int i = 0; i < automatonIterations; i++)
        {
            // Go through each grid element
            for (int y = 0; y < mapHeight; y++)
            {
                for (int x = 0; x < mapWidth; x++)
                {
                    int wallCount = grid.GetSurroundingWallCount(y, x);

                    if (wallCount >= 4)
                    {
                        grid.UpdateTemporaryGrid(y, x, true);
                    }
                    else
                    {
                        grid.UpdateTemporaryGrid(y, x, false);
                    }

                }
            }

            grid.MergeTempGrid();
        }

        grid.DrawGrid();

        // Get user input
        std::cout << std::endl;
        std::cout << "Would you like to save this map to a .txt file (Y/y to confirm)? ";
        std::cin >> repeatAnswer;

        if (repeatAnswer == "Y" || repeatAnswer == "y")
            grid.SaveGridToFile();

        // Get user input
        std::cout << std::endl;
        std::cout << "Would you like to generate a new map (N/n to quit)? ";
        std::cin >> repeatAnswer;

        if (repeatAnswer == "N" || repeatAnswer == "n")
            continueGenerating = false;
    }
}

