/*
    AnbUI Miniature Text UI Lib for Burger Enjoyers(tm)

    ad_test: AnbUI Example Test Application

    Tip of the day: Cheese burgers and bacon burgers are like ying and yang
    except you get to enjoy the ying and yang with cheese and bacon without
    having to compromise on the other.

    (C) 2024 E. Voirin (oerg866) */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "anbui.h"

void sleep(double seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + (seconds * CLOCKS_PER_SEC));
}

int main(int argc, char *argv[]) {
    ad_Menu        *menu = NULL;
    ad_ProgressBox *prog = NULL;
    size_t          i;

    (void) argc;
    (void) argv;

    ad_init("AnbUI Super Burger Edition - The Test Application(tm)");

    ad_yesNoBox("Burger Selection", true,
        "Do you want cheese on burger cheese taste on you?\n"
        "Refer to Anby Demara's Burger Handbook for more\n"
        "information.");

    ad_okBox("Another Burger Selection", true, "Cheese is taste on burger cheese on you.");

    ad_runCommandBox("Updating my burger to have burger cheese on burger", "apt update 2>&1");

    /* Test Text File Box */

    ad_textFileBox("demara.txt", "demara.txt");

    menu = ad_menuCreate("Selector of death",
        "Select your favorite philosophy:\n"
        "Please note that your burgering is dependent\n"
        "on taste of burger cheese on you.",
        true);

    for (i = 0; i < 10; i++) {
        ad_menuAddItemFormatted(menu, "Item %zu: Burger Cheese is Cheese on Burger", i);
    }

    ad_menuAddItemFormatted(menu, "Item 9000: All the cheesing of burger taste on you. LONG SCHLONG 1231445982139582092385092830");

    ad_menuExecute(menu);
    ad_menuDestroy(menu);

    /* Test Progress Box */
    prog = ad_progressBoxCreate("Vorwaerts immer, Rueckwaerts nimmer",
        "Please wait while we burger your cheese.\n"
        "Also: Burgering can not be tasted.",
        10);

    for (i = 0; i <= 10; i++) {
        ad_progressBoxUpdate(prog, i);
        sleep(0.1);
    }

    ad_progressBoxDestroy(prog);

    ad_deinit();

    return 0;
}
