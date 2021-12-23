#include "xml.h"
#include <vector>
#include <string>
#include <stack>
using namespace std;
string spaces(int num_space)
{
	string numofspace;
	for (int i = 0; i < num_space; i++)
	{
		numofspace += " ";
	}

	return numofspace;
}



void xml_to_json(vector<string>& XML, vector<string>& JASON, unsigned int & size)
{
	string txt;
	string pre;
	string te;
	string t;
	
	bool empty = false;

	stack <int> W_LENGTH;
	stack <string> st;

	int start, end, another_e;
	int INDEX = 1;

	JASON[0] = "{";
	int i1 = 0;
	while (i1 < size) {

		te = XML[i1];

		if ((te == "") || (((te[1] == '?') || (te[1] == '!')) && te[0] == '<') || ((te.find("<") == -1) && (te.find(">") != -1)) || ((te.find(">") == -1) && (te.find("<") != -1)))
		{
			continue;
		}


		start = te.find("<") + 1;
		end = te.find(">");
		if (start == 0 && end == -1)
		{
			if (empty == true)
				JASON[INDEX] = spaces(W_LENGTH.top()) + te;

			else
				continue;

		}
		else if (te[start] == '/')
		{
			t = te.substr(start + 1, end - (start + 1));
			pre = t;

			JASON[INDEX] = spaces(W_LENGTH.top()) + "}";
			st.pop();
			W_LENGTH.pop();
		}

		else
		{
			another_e = te.find(" ");
			if (another_e > start && another_e < end)
				t = te.substr(start, another_e - start);

			else
				t = te.substr(start, end - start);


			st.push(t);
			empty = true;

			if (t != pre)
				JASON[INDEX] = "'" + t + "'" + ":" + "{";

			else
				JASON[INDEX] = spaces(W_LENGTH.top() - 2) + ", {";


			W_LENGTH.push(JASON[INDEX].length());
		}

		INDEX++;
		i1++;
	}

	JASON[INDEX++] = "}";
	for (int i = 0; i < INDEX; i++) {
		cout << JASON[i] << endl;
	}
}
void PARSE(string FILE, vector<string>& XML, unsigned int& SIZE_OF_XML)
{
	int STR_S;
	int STR_end;
	int INDEX = 0;
	XML.reserve(10000);
	long long vector_capacity = 10000;
	while (FILE[INDEX] != '\0')
	{
		string line = "";

		while ((FILE[INDEX] == ' ') && (FILE[INDEX] == '\n'))
		{
			INDEX++;
		}

		if (FILE[INDEX] == '<')
		{
			STR_S = INDEX;
			STR_end = INDEX + 1;
			while (FILE[STR_end] != '>' && FILE[STR_end] != '\0')
			{
				STR_end++;
			}
			if (FILE[STR_end] == '\0')
			{
				break;
			}
		}
		else 
		{
			STR_S = INDEX;
			STR_end = INDEX + 1;
			while (FILE[STR_end] != '<' && FILE[STR_end] != '\0' && FILE[STR_end] != '\n')
			{
				STR_end++;
			}
			STR_end--; 
			if (FILE[STR_end] == '\0')
			{
				break;
			}
		}

		if (FILE[INDEX] == '\n') { INDEX++; continue; }
		INDEX = STR_end + 1;
		XML.push_back(FILE.substr(STR_S, STR_end - STR_S + 1));
		SIZE_OF_XML++;
		if (SIZE_OF_XML + 20 > vector_capacity)
		{
			XML.reserve(vector_capacity + 10000);
			vector_capacity = vector_capacity + 10000;
		}
	}
}
