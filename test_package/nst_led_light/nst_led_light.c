/*
 * This file is part of ledring.
 * Copyright (c) amlogic 2017
 * All rights reserved.
 * author:renjun.xu@amlogic.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

extern int nst_led_init(void);
extern int nst_led_light(int mic_id);
extern int nst_led_release(void);

static const struct option OPTIONS[] =
{
    { "mic_id", required_argument, NULL, 'i' },
    { NULL, 0, NULL, 0 },
};
static void printHelp(const char* s_arg) {
    printf("\n");
    printf("Usage: %s [options...]*\n", s_arg);
    printf("\n");
    printf("Options:\n");
    printf("    -h, --help         show this help.\n");
    printf("    -i, --mic_id       the id of move.     --range[0 ~ 6 of led index]\n");
    printf("\n");
    printf("eg: %s --mic_id=1\n",s_arg);
    printf("\n");
}

int main(int argc,char* argv[]){
    int res=0;
    int arg;
    char mbuf[100];
    int mic_id;

    if (argc < 2) {
        printHelp(argv[0]);
        return -1;
    }

    if ((2 == argc) && ((!strcmp(argv[1],"--help")) || (!strcmp(argv[1],"-h")))) {
        printHelp(argv[0]);
        return -1;
    }

   while ((arg = getopt_long(argc, argv, "", OPTIONS, NULL)) != -1) {
        switch (arg) {
        case 'i': mic_id = atoi(optarg); break;
        case '?':
            sprintf(mbuf,"%d",arg);
            printf("Invalid command argument:%s\n",mbuf);
        return -1;
        }
    }
    res = nst_led_init();
    if (res < 0) {
        printf("nst_led_init err!\n");
        return -1;
    }
    res = nst_led_light(mic_id);
    if (res < 0) {
        printf("ledShow err!\n");
        return -1;
    }
    sleep(10);
    res = nst_led_light(mic_id+2);
    if (res < 0) {
        printf("ledShow err!\n");
        return -1;
    }
    res = nst_led_release();
    if (res < 0) {
        printf("ledRelease err!\n");
        return -1;
    }

    return 0;
}
