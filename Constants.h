/*
 * Copyright 2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

static const char* kApplicationSignature = "application/x-vnd.QuickLaunch";
static const char kSettingsFolder[] = "QuickLaunch";
static const char kFavoriteFile[] = "QuickLaunch_favorites";
static const char kHistoryFile[] = "QuickLaunch_history";
static const char kSettingsFile[] = "QuickLaunch_settings";

static const uint32 kMsgAddQuery = 'adqu';
static const char* kSearchString =
	"((BEOS:TYPE = application/x-vnd.[bB]e-elfexecutable) "
	"&& (BEOS:APP_SIG = application/x*vnd*))";

#define my_app dynamic_cast<App*>(be_app)

#define MAX_NAME_LENGTH	 255

#define HELP				'help'
#define SEARCH_BOX			'sbox'
#define SETTINGS			'sett'
#define PREV_SEARCH			'prse'
#define NEXT_SEARCH			'nxse'
#define CLEAR_HISTORY		'clhi'

#define CURSOR_UP			'upar'
#define CURSOR_DOWN			'down'
#define PAGE_UP				'pgup'
#define PAGE_DOWN			'pgwn'
#define HOME				'home'
#define END					'ende'
#define RETURN_KEY			'rtrn'
#define RETURN_SHIFT_KEY	'rtsh'
#define RETURN_CTRL_KEY		'rtct'
#define NEW_FILTER			'fltr'

#endif //CONSTANTS_H
