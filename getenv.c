#include "shell.h"

/**
 
_getenv - find path in environ
@name: path name
Description: getenv parcours environ pour trouver la ligne PATH
et plus tard en faire une copie pour l'utiliser. 
Return: Path line*/
char get_env(charname)
{
    int i = 0;
    int nl;

    if (name == NULL || name[0] == '\0')
        return (NULL);

    nl = strlen(name);

    while (environ && environ[i])
    {
        if (_strncmp(environ[i], name, nl) == 0 && environ[i][nl] == '=')
            return (environ[i]);
        i++;
    }
    return (NULL);
}
