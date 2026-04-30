#include <iostream>
#include <algorithm>
#include <format>
#include <vector>
#include <string>
constexpr double pi = 3.14159; // alternative to "define" which is apparently better

void exercice1()
{
	int inputs[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::format("Enter a number ({}): ", i + 1);
		std::cin >> inputs[i];
	}
	int sum = 0;
	int product = 1;
	int max = 0;
	int min = inputs[0];
	// calculate sum, product, max and min
	for (int i = 0; i < 4; i++)
	{
		sum += inputs[i];
		product *= inputs[i];
		if (max < inputs[i])
		{
			max = inputs[i];
		}
		if (min > inputs[i])
		{
			min = inputs[i];
		}
	}
	float average = sum / 4.0;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Product: " << product << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Min: " << min << std::endl;
}

void exercice2()
{
	float radius;
	std::cout << "Enter the circle's radius: ";
	std::cin >> radius;
	std::cout << "Diameter: " << 2.0 * radius << std::endl;
	std::cout << "Circumference: " << 2.0 * radius * pi << std::endl;
	std::cout << "Area: " << pi * std::pow(radius, 2.0) << std::endl;
}


void exercice3(char* nameGot)
{
	std::cout << std::format("Bonjour {}", nameGot) << std::endl;
}

void exercice4()
{
	int numberGot;
	std::cout << "Enter a number: ";
	std::cin >> numberGot;
	int tempNumber = numberGot;
	std::vector<int> binaryResult;
	while (tempNumber > 0)
	{
		binaryResult.push_back(tempNumber % 2);
		tempNumber /= 2;
	}
	//std::reverse(binaryResult.begin(), binaryResult.end()); // Not needed for this exercice, but useful to get the actual binary result

	int totalBits = 0;
	for (int bitGot : binaryResult)
	{
		if (bitGot == 1)
		{
			totalBits++;
		}
	}
	std::cout << "Bits result: " << totalBits << std::endl;
}

void exercice5()
{
	int numberGot;
	std::cout << "Enter a number: ";
	std::cin >> numberGot;
	int tempNumber = numberGot;
	std::vector<int> binaryResult;
	while (tempNumber > 0)
	{
		binaryResult.push_back(tempNumber % 2 == 1 ? 0 : 1); // inverts the bits
		tempNumber /= 2;
	}
	std::reverse(binaryResult.begin(), binaryResult.end());

	int resultGot = 0;
	int idxGot = binaryResult.size();
	for (int bitGot : binaryResult)
	{
		idxGot -= 1;
		resultGot += bitGot * std::pow(2, idxGot);
	}
	std::cout << "Decimal result: " << resultGot << std::endl;
}

void exercice6()
{
	int numberGot;
	std::cout << "Enter a number: ";
	std::cin >> numberGot;
	int tempNumber = numberGot;
	if (numberGot > 0)
	{
		while (tempNumber % 2 == 0)
		{
			tempNumber = floor(tempNumber / 2);
		}
		std::cout << "This number " << (tempNumber == 1 ? "is" : "is not") << " a power of two" << std::endl;
	}
	else
	{
		std::cout << "Number must be above 0" << std::endl;
	}
}

void exercice7()
{
	int yAmount = 9;
	int xStart = 5;
	for (int yGot = 0; yGot < yAmount; yGot++)
	{
		for (int i = 0; i < xStart - (yGot < (yAmount / 2) ? yGot : (yAmount - yGot)); i++)
		{
			std::cout << " ";
		}
		for (int i2 = 0; i2 < (yGot == 0 || yGot == yAmount - 1 ? 1 : 2); i2++)
		{
			if (i2 == 1)
			{
				for (int xIdx = 0; xIdx < (yGot < (yAmount / 2) ? yGot * 2 - 2 : (yAmount - yGot) * 2 - 3); xIdx++)
				{
					std::cout << " ";
				}
			}
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void exercice8()
{
	int xMax = 5;
	// Draw triangle
	for (int i = 0; i < 3; i++)
	{
		for (int i2 = 0; i2 < (xMax - i); i2++)
		{
			std::cout << " ";
		}
		for (int i3 = 0; i3 < i + 1; i3++)
		{
			if (i3 > 0)
			{
				std::cout << "*";
			}
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	int lineLengthY = 5;
	// Draw line below triangle
	for (int i = 0; i < lineLengthY; i++)
	{
		for (int i2 = 0; i2 < xMax; i2++)
		{
			std::cout << " ";
		}
		std::cout << "*" << std::endl;
	}
}

void exercice9()
{
	int numberGot;
	std::cout << "Enter a number (between 0-999): ";
	std::cin >> numberGot;
	if (numberGot < 0 || numberGot > 999)
	{
		return;
	}
	int totalResult = 0;
	std::vector<int> listDigits;
	while (numberGot > 0)
	{
		int remainderGot = numberGot % 10;
		totalResult += remainderGot;
		numberGot /= 10;
		listDigits.push_back(remainderGot);
	}
	std::reverse(listDigits.begin(), listDigits.end());
	int idx = 0;
	for (int digitGot : listDigits)
	{
		if (idx > 0)
		{
			std::cout << " + ";
		}
		std::cout << digitGot;
		idx++;
	}
	// if the input number is "0", then show "0" instead of nothing
	if (listDigits.size() <= 0)
	{
		std::cout << "0";
	}
	std::cout << " = ";
	std::cout << totalResult << std::endl;
}

void exercice10()
{
	int numberGot;
	std::cout << "Enter a number: ";
	std::cin >> numberGot;
	int temporaryNumberGot = numberGot;

	std::string binaryStrResult;
	while (temporaryNumberGot > 0)
	{
		temporaryNumberGot /= 2;
		int resultBit = temporaryNumberGot % 2;
		// prevents an extra bit at the end
		if (temporaryNumberGot > 0)
		{
			binaryStrResult += std::to_string(resultBit);
		}
	}
	std::cout << numberGot << " = " << binaryStrResult << std::endl;
}
int main(int argc, char** argv)
{
	exercice1();
	exercice2();
	if (argc == 2)
	{
		exercice3(argv[1]);
	}
	exercice4();
	exercice5();
	exercice6();
	exercice7();
	exercice8();
	exercice9();
	exercice10();
	return 0;
}
