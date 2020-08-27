#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/cliargs.h"

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    help();
  }
  int opt;
  int hflag = 0;
  int tflag = 0;
  int rflag = 0;
  int aflag = 0;
  int vflag = 0;
  char name[64] = "";

  const char *const shortOpts = "hnt:rav";
  const struct option longOpts[] = {
    {"help", no_argument, NULL, 'n'},
	{"name", required_argument, NULL, 'n'},
    {"temp", required_argument, NULL, 't'},
    {"reset", no_argument, NULL, 'r'},
    {"auto", no_argument, NULL, 'a'},
    {"version", no_argument, NULL, 'v'},
    {NULL, no_argument, NULL, 0}
  };
  
  while ((opt = getopt_long(argc, argv, shortOpts, longOpts, NULL)) != -1)
  {
    switch (opt)
    {
    case 'h':
      if (hflag)
		break;
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      help();
      break;
    case 'n':
	  if(hflag)
		break;
	  strncpy(name, argv[2], 64);
	  printf("%s", name);
	  break;

    case 't':
      if (tflag)
      {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      setTemp(atoi(optarg), name);
      break;
    case 'r':
      if (rflag)
      {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      reset(name);
      break;
    case 'a':
      if (aflag)
      {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      autoDetect(name);
      break;
    case 'v':
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      printf("KShift Version: %s\n", Version());
      break;
	    default:
      help();
      break;
    }
  }
}
