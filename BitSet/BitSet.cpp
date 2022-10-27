// BitSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <string_view>
#include <numeric>
#include <limits>

using std::vector;
using namespace  std;


//Lesson 1 
std::string IntToBin(int value)
{
	return std::bitset<32>(value).to_string();
}

int DetectGap(std::string binaryValue)
{
	//std::bitset<8> binaryValue(32);

	int gapValue{ 0 };
	bool checking = false;
	int maxValue = 0;
	//std::string val = binaryValue.to_string();

	for (size_t i = binaryValue.find('1'); i < binaryValue.size(); i++)
	{
		if (!checking)
		{
			if (binaryValue.at(i) == '1')
			{
				checking = true;
			}

		}
		else
		{
			if (binaryValue.at(i) == '1')
			{
				//checking = false;
				if (gapValue >= maxValue)
				{
					maxValue = gapValue;
				}
				gapValue = 0;
			}
			else
			{
				gapValue++;
			}


		}
	}
return maxValue;
}

int BinaryGap(int N)
{
	return DetectGap(IntToBin(N));
}
//Lesson 2

void CyclicRotation(vector<int>& A, int K)
{
	//On doit déplacer A K fois
	//if (K == 0) return A;
	//if (K == A.size()) return A;

	for (size_t i = 0; i < K; i++)
	{
		A.insert(A.begin(), A.back());
		A.pop_back();
	}
	A.resize(A.size());

	/*

	for (size_t i =0; i < K; i++)
	{
		int lastVal = A.back();

		for (size_t i = 1; i < A.size(); i++)
		{
			A.at(i) = A.at(i - 1);
		}
		A.at(0) = lastVal;
	}

	*/
}


int OddOccurencesInArray(vector<int>& A)
{
	if (A.size() <= 0) return A.at(0);
	//quickSort(A, 0, A.size() - 1);
	std::sort(A.begin(), A.end());

	for (size_t i = 0; i < A.size() - 1; i += 2)
	{
		cout << endl;
		if (i == A.size() - 1)
		{
			cout << A.at(i) << endl;
			return A.at(i);
		}

		if (A.at(i) != A.at(i + 1))
		{
			cout << A.at(i) << endl;
			return A.at(i);
		}
	}
}

//Lesson 3
int FrogJmp(int X, int Y, int D) {
	float result{ 0 };
	if (X >= Y) return 0;

	float reste = (Y - X) % (D);
	if (reste != 0)
	{
		return ((Y - X) / D) + 1;
	}
	else
	{
		return (Y - X) / D;

	}
}

int PermMissingElem(vector<int>& A)
{
	if (A.size() == 0) return 1;

	sort(A.begin(), A.end());

	if (A.at(0) != 1) return 1;

	for (size_t i = 0; i < A.size() - 1; i++)
	{
		if (A.at(i + 1) != A.at(i) + 1)
		{
			return A.at(i) + 1;
		}
	}
	if (A.size() == 1) return A.back() + 1;
	return A.back() + 1;
}

int TapeEquilibrium(vector<int>& A)
{
	//But trouver quel est laplus petite différence
	int jMax = 0;
	int kMax = 0;
	//set<int> minValue;

	int minval = numeric_limits<float>::infinity();


	for (size_t i = 1; i < A.size(); i++)
	{
		/*
		//jMax = 0;
		//kMax = 0;
		

		for (size_t j = 0; j < i; j++)
		{
			jMax += A.at(j);
		}
		for (size_t k = i; k < A.size(); k++)
		{
			kMax += A.at(k);

		}*/

		
		jMax = accumulate(A.begin(), A.end()-i, 0);
		kMax = accumulate(A.end() - i, A.end(), 0);
		
		int val = abs(jMax - kMax);

		if (val == 0) return 0;

		if (val < minval)
		{
			minval = val;
		}
		//minValue.insert(abs(jMax - kMax));

		
	}
	//return *minValue.begin();
	return minval;
}

int main()
{
	vector<int> vals{ 3,1,2,4,3 };
	int x = 10;
	int y = 85;
	int d = 30;

	cout << endl << TapeEquilibrium(vals) << endl;

	//std::cout << DetectGap(IntToBin(145));

	//std::set<int> set(vals.begin(), vals.end());
	
}
