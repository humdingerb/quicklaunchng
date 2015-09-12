/*
 * Copyright 2010-2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 *
 * A graphical launch panel finding an app via a query.
 */

#include <Catalog.h>

#include "App.h"
#include "Constants.h"

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "Application"

App::App()
	:
	BApplication(kApplicationSignature)
{
}


App::~App()
{
	BMessenger messenger(fMainWindow);
	if (messenger.IsValid() && messenger.LockTarget())
		fMainWindow->Quit();
}


void
App::ReadyToRun()
{
	fMainWindow = new MainWindow(BRect(fSettings.GetWindowPosition()));
	fMainWindow->Show();
}


void
App::AboutRequested()
{
	BAlert* alert = new BAlert("about",
		B_TRANSLATE("QuickLaunch v1.0\n"
		"\twritten by Humdinger\n"
		"\tCopyright 2010-2015\n\n"
		"QuickLaunch quickly starts any installed application. "
		"Just enter the first few letters of its name and choose "
		"from a list of all found programs.\n\n"
		"Please let me know of any bugs you find or features you "
		"miss. Contact info is in the ReadMe, see menu item 'Help'."),
		B_TRANSLATE("Thank you"));

	BTextView* view = alert->TextView();
	BFont font;
	view->SetStylable(true);
	view->GetFont(&font);
	font.SetSize(font.Size() + 4);
	font.SetFace(B_BOLD_FACE);
	view->SetFontAndColor(0, 11, &font);
	alert->Go();
}


int
main()
{
	App app;
	app.Run();
	return 0;
}
