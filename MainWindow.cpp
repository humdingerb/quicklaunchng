/*
 * Copyright 2010-2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#include "App.h"
#include "Constants.h"
#include "MainWindow.h"

#include <Catalog.h>
#include <Entry.h>
#include <FindDirectory.h>
#include <NodeMonitor.h>
#include <ObjectList.h>
#include <Path.h>

#include <algorithm>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "MainWindow"


MainWindow::MainWindow(BRect frame)
	:	BWindow(frame, B_TRANSLATE_SYSTEM_NAME("QuickLaunch"),
			B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	_BuildLayout();
}


void
MainWindow::_BuildLayout()
{
	// The menu
	BMenuBar* menuBar = new BMenuBar("menubar");
	BMenu* menu;
	BMenuItem* item;

	menu = new BMenu(B_TRANSLATE("App"));
	item = new BMenuItem(B_TRANSLATE("About QuickLaunch"),
		new BMessage(B_ABOUT_REQUESTED));
	menu->AddItem(item);
	item->SetTarget(be_app);
	item = new BMenuItem(B_TRANSLATE("Settings" B_UTF8_ELLIPSIS),
		new BMessage(SETTINGS), 'S');
	menu->AddItem(item);
	item = new BMenuItem(B_TRANSLATE("Help"),
		new BMessage(HELP));
	menu->AddItem(item);
	item = new BMenuItem(B_TRANSLATE("Quit"),
		new BMessage(B_QUIT_REQUESTED), 'Q');
	menu->AddItem(item);
	menuBar->AddItem(menu);

	menu = new BMenu(B_TRANSLATE("History"));
	item = new BMenuItem(B_TRANSLATE("Previous search"),
		new BMessage(PREV_SEARCH), B_LEFT_ARROW);
	menu->AddItem(item);
	item = new BMenuItem(B_TRANSLATE("Next search"),
		new BMessage(NEXT_SEARCH), B_RIGHT_ARROW);
	menu->AddItem(item);
	item = new BMenuItem(B_TRANSLATE("Clear history"),
		new BMessage(CLEAR_HISTORY));
	menu->AddItem(item);

	menuBar->AddItem(menu);

	// The search & history
	fSearchBox = new BTextControl("SearchBox", NULL, NULL,
		new BMessage(SEARCH_BOX));

	fPopHistory = new BPopUpMenu(B_TRANSLATE("History"));

	// The list - missing

	// do the layouting
	float spacing = be_control_look->DefaultItemSpacing();
	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.Add(menuBar)
		.AddGlue()
		.AddGroup(B_HORIZONTAL, 0)
			.Add(fSearchBox)
			.AddStrut(spacing)
			.Add(fPopHistory)
			.AddGlue()
			.SetInsets(spacing/2)
		.End();

	fSearchBox->MakeFocus(true);
}


bool
MainWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
