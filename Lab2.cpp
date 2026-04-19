#include <iostream>
#include <vector>
#include <string>

std::string exercice1(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] + 1;
	}
	return str;
}

std::string exercice2(std::string str)
{
	str[0] = toupper(str[0]);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str[i + 1] = toupper(str[i + 1]);
		}
	}
	return str;
}

struct WordInfo
{
	int length = 0;
	int idxStart = 0;
	int idxEnd = 0;
};

std::string exercice3(std::string str)
{
	std::vector<WordInfo> wordsInfo;
	int lastWordStartIdx = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			WordInfo infoWord{ (i + 1) - lastWordStartIdx, lastWordStartIdx, (i + 1) };
			wordsInfo.push_back(infoWord);
			lastWordStartIdx = (i + 1);
		}
	}
	WordInfo tempLongestResult;
	for (const WordInfo wordInfoGot : wordsInfo)
	{
		if (tempLongestResult.length < wordInfoGot.length)
		{
			tempLongestResult.length = wordInfoGot.length;
			tempLongestResult.idxStart = wordInfoGot.idxStart;
			tempLongestResult.idxEnd = wordInfoGot.idxEnd;
		}
	}
	std::string resultStr;
	for (int iGot = tempLongestResult.idxStart; iGot < tempLongestResult.idxEnd; iGot++)
	{
		resultStr += str[iGot];
	}
	return resultStr;
}

std::string exercice4(std::string str)
{
	int strLength = str.length();
	for (int reverseIdx = strLength - 1; reverseIdx > 0; reverseIdx--)
	{
		if (str[(strLength - 1) - reverseIdx] != str[reverseIdx])
		{
			return "non (pas un palindrome)";
		}
	}
	return "oui (c'est un palindrome)";
}

int exercice5(std::string str)
{
	int strLength = str.length();
	int totalResult = 0;
	for (int charIdx = 0; charIdx < strLength; charIdx++)
	{
		if (str[charIdx] == ' ')
		{
			std::vector<int> listDigits;
			int tempLength = strLength;
			for (int i = charIdx + 1; i < tempLength; i++)
			{
				if (str[i] == ' ')
				{
					break;
				}
				else if (isdigit(str[i]))
				{
					listDigits.push_back(atoi(&str[i]));
				}
			}
			for (int digitGot : listDigits)
			{
				totalResult += digitGot;
			}
		}
	}
	return totalResult;
}

int main(int argc, char** argv)
{
	std::cout << exercice1("allo") << std::endl;
	std::cout << exercice2("hello world") << std::endl;
	std::cout << exercice3("Bonjour tout le monde.") << std::endl;
	std::cout << exercice4("radar") << std::endl;
	std::cout << exercice5("Bonjour 10 et 20") << std::endl;
}
