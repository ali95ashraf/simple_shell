#include "shell.h"

/**
 * determineLength - returns the length of a string
 * @string: the string whose length to check
 *
 * Return: length of string
 */
int determineLength(char *string)
{
	int i = 0;

	if (!string)
		return (0);

	while (*string++)
		i++;
	return (i);
}

/**
 * lexicographicComparison - performs lexicogarphic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: positive if s1 > s2, negative if s1 < s2, zero if s1 == s2
 */
int lexicographicComparison(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * startsWithSubstring - verifies if needle is at the beginning of haystack
 * @haystack: the string to look in
 * @needle:   the subsequence to look for
 *
 * Return: location of the next character in haystack or NULL
 */
char *startsWithSubstring(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * combineStrings - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *combineStrings(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
