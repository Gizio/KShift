

#ifndef CLI_ARGS
#define CLI_ARGS

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct Gamma
{
	char K25K[1024];
	char K3K[1024];
	char K35K[1024];
	char K4K[1024];
	char K45K[1024];
	char K5K[1024];
	char K55K[1024];
	char K6K[1024];
	char K65K[1024];
};

void help();
void setTemp(int temp);
void reset();
void autoDetect();
char *Version();

void help()
{
	printf("\nHelp:\n\nKShift -h | KShift --help\tDisplays help\nKShift -t | "
				 "KShift --temp\tShifts monitor temp (REQUIRES ARGUMENT)\nKShift -r | "
				 "KShift --reset\tResets monitor temp\nKShift -a | KShift "
				 "--auto\tAutomatically sets temperature\n\nType \"man KShift\" into "
				 "terminal for more information\n\n");
}

void setTemp(int temp)
{
	struct Gamma gamma;
	strcpy(gamma.K25K, "1.00000000:0.64373109:0.28819679\0");
	strcpy(gamma.K3K, "1.00000000:0.71976951:0.42860152\0");
	strcpy(gamma.K35K, "1.00000000:0.77987699:0.54642268\0");
	strcpy(gamma.K4K, "1.00000000:0.82854786:0.64816570\0");
	strcpy(gamma.K45K, "1.00000000:0.86860704:0.73688797\0");
	strcpy(gamma.K5K, "1.00000000:0.90198230:0.81465502\0");
	strcpy(gamma.K55K, "1.00000000:0.93853986:0.88130458\0");
	strcpy(gamma.K6K, "1.00000000:0.97107439:0.94305985\0");

	char xrandr[1024] = "xrandr --output eDP-1 --gamma ";

	if (temp > 6500)
	{
		printf("ERROR: You cannot go above 6500K\n");
		return;
	}
	else if (temp < 2500)
	{
		printf("Values must be above 2000\n");
	}
	else if (temp % 500 != 0)
	{
		printf("ERROR: Value must be divisible by 500\n");
		return;
	}

	// The following code is an affront to god.
	switch (temp)
	{
	case 2500:
		printf("%d", temp);
		strcat(xrandr, gamma.K25K);
		break;
	case 3000:
		strcat(xrandr, gamma.K3K);
		break;
	case 3500:
		strcat(xrandr, gamma.K35K);
		break;
	case 4000:
		strcat(xrandr, gamma.K4K);
		break;
	case 4500:
		strcat(xrandr, gamma.K45K);
		break;
	case 5000:
		strcat(xrandr, gamma.K5K);
		break;
	case 5500:
		strcat(xrandr, gamma.K55K);
		break;
	case 6000:
		strcat(xrandr, gamma.K6K);
		break;
	case 6500:
		reset();
	default:
		return;
	}
	system(xrandr);
}

void reset() { system("xrandr --output eDP-1 --gamma 1:1:1"); }

void autoDetect()
{

	struct Gamma gamma;
	strcpy(gamma.K25K, "1.00000000:0.64373109:0.28819679\0");
	strcpy(gamma.K3K, "1.00000000:0.71976951:0.42860152\0");
	strcpy(gamma.K35K, "1.00000000:0.77987699:0.54642268\0");
	strcpy(gamma.K4K, "1.00000000:0.82854786:0.64816570\0");
	strcpy(gamma.K45K, "1.00000000:0.86860704:0.73688797\0");
	strcpy(gamma.K5K, "1.00000000:0.90198230:0.81465502\0");
	strcpy(gamma.K55K, "1.00000000:0.93853986:0.88130458\0");
	strcpy(gamma.K6K, "1.00000000:0.97107439:0.94305985\0");
	strcpy(gamma.K65K, "1:1:1\0");

	time_t now;
	struct tm *now_tm;
	int hour;
	while (1)
	{
		char xrandr[1024] = "xrandr --output eDP-1 --gamma ";
		now = time(NULL);
		now_tm = localtime(&now);
		hour = now_tm->tm_hour;

		switch (hour)
		{
		case 18:
			strcat(xrandr, gamma.K55K);
			break;
		case 19:
			strcat(xrandr, gamma.K5K);
			break;
		case 20:
			strcat(xrandr, gamma.K45K);
			break;
		case 21:
			strcat(xrandr, gamma.K4K);
			break;
		case 22:
			strcat(xrandr, gamma.K35K);
			break;
		case 23:
			strcat(xrandr, gamma.K3K);
			break;
		case 00:
			strcat(xrandr, gamma.K25K);
			break;
		default:
			strcat(xrandr, gamma.K65K);
			break;
		}
		system(xrandr);
	}
}

char *Version()
{
	char *version = malloc(5 * sizeof(char));
	version = "0.3.1a";
	return version;
}
#endif