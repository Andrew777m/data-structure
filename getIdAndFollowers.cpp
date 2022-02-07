#include <string>
#include <stack>
#include <vector>
#include "getIdAndFollowers.h"
string getIdAndFollowers(string s)
{
	int counter=0;
	string IdAndFollowers;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='<' && s[i+1]=='i' && s[i+2]=='d' && s[i+3]=='>')
		{
			IdAndFollowers.push_back(s[i+4]);
			IdAndFollowers.push_back(32);
			if(counter==0)
			{
				IdAndFollowers+=" -> ";
				IdAndFollowers+="{ " ;
				counter=1;
			}
		}
		else if(s[i]=='<' && s[i+1] == '/' && s[i+2] == 'u' && s[i+3] == 's' && s[i+4] == 'e' && s[i+5] == 'r' && s[i+6]=='>')
		{
			counter=0;
			IdAndFollowers+="}" ;
			IdAndFollowers.push_back(10);
		}
	}
	return IdAndFollowers;
}
