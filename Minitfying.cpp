string Minifying(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='\n' || s[i]==' ')
		{
			s.erase(i,1);
			i--;
		}
	}

	return s;
}
