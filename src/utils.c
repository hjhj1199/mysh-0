#include <string.h>
#include <stdlib.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
    char usercommand[8096],*token=NULL;
    int cnt=0;

    strcpy(usercommand,command);
  
    *argv=(char**)malloc(4*sizeof(char));

    token=strtok(usercommand," \n\t");

    do
    {
        *(*argv+cnt)=(char*)malloc(strlen(token+1)*sizeof(char));
        strcpy(*(*argv+cnt),token);
        cnt++;
        token=strtok(NULL," \n\t");
        if (token==NULL) break;
    }while(1);
    
    *argc=cnt;
}
