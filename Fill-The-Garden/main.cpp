#include <iostream>
#include <queue>
#include <set>
#include <iomanip>
#include "Garden.h"


template<typename T>
bool PrintRead(const char* strToPrint, T& dataToRead)
{
	std::cout << strToPrint;
	std::cin >> dataToRead;

	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return false;
	}
	return true;
}


bool Initialize(Vector2& rect, double& angle, int& type, double& size1, double size2)
{
	if (!PrintRead("Enter rectangle width: ", rect.x)) return false;
	if (!PrintRead("Enter rectangle height: ", rect.y)) return false;
	if (!PrintRead("Enter angle: ", angle))	return false;

	std::cout << "Figure types:\n";
	for (int i = 0; i < Shape::NUM_OF_TYPES; ++i)
		std::cout << "\t" << i << ": " << Shape::NAMES[i] << "\n";

	if (!PrintRead("Enter figure type: ", type)) return false;
	if (!PrintRead("Enter figure dimension: ", size1)) return false;

	if (type == Shape::ELLIPSE &&
		!PrintRead("Enter second figure dimension: ", size2))
		return false;

	return true;
}

int main()
{
	Vector2 rect;
	double angle = 0;
	int type = -1;
	double size = 0, size2 = 0;
	
	while (Initialize(rect, angle, type, size, size2) == false)
	std::cout << "\nTry again.\n";

	Garden garden(rect.x, rect.y);
	garden.Fill((Shape::Type)type, size, size2);
	garden.Rotate(angle, true);
	garden.PrintPlantsCount();
	garden.PrintPlantsCenters();
	garden.PrintAreaCovered();

	return 0;
}
