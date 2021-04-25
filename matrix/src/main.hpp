// Matrix Screensaver
// Copyright (c) J Brown 2003 (catch22.net)
// Copyright (c) 2011-2018 Henry++

#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <commctrl.h>
#include "resource.hpp"
#include "app.hpp"

// config
typedef unsigned int GLYPH;

#define UID 0xDEADBEEF

#define CLASS_FULLSCREEN APP_NAME_SHORT L"_Fullscreen"
#define CLASS_PREVIEW APP_NAME_SHORT L"_Preview"

#define GLYPH_REDRAW 0x8000
#define GLYPH_BLANK 0x4000
#define RND_MASK 0xB400

#define AMOUNT_MIN 1
#define AMOUNT_MAX 26
#define AMOUNT_DEFAULT 26

#define DENSITY_MIN 5
#define DENSITY_MAX 50
#define DENSITY_DEFAULT 30

#define SPEED_MIN 1
#define SPEED_MAX 10
#define SPEED_DEFAULT 6

#define HUE_MIN 1
#define HUE_MAX 255
#define HUE_DEFAULT 100

#define HUE_RANDOM false

// constants inferred from matrix.bmp
#define MAX_INTENSITY 5 // number of intensity levels
#define GLYPH_WIDTH 14 // width of each glyph (pixels)
#define GLYPH_HEIGHT 14 // height of each glyph (pixels)

//
//	The "matrix" is basically an array of these
//  column structures, positioned side-by-side
//
struct _MATRIX_COLUMN
{
	GLYPH* glyph = nullptr;

	int state = 0;
	int countdown = 0;

	int runlen = 0;

	int blippos = 0;
	int bliplen = 0;

	int length = 0;

	bool started = false;
};

typedef _MATRIX_COLUMN MATRIX_COLUMN;

struct _MATRIX
{
	int width = 0;
	int height = 0;
	int numcols = 0;
	int numrows = 0;

	// bitmap containing glyphs.
	HDC hdcBitmap = nullptr;
	HBITMAP hbmBitmap = nullptr;

	MATRIX_COLUMN column[1];
};

typedef _MATRIX MATRIX;

#endif // __MAIN_H__
