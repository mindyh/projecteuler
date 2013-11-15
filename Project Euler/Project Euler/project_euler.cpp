#include<math.h>
#include<vector>
#include<string.h>
#include <algorithm> 
#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;

// problem 3
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
		if(numStr[i] != numStr[strSize - i])
			return false;

	return true;
}

int largestPalindromeProduct()
{
	int x = 10;
	int y = 10;
	int retval = 0;
	while (x < 100)
	{
		while(y < 100)
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



int main()
{
	// problem 3
	/*
	long long input = 0;
	cout << "please input a number: " << endl;
	cin >> input;
	cout << largest_prime_factor(input) << endl;*/
	

	cout << "largest palindrome " << largestPalindromeProduct() << endl;

	cout << "done" << endl; 
	int c; 
	cin >> c;
	return 0;
}
