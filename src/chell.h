#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h> 
#include "chellin.h"

#define VERSION 0.05
#define SHELL_NAME "Chell"
#define ARG_MAX sysconf(_SC_ARG_MAX)

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


struct executable
{
    char name[NAME_MAX + 1];
    char path[PATH_MAX + 1];
};

int getPATHLocationCount(char *PATH);
void getPATHLocations(char *directories[], char *PATH);

int nExecutables = 0;
struct executable *getFilesFromDirectories(char **dir, int numberOfDirectory);


void initPrompt();

int splitString(char *split[], char *string, char *delim);
int splitCommand(char *argv[], char *command);

void executeCommand(char *commandString, struct executable *executables);

void cd(char *path);

void sigintHandler(int signal_number);

char isWhiteSpaces(char *str);