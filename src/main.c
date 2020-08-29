#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/cliargs.h"

int main(int argc, char **argv)
{
  if(argc < 2)
  {
  		autoDetect();
  }
  int opt;
  int hflag = 0;
  int tflag = 0;
  int rflag = 0;
  int aflag = 0;
  int vflag = 0;

  const char *const shortOpts = "hav";
  const struct option longOpts[] = {
    {"help", no_argument, NULL, 'n'},
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
      rflag++;
      aflag++;
      vflag++;
      help();
      break;
    case 'a':
      if (aflag)
 		break;
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      autoDetect();
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
	  autoDetect();
	  break;
    }
  }
}
