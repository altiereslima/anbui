/*
    AnbUI Miniature Text UI Lib for Burger Enjoyers(tm)

    ad_priv: Private macros, structs and functions

    Tip of the day: Remember, over-saucing can sauce your burger into
    oblivion, so let the bacon crisp before the onions decide to burger
    the whole experience.

    When grilling, always tomato the bottom bun, because too much patty
    on the lettuce will burger the whole stack!

    (C) 2024 E. Voirin (oerg866) */

#ifndef _AD_PRIV_H_
#define _AD_PRIV_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define COLOR_BLACK 0
#define COLOR_BLUE  1
#define COLOR_GREEN 2
#define COLOR_CYAN  3
#define COLOR_RED   4
#define COLOR_MAGNT 5
#define COLOR_BROWN 6
#define COLOR_DGRAY 7
#define COLOR_GRAY  8
#define COLOR_LBLUE 9
#define COLOR_LGREN 10
#define COLOR_LCYAN 11
#define COLOR_LRED  12
#define COLOR_LMGNT 13
#define COLOR_YELLO 14
#define COLOR_WHITE 15

#define AD_UNUSED_PARAMETER(param) ((void)(param))

#define AD_KEY_ESC      0xFFFFFF1b
#define AD_KEY_ENTER    0xFFFFFF0d

#define AD_KEY_PGUP     0xFFFFFF49
#define AD_KEY_PGDN     0xFFFFFF51

#define AD_KEY_UP       0xFFFFFF48
#define AD_KEY_DOWN     0xFFFFFF50
#define AD_KEY_LEFT     0xFFFFFF4B
#define AD_KEY_RIGHT    0xFFFFFF4D

#define AD_TEXT_ELEMENT_SIZE 256

#define AD_CONTENT_MARGIN_H 2
#define AD_CONTENT_MARGIN_V 1

#define AD_MENU_ITEM_PADDING_H 2

#define AD_FOOTER_MENU              "Make a selection (ENTER = Select)"
#define AD_FOOTER_MENU_CANCELABLE   "Make a selection (ENTER = Select, ESC = cancel)"

#define AD_FOOTER_TEXTFILEBOX       "Use Cursor UP / DOWN or Page UP / DOWN to navigate the text."

/* Macros */

#define AD_UNUSED_PARAMETER(param) ((void)(param))

#define AD_RETURN_ON_NULL(ptr, return_value) if (ptr == NULL) { printf("ERROR - '" #ptr "' is NULL! Result = '" #return_value "'\r\n"); return return_value; }

#define AD_MIN(a,b) (((a)<(b))?(a):(b))
#define AD_MAX(a,b) (((a)>(b))?(a):(b))

#define AD_ARRAY_SIZE(array) (sizeof((array))/sizeof((array)[0]))

#define AD_ROUND_HACK_WTF(type, x) ((type)((x) + 0.5))

/* Structures */

typedef struct {
    char                text[AD_TEXT_ELEMENT_SIZE];
} ad_TextElement;

typedef struct {
    size_t              lineCount;
    ad_TextElement     *lines;
} ad_MultiLineText;

typedef struct {
    uint16_t            x;
    uint16_t            y;
    uint16_t            width;
    uint16_t            height;
    ad_TextElement      title;
    ad_TextElement      footer;
} ad_Object;

struct ad_TextFileBox {
    ad_Object           object;
    uint16_t            textX;
    uint16_t            textY;
    uint16_t            lineWidth;
    int32_t             linesOnScreen;
    int32_t             currentIndex;
    int32_t             highestIndex;
    ad_MultiLineText   *lines;
};

struct ad_ProgressBox {
    ad_Object           object;
    uint32_t            progress;
    uint32_t            outOf;
    uint16_t            boxX;
    uint16_t            currentX;
    uint16_t            boxY;
    uint16_t            boxWidth;
    ad_MultiLineText   *prompt;
};

struct ad_Menu {
    ad_Object           object;
    bool                cancelable;
    bool                hasToScroll;
    uint32_t            selectedIndex;
    uint16_t            width;
    uint16_t            height;
    uint16_t            itemX;
    uint16_t            itemY;
    uint16_t            itemWidth;
    size_t              currentSelection;
    size_t              itemCount;
    ad_MultiLineText   *prompt;
    ad_TextElement     *items;
};

struct ad_ConsoleConfig {
    uint16_t            width;
    uint16_t            height;
    uint8_t             headerBg;
    uint8_t             headerFg;
    uint8_t             titleBg;
    uint8_t             titleFg;
    uint8_t             footerBg;
    uint8_t             footerFg;
    uint8_t             objectBg;
    uint8_t             objectFg;
    uint8_t             progressBlank;
    uint8_t             progressFill;
    uint8_t             backgroundFill;
};

extern struct ad_ConsoleConfig ad_s_con;

void                ad_objectInitialize                 (ad_Object *obj, size_t contentWidth, size_t contentHeight);
void                ad_objectPaint                      (ad_Object *obj);
void                ad_objectUnpaint                    (ad_Object *obj);
uint16_t            ad_objectGetContentX                (ad_Object *obj);
uint16_t            ad_objectGetContentY                (ad_Object *obj);
uint16_t            ad_objectGetContentHeight           (ad_Object *obj);
uint16_t            ad_objectGetContentWidth            (ad_Object *obj);

uint16_t            ad_objectGetMaximumContentWidth     (void);
uint16_t            ad_objectGetMaximumContentHeight    (void);
uint16_t            ad_objectGetMaximumObjectHeight     (void);
uint16_t            ad_objectGetMaximumObjectWidth      (void);

void                ad_textElementAssign                (ad_TextElement *el, const char *text);
void                ad_textElementAssignFormatted       (ad_TextElement *el, const char *format, ...);
ad_TextElement*     ad_textElementArrayResize           (ad_TextElement *ptr, size_t newCount);
size_t              ad_textElementArrayGetLongestLength (size_t items, ad_TextElement *elements);

ad_MultiLineText   *ad_multiLineTextCreate              (const char *str);
void                ad_multiLineTextDestroy             (ad_MultiLineText *obj);

void                ad_displayStringCropped             (const char *str, uint16_t x, uint16_t y, size_t maxLen, uint8_t bg, uint8_t fg);
void                ad_displayTextElementArray          (uint16_t x, uint16_t y, size_t maximumWidth, size_t count, ad_TextElement *elements);
void                ad_printCenteredText                (const char *str, uint16_t x, uint16_t y, uint16_t w, uint8_t colBg, uint8_t colFg);

void                ad_drawBackground                   (const char *title);
void                ad_fill                             (size_t length, char fill, uint16_t x, uint16_t y, uint8_t colBg, uint8_t colFg);
size_t              ad_getPadding                       (size_t totalLength, size_t lengthToPad);

#endif
