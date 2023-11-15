/**
 * _strncmp - compares two strings.
 * @s1: a pointer to the 1st string.
 * @s2: a pointer to the 2nd string.
 * @n: number of characters to be compared.
 *
 * Return: 0 if they are the same in the nth
 * +ve if s1 > s2
 * -ve if s1 < s2
 *
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
