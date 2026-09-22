
#pragma once
#include <time.h>
#include <string>
#include <cctype>
#include <iostream>
#include<vector>

using namespace std;


class clsstring
{

private:
	string _Value;



public:

	void Setstring(string s1) {

		_Value = s1;
	}

	string Getstring() {
		return _Value;
	}

	__declspec(property(get = Getstring, put = Setstring)) string String;

	// print the first letter in the word 

	static char  Firstletter(string name) {

		bool isfisrtletter = true;
		for (int i = 0; i < name.length(); i++)
		{

			if (name[i] != ' ' && isfisrtletter) {
				return name[i];
			}
			isfisrtletter = (name[i] == ' ' ? true : false);
		}
	}

	char Firstletter() {
		return Firstletter(_Value);
	}

	// get the length of word  

	static int Length(string s1) {
		return s1.length();
	}

	int Length() {
		return  Length(_Value);
	}

	// capitalize  the first letter each word int the sentance 

	static string ToTitleCase(string name) {

		bool isfirstletter = true;

		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] != ' ' && isfirstletter)
			{
				name[i] = toupper(name[i]);
			}

			isfirstletter = (name[i] == ' ') ? true : false;
		}
		return name;
	}

	string  ToTitleCase() {
		return ToTitleCase(_Value);
	}

	// lower the first letter each word int the sentance 

	static string LowercaseEachWord(string s) {

		bool isfirstleeter = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isfirstleeter)
			{
				s[i] = tolower(s[i]);
			}
			isfirstleeter = (s[i] == ' ') ? true : false;
		}
		return s;
	}

	string LowercaseEachWord() {
		return LowercaseEachWord(_Value);
	}

	// UPPER STRING

	static string UpperString(string s) {

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = toupper(s[i]);
		}

		return s;
	}

	string UpperString() {
		return  UpperString(_Value);
	}

	// LOwer  STRING

	static string LowerString(string s) {

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}

		return s;
	}

	string LowerString() {
		return  LowerString(_Value);
	}

	// Invert Charachter Case

	static char InvertLetter(char s) {

		return (isupper(s) ? tolower(s) : toupper(s));

	}

	static string InvertAllLettersCase(string s) {

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = clsstring::InvertLetter(s[i]);
		}
		return s;
	}

	string InvertAllLettersCase() {

		return InvertAllLettersCase(_Value);
	}

	// Count the Capital Letter In The Sentance 

	static int CountCapitalLetter(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (isupper(s[i]))
				counter++;
		}
		return counter;
	}

	int CountCapitalLetter() {
		return CountCapitalLetter(_Value);
	}

	// Count the Capital Letter In The Sentance 

	static int CountLowerLetter(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (islower(s[i]))
				counter++;
		}
		return counter;
	}

	int  CountLowerLetter() {
		return  CountLowerLetter(_Value);
	}

	// count the number of same letter int the sentance 

	static int CountLetterInSentance(string s, char input)
	{
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (input == s[i])
			{
				counter++;
			}
		}
		return counter;
	}

	int CountLetterInSentance(char input) {
		return CountLetterInSentance(_Value, input);
	}

	//  the occurrences of a specific character. 

	static int CountCharOccurrences(string s, char input, bool matchcase = true) {

		int  counter = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (matchcase) {
				if (input == s[i])
				{
					counter++;

				}
			}
			else
			{
				if (tolower(input) == tolower(s[i]))
				{
					counter++;

				}
			}
		}
		return counter;
	}

	int CountCharOccurrences(char input) {
		return CountCharOccurrences(_Value, input);
	}

	// count vowel letter int the sentance 

	static bool IsVowel(char c) {

		c = tolower(c);
		return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));

	}

	static	 int CountVowels(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (IsVowel(s[i])) {
				counter++;
			}
		}
		return counter;
	}

	int CountVowels() {
		return CountVowels(_Value);
	}

	// print all vowels in sentance

	static void PrintAllVowel(string s) {

		for (int i = 0; i < s.length(); i++)
		{
			if (IsVowel(s[i])) {
				cout << s[i] << "  ";
			}
		}

	}

	void PrintAllVowel() {
		return PrintAllVowel(_Value);
	}

	// print each word in the setance  

	static void PrintEachWord(string s) {

		string delim = " ";
		cout << "\n your string words  are : \n\n";
		short pos = 0;
		string sword;

		while ((pos = s.find(delim)) != std::string::npos)
		{
			sword = s.substr(0, pos);
			if (sword != "") {
				cout << sword << endl;
			}

			s.erase(0, pos + delim.length());
		}

		if (s != "") {

			cout << s << endl;
		}
	}

	void PrintEachWord() {
		return PrintEachWord(_Value);
	}

	// count word int the sentance 

	static int CountWord(string s1, string delim) {
		short pos = 0;
		string word = "";
		int counter = 0;
		pos = s1.find(delim);
		while (pos != string::npos)
		{
			word = s1.substr(0, pos);
			if (!word.empty()) {
				counter++;
			}
			s1.erase(0, pos + delim.length());
			pos = s1.find(delim);
		}
		if (!s1.empty()) {
			counter++;
		}
		return counter++;
	}

	int CountWord(string delim) {
		return CountWord(_Value, delim);
	}

	// splite string 

	static vector<string> Splite(string s1, string delim) {
		short pos = 0;
		string word = "";
		int counter = 0;
		vector<string> vstring;
		pos = s1.find(delim);
		while (pos != string::npos)
		{
			word = s1.substr(0, pos);
			if (!word.empty()) {
				vstring.push_back(word);
			}
			s1.erase(0, pos + delim.length());
			pos = s1.find(delim);
		}
		if (!s1.empty()) {
			vstring.push_back(s1);
		}
		return vstring;
	}

	vector<string> Splite(string delim) {

		return Splite(_Value, delim);
	}

	// trim 

	static string TrimLeft(string S1)
	{
		for (int i = 0;i < S1.length();i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return S1;
	}

	string TrimLeft() {
		return TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (int i = S1.length() - 1;i >= 0;i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return S1;
	}

	string TrimRight() {
		return  TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}

	string Trim() {
		return  Trim(_Value);
	}

	// join string 

	static string JoinString(vector <string> vSplit, string delim)
	{
		string S1 = "";
		for (string& s : vSplit)
		{
			S1 = S1 + s + delim;
		}

		return S1.substr(0, S1.length() - delim.length());
	}

	static string JoinString(string arr[], short length, string delim)
	{
		string S1 = "";

		for (int i = 0;i < length;i++)
		{
			S1 = S1 + arr[i] + delim;
		}

		return S1.substr(0, S1.length() - delim.length());
	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Splite(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Splite(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerString(s) == LowerString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}
	}
};



