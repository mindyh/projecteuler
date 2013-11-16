#include<math.h>
#include<vector>
#include<string.h>
#include <algorithm> 
#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;

// problem 3
// O(n^2)
long long largest_prime_factor(long long input)
{
	long long curr_factor = 2;
	long long largest_factor = curr_factor;
	vector<long long> primes;
	primes.push_back(2);
	while(input != 1)
	{
		vector<long long>::iterator it;
		it = find(primes.begin(), primes.end(), curr_factor);

		bool isPrime = true;
		if(it == primes.end()) // not already in the primes list
		{
			// check if it's a prime number
			for(unsigned int i = 0; i < primes.size(); i++)
			{
				if(curr_factor % primes[i] == 0)
				{
					isPrime = false;
					break;
				}
			}

			if(isPrime)
				primes.push_back(curr_factor);
		}
		
		//check if prime factor of number
		if(isPrime && (input % curr_factor) == 0)
		{
			cout << curr_factor << endl;
			largest_factor = curr_factor;
			while(input % curr_factor == 0)
				input /= curr_factor;
		}

		curr_factor++;
	}

	return largest_factor;
}

// Problem 4
string itostr(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}

bool isPalindrome(int num)
{
	string numStr  = itostr(num);
	int strSize = numStr.size();
	for(int i = 0; i < strSize/2; i++)
		if(numStr[i] != numStr[strSize - i - 1])
			return false;

	return true;
}


// O(n^2)
int largestPalindromeProduct()
{
	int x = 100;
	int retval = 0;
	while (x < 1000)
	{
		int y = 100;
		while(y < 1000)
		{
			int z = x*y;
			if (z > retval && isPalindrome(z))
				retval = z;		

			y++;
		}
		x++;
	}

	return retval;
}


// Problem 15 
/* given an n by n lattice, how many paths are possible 
   from the top left corner to the bottom right?
*/
int latticeHelper(int x, int y, int n)
{
	int numPaths = 0;

	if(x == n && y == n)
	{
		return 1;
	}

	if(x < n)
		numPaths += latticeHelper(x+1, y, n);

	if(y < n)
		numPaths += latticeHelper(x, y+1, n);

	return numPaths;
}

int LatticePaths(int n)
{
	return latticeHelper(0, 0, n);
}


int main()
{
	// problem 3
	/*
	long long input = 0;
	cout << "please input a number: " << endl;
	cin >> input;
	cout << largest_prime_factor(input) << endl;*/
	
	// problem 4
	// cout << "largest palindrome " << largestPalindromeProduct() << endl;

	// Problem 5 
	cout << "lattice paths: " << LatticePaths(20) << endl;
	string c = "";
	c += "a";
	cout << c

	/* prevent window from closing */
	cout << "done" << endl; 
	int c; 
	cin >> c;
	return 0;
}
