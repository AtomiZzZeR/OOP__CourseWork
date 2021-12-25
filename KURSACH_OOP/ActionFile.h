#pragma once
#include <iostream>
#include <string>
#include "Vector.h"
#include <fstream>
#include "Plant.h"

using namespace std;

class ActionFile
{
private:
	template<typename T1, typename T2>
	static void Write(string file, T1 object, T2 collection)
	{
		ofstream out(file, ofstream::out);

		if (out.is_open())
		{
			for (const T1& object : collection)
			{
				out.write((char*)&object, sizeof(T1));
			}
		}

		out.close();
	}

public:
	static void WriteFiles()
	{
		Plant Plant;
		Write("files\\plants.bin", Plant, Vector::plants);
	}

	static void ReadFiles()
	{
		Vector::plants.clear();

		ifstream in("files\\plants.bin", ios::app);

		if (in.is_open())
		{
			Plant plant;

			while (in.read((char*)&plant, sizeof(plant)))
			{
				Vector::plants.push_back(plant);
			}
		}

		in.close();
	}
};

