#include <iostream>
#include <queue>
#include <set>
#include <iomanip>
#include "Triangle.h"
#include "Hexagon.h"
#include "Ellipse.h"
#include "Circle.h"

enum FigureType
{
	TRIANGLE,
	HEXAGON,
	ELLIPSE,
	CIRCLE,

	NUM_OF_TYPES
};

const char* const  FIGURES[NUM_OF_TYPES] = { "triangle", "hexagon", "ellipse", "circle" };

void FillRect(std::vector<Shape*>& shapes, double rectWidth, double rectHeight)
{
	if (shapes.empty())
		return;

	std::set<Vector2> added;
	std::queue<Shape*> q;

	q.push(shapes[0]);
	added.insert(shapes[0]->Center());

	while (!q.empty())
	{
		Shape* shape = q.front();
		q.pop();

		auto neighbours = shape->GetAdjecentShapes();
		for (Shape*& neighbour : neighbours)
			if (!added.count(neighbour->Center()))
			{
				if (neighbour->IsInRectangle(rectWidth, rectHeight))
				{
					added.insert(neighbour->Center());
					shapes.push_back(neighbour);
					q.push(neighbour);
				}
				else
				{
					delete neighbour;
					neighbour = nullptr;
				}
			}
	}
}

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


bool Initialize(std::vector<Shape*>& shapes, Vector2& rect, double& angle, int type, double& size1, double size2)
{
	if (!PrintRead("Enter rectangle width: ", rect.x)) return false;
	if (!PrintRead("Enter rectangle height: ", rect.y)) return false;
	if (!PrintRead("Enter angle: ", angle))	return false;

	std::cout << "Figure types:\n";
	for (int i = 0; i < NUM_OF_TYPES; ++i)
		std::cout << "\t" << i << ": " << FIGURES[i] << "\n";

	if (!PrintRead("Enter figure type: ", type)) return false;
	if (!PrintRead("Enter figure dimension: ", size1)) return false;

	if (type == FigureType::ELLIPSE &&
		!PrintRead("Enter second figure dimension: ", size2))
		return false;

	switch (type)
	{
	case TRIANGLE:
		shapes.push_back(new Triangle(size1));
		break;
	case HEXAGON:
		shapes.push_back(new Hexagon(size1));
		break;
	case ELLIPSE:
		shapes.push_back(new Ellipse(size1, size2));
		break;
	case CIRCLE:
		shapes.push_back(new Circle(size1));
		break;
	default:
		std::cout << "Invalid shape type\n";
		return false;
	}

	if (shapes[0]->IsInRectangle(rect.x, rect.y) == false)
	{
		delete shapes[0];
		shapes.pop_back();
	}

	return true;
}

int main()
{
	Vector2 rect;
	double angle = 0;
	int type = -1;
	double size = 0, size2 = 0;

	std::vector<Shape*> shapes;
	
	while (Initialize(shapes, rect, angle, type, size, size2) == false)
		std::cout << "\nTry again.\n";

	FillRect(shapes, rect.x, rect.y);

	double overallArea = 0;
	if (shapes.size() > 0)
		overallArea = shapes.size() * shapes[0]->Area();

	for (Shape* shape : shapes)
		shape->Rotate(angle, true);

	std::cout << "Number of plants: " << shapes.size() << "\n";
	std::cout << "Coordinates: \n";

	for (Shape* shape : shapes)
		std::cout << "\t(" << shape->Center().x << ", " << shape->Center().y << ")\n";

	double areaCovered = (100 * overallArea) / (rect.x * rect.y);
	std::cout << "Overall area covered: ";
	std::cout<< std::fixed << std::setprecision(2) << areaCovered << "%\n";

	for (auto& shape : shapes)
		delete shape;
}
