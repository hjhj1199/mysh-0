#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  chdir(argv[1]);
  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv) {
  char location[8096];
  if (!validate_pwd_argv(argc, argv))
    return -1;
  getcwd(location,8096);
  
  printf("%s\n",location);
  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  struct stat dir;
 
  if (argc==2 && strcmp(argv[0],"cd")==0 && access(argv[1],F_OK | R_OK)==0 && stat(argv[1],&dir)==0 && S_ISDIR(dir.st_mode)==1) return 1;

  return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if (argc==1 && strcmp(argv[0],"pwd")==0) return 1;
  // TODO: Fill it!
  return 0;
}
