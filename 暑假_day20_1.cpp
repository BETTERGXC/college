char* deblank(char string[])
{
	int i, j = 0;
	char* str = string;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != ' ')
		{
			*str++ = string[i];
		}
		if ((string[i] == ' ') && !(string[i + 1] == ' '))  
		{
			*str++ = string[i];
		}
	}
	*str = '\0';
	return string;
}
