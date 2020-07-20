#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/cliargs.h"

int main(int argc, char **argv) {
  
  if (argc < 2) {
    help();
  }
  int opt;
  int hflag = 0;
  int tflag = 0;
  int rflag = 0;
  int aflag = 0;
  int vflag = 0;
  while ((opt = getopt(argc, argv, "ht:rav")) != -1) {
    switch (opt) {
    case 'h':
      if (hflag) {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      help();
      break;
    case 't':
      if (tflag) {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      setTemp(atoi(optarg));
      break;
    case 'r':
      if (rflag) {
        break;
      }
      hflag++;
      tflag++;
      rflag++;
      aflag++;
      vflag++;
      reset();
      break;
    case 'a':
      if (aflag) {
        break;
      }
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
      printf("KShift Version: 0.2.0a (2020-7-2020)\n", Version());
      break;
    default:
      help();
      break;
    }
  }
}
