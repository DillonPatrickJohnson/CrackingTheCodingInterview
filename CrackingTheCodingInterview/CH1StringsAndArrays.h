#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using std::string;
using std::cout;
using std::ostream;
using std::endl;

/*	1.3 -	URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string
			has sufficient space at the end to hold the additional characters, and that you are given the "true"
			length of the string. (Note: If implementing in Java, please use a character array so that you can
			perform this operation in place.)
			EXAMPLE:
			Input: "Mr John Smith    ", 13
			Output: "Mr%20John%20Smith" */

class URLify
{
public:
	string input1;
	int input2;
	string output;

	URLify(string in1, int in2)
	{
		input1 = in1;
		input2 = in2;
		output;

		for (int i = 0; i < input2; i++)
		{
			if (input1[i] != ' ')
			{
				output += input1[i];
			}
			else
			{
				output += "%20";
				string temp = input1;
				for (int x = i + 2; x < input1.length() - 2; x++)
				{
					temp[x + 2] = input1[x];
				}
			}
		}

		cout << "Answer 1.3: |" << output << "|" << endl;
	}
};

/*	1.4 -	Palindrome Permutation:  Given a string, write a function to check if it is a permutation of a palindrome.
			A palindrome is a word or phrase that is the same forwards and backwards.A permutation
			is a rearrangement of letters.The palindrome does not need to be limited to just dictionary words.
			Example:
			Input: Tact Coa
			Output: True (permutations: "Taco cat", "atco cta", etc.)
			*/

class PalindromePermutation
{
public:
	int frequency[128] = { 0 };
	string s;

	PalindromePermutation(string in)
	{
		s = in;

		for (int i = 0; i < s.length(); i++)
		{
			frequency[s[i]]++;
		}

		//only max one letter can have an odd count
		cout << "Answer 1.4: " << checkPalindrome()<< endl;
	}

	bool checkPalindrome()
	{
		bool checkOdd = false;
		for (int i = 0; i < 128; i++)
		{
			if (i == 32) //skipping space
			{
			}
			else if (frequency[i] % 2 == 1)
			{
				if (checkOdd == true)
				{
					return false;
				}
				else
				{
					checkOdd = true;
				}
			}
		}
		return true;
	}
};

/*	1.5 -	One Away: There are three types of edits that can be performed on strings: insert a character,
			remove a character, or replace a character. Given two strings, write a function to check if they are
			one edit (or zero edits) away.
			Ex:
			pale, ple   -> true
			pales, pale -> true
			pale, bale  -> true
			pale, bake  -> false
*/

class OneAway
{
public:
	string str1;
	string str2;

	OneAway(string s1, string s2)
	{
		str1 = s1;
		str2 = s2;
		cout << "Answer 1.5: " << check() << endl;
	}

	bool check()
	{
		if (str1.length() != str2.length() && str1.length() != str2.length() + 1 && str1.length() != str2.length() - 1)
		{
			return false;	//lengths of the strings must be +/- 1 from eachother
		}
		else
		{
			string temp;
			string temp2;
			if (str1.length() == str2.length())
			{
				return checkReplace(str1, str2);
			}
			else if (str1.length() > str2.length())
			{
				temp = str1;
				temp2 = str2;
				return checkInsertion(str1, str2);
			}
			else
			{
				temp = str2;
				temp2 = str1;
				return checkInsertion(str2, str1);
			}
		}
	}

	bool checkReplace(string temp, string temp2)
	{
		bool check = false;

		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] != temp2[i])
			{
				if (check == true)
				{
					return false;
				}
				else
				{
					check = true;
				}
			}
		}
		return true;
	}

	bool checkInsertion(string temp1, string temp2)
	{
		bool check = false;
		//temp1 is 1 larger than temp2
		for (int i = 0; i < temp1.length(); i++)
		{
			if (temp1[i] != temp2[i] && check == false)
			{
				check = true;
			}
			else if (check == true)
			{
				int j = i - 1;
				if (temp1[i] != temp2[j])
				{
					if (check == true)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

