/**
 * _strcmp - compares two strings.
 * @s1: a pointer to the 1st string.
 * @s2: a pointer to the 2nd string.
 *
 * Return: 0 if they are the same
 * +ve if s1 > s2
 * -ve if si < s2
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
