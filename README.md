## **Cellular Automata**
A simple cellular automata built in my free time, in a single day. This algorithm is commonly utilised to create procedurally generated worlds for (simple) video games!

In essence, the algorithm takes a randomly generated map, containing "wall" tiles, represented by "X", and "floor" tiles, represented by "_", and progressively generates a new map, following a set of rules to define whether tiles should be walls or floors.

<p align="center">
  <img src="https://github.com/user-attachments/assets/7754b686-9d88-4984-88df-331ddd8a39ca" width=500/>
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/7da0dc24-5a8c-40c7-b218-bdaafdca09bb" width=500/>
</p>


## **Quick Start**
1. Clone the repository or download and unzip the files

If you plan on taking a look at the source code:
2. Open the solution in Visual Studio (last tested with version 2022)
3. You can run the program with F5

If you plan on just taking a look at the build itself:
2. Navigate to x64 > Release and execute "CellularAutomata.exe"

You can **change the generate map's parameters** (height, width and "wall" density). Try 20 height, 60 width and 35 "wall density"...

You can additionally **alter the number of iterations considered by the algorithm** (try 6 vs 20) and **save the resulting maps to a .txt file**.


## **Authors and Acknowledgements**
This project was developed by **[Miguel Belbute (zorrocrisis)](https://github.com/zorrocrisis)**, having explored the resources available [here}(https://www.youtube.com/watch?v=slTEz6555Ts).
