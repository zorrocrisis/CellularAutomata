#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class MapGrid
{
	private:
		// Grid features
		int gridHeight;
		int gridWidth;
		int gridDensity;
		std::string wallText = "X";
		std::string floorText = "_";
		int seed;

		// Grids
		std::vector<std::vector<std::string>> grid;
		std::vector<std::vector<std::string>> tempGrid;
		

	public:

		MapGrid(int h, int w, int gd):

			gridHeight(h), gridWidth(w),
			grid(h, std::vector<std::string>(w)),
			tempGrid(h, std::vector<std::string>(w)),
			gridDensity(gd)

		{
			// Seeds the random function
			seed = time(NULL);
			srand(seed);

			std::cout << std::endl;
			std::cout << "Initial Grid: " << std::endl << std::endl;

			// Go through each grid element
			for (int y = 0; y < gridHeight; y++)
			{
				for (int x = 0; x < gridWidth; x++)
				{

					// Assign a random value to determine if each tile is either wall or floor
					int randomValue = rand() % 100 + 1; // 1 - 100

					std::string assignedString;

					if (randomValue > gridDensity)
					{
						assignedString = floorText; // floor
					}
					else
					{
						assignedString = wallText; // wall
					}

					// Update grid value
					SetGridValue(y, x, assignedString);

					// Progressively draw initial map
					std::cout << assignedString;
				}

				std::cout << std::endl;
			}

			tempGrid = grid;
		}

		std::vector<std::vector< std::string>> GetGrid()
		{
			return grid;
		}

		void SetGridValue(int h, int w, std::string value)
		{
			if(h >= 0 && h < gridHeight && w >= 0 && w < gridWidth)
				grid[h][w] = value;
			else
				throw std::out_of_range("Grid index out of range");
		}

		std::string GetGridValue(int h, int w)
		{
			if (h >= 0 && h < gridHeight && w >= 0 && w < gridWidth)
				return grid[h][w];
			else
				throw std::out_of_range("Grid index out of range");
		}

		int GetSurroundingWallCount(int h, int w)
		{
			if (h >= 0 && h < gridHeight && w >= 0 && w < gridWidth)
			{
				int wallCount = 0;

				// Each grid element has 8 neighbours
				for (int y = h - 1; y <= h + 1; y++)
				{
					for (int x = w - 1; x <= w + 1; x++)
					{
						// Check if we are close to the map's boundary
						if (y < 0 || y >= gridHeight || x < 0 || x >= gridWidth)
						{
							wallCount++;
						}
						else
						{
							// Skip over self
							if (!(y == h && x == w))
							{
								if (GetGridValue(y, x) == wallText)
								{
									wallCount++;
								}
							}
						}
					}
				}

				return wallCount;
			}
			else
				throw std::out_of_range("Grid index out of range");
		}

		void UpdateTemporaryGrid(int h, int w, bool isWall)
		{
			if (h >= 0 && h < gridHeight && w >= 0 && w < gridWidth)
				if(isWall)
					tempGrid[h][w] = wallText;
				else
					tempGrid[h][w] = floorText;
			else
				throw std::out_of_range("Grid index out of range");
		}

		void MergeTempGrid()
		{
			grid = tempGrid;
		}

		void DrawGrid()
		{
			std::cout << std::endl;
			std::cout << "Current Grid: " << std::endl << std::endl;

			// Go through each grid element
			for (int y = 0; y < gridHeight; y++)
			{
				for (int x = 0; x < gridWidth; x++)
				{
					std::cout << GetGridValue(y, x);
				}

				std::cout << std::endl;
			}
		}


		void SaveGridToFile()
		{
			std::ofstream myfile;
			std::string fileName = "map_" + std::to_string(gridHeight) + "h" + std::to_string(gridWidth) +
										 "w_" + std::to_string(gridDensity) + "gd_" + std::to_string(seed) + ".txt";
			myfile.open(fileName);

			// Go through each grid element
			for (int y = 0; y < gridHeight; y++)
			{
				for (int x = 0; x < gridWidth; x++)
				{
					myfile << GetGridValue(y, x);
				}

				myfile << std::endl;
			}

			myfile.close();
			std::cout << "Saved " << fileName << "!" << std::endl;
		}
};