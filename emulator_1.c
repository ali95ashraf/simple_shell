#include "shell.h"

/**
 * terminateShell - Function to terminate the shell
 * @info: This is a structure that contains potential arguments.
 * It is used to keep the function prototype consistent.
 *  Return: The function terminates with an exit status.
 *           It exits with status (0) if info.argv[0] != "exit"
 */
int terminateShell(info_t *info)
{
	int checkToExit;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		checkToExit = parseToInt(info->argv[1]);
		if (checkToExit == -1)
		{
			info->status = 2;
			print_error(info, "Number not supported: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = parseToInt(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * changeDirectory - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int changeDirectory(info_t *info)
{
	char *stringVar, *dir, buffer[1024];
	int chdirRet;

	stringVar = getcwd(buffer, 1024);
	if (!stringVar)
		_puts(">>failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = retrieveEnvValue(info, "HOME=");
		if (!dir)
			chdirRet =
				chdir((dir = retrieveEnvValue(info, "PWD=")) ? dir : "/");
		else
			chdirRet = chdir(dir);
	}
	else if (lexicographicComparison(info->argv[1], "-") == 0)
	{
		if (!retrieveEnvValue(info, "OLDPWD="))
		{
			_puts(stringVar);
			_putchar('\n');
			return (1);
		}
		_puts(retrieveEnvValue(info, "OLDPWD=")), _putchar('\n');
		chdirRet =
			chdir((dir = retrieveEnvValue(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdirRet = chdir(info->argv[1]);
	if (chdirRet == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", retrieveEnvValue(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * setCurrentDirectory - modifies the present directory of the process
 * @info: Structure that holds possible arguments. It helps in keeping
 *          the function prototype consistent.
 *  Return: Consistently 0.
 */
int setCurrentDirectory(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Could not be implemented - sad face : ( \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
