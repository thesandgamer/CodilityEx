// BitSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <set>
#include <bitset>
#include <string>
#include <vector>

using std::vector;


int DetectGap(std::string binaryValue)
{
	//std::bitset<8> binaryValue(32);

	int gapValue {0};
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


std::string IntToBin(int value)
{
	return std::bitset<32>(value).to_string();
}


void Shift(vector<int>& A, int K)
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

int main()
{
	//std::cout << DetectGap(IntToBin(145));
	vector<int> vals{ 9,3,9,3,9,7,9 };

	//std::set<int> set(vals.begin(), vals.end());
	// Sort et si après et avant pas pareil c'est solo
	
}
