#include "SaveLoad.h"
#include <iostream>
#include <String>
#include <fstream>

using namespace std;

void SaveLoad::Save(string filename, int* buffer, int X_COUNT, int Y_COUNT)
{
	ofstream myfile;
	myfile.open(filename);

	for (size_t y = 0; y < Y_COUNT; y++)
	{
		for (size_t x = 0; x < X_COUNT; x++)
		{
			int i = x + y * X_COUNT;
			myfile << buffer[i] << ", ";
		}

		myfile << std::endl;
	}

	myfile.close();
}

void SaveLoad::Load(std::string filename, int* buffer, int size, Example& example)
{
	string line;
	ifstream myfile(filename);
	int i = 0;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int cutStart = 0;
			int commaIndex = -1;

			while (true)
			{
				cutStart = commaIndex + 1;
				commaIndex = line.find(',', commaIndex + 1);

				if (commaIndex < 0)
					break;

				string numStr = line.substr(cutStart, commaIndex - cutStart);
				buffer[i] = std::stoi(numStr);
				i++;
			}

			std::cout << std::endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";


	//example.SetTilesFromMap();
}