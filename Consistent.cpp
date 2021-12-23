#include "Consistent.h"

string detection=" ";//This string is for detecting the opening or closing tags which have errors
string Consistent(string s)
{
	string y,z,found,r;
	stack<string>check;
	int tempvar,i;
	bool isfound;

	for(i=0;i<s.length();i++) // Looping on the whole string xml
	{
		if(s[i]=='<' && s[i+1] !='/') // Finding the opening tags to push them into the stack
		{
			i++;
			while(s[i]!='>')
			{
				y+=s[i++];
			}
			check.push(y);
			y.erase(0);
		}
		else if(s[i]=='<' && s[i+1]=='/') // Finding the closing tags to pop their openings from the stack
		{
			tempvar=i;
			i+=2;
			while(s[i]!='>')
			{
				z+=s[i++];
			}

			if(z==check.top()) // In case of finding the correct closing tag for its opening tag
			{
				check.pop();
				z.erase(0);
			}
			else // In case of finding a wrong closing tag
			{
				isfound=false;
				stack<string>temp;    // A temporary stack to show all of the search in the original stack
				while(!check.empty()) // This loop is here as the opening tag may not be at the stack top
				{
					found=check.top();
					if(z==found){
						isfound=true;
					}
					temp.push(check.top());
					check.pop();
				}
				while(!temp.empty())  // Returning the elements to its main stack
				{
					check.push(temp.top());
					temp.pop();
				}
				if(isfound)  // In case that the error was because of a missing closing tag
				{
					while(z!=check.top())
					{
						detection.append("The closing tag </"+check.top()+"> "+"was missing"); //This string is for detecting the closing tags which have errors
						//cout<<"The closing tag </"<<check.top()<<"> "<<"was missing"<<endl;
						s.insert(tempvar,"</"+check.top()+">");
						check.pop();
					}
					check.pop();
					z.erase(0);
				}
				else  // In case that the error was because of a missing opening tag
				{
					detection.append("The opening tag <"+z+"> "+"was missing");//This string is for detecting the opening tags which have errors
					//cout<<"The opening tag <"<<z<<"> "<<"was missing"<<endl;
					while(s[tempvar]!='>')
						tempvar--;  // Trying to find the right place of this tag
					s.insert(tempvar+1,"<"+z+">");
					z.erase(0);
				}
			}
		}
	}

	//In case the stack wasn't empty, there must be an error

	while(!check.empty())
	{
		detection.append("The closing tag </"+check.top()+"> "+"was missing");
		//cout<<"The closing tag </"<<check.top()<<"> "<<"was missing"<<endl;
		s.append("</"+check.top()+">");
		check.pop();
	}

	return s;
}
