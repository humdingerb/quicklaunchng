/*
 * Copyright 2010-2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#ifndef APP_H
#define APP_H

#include <Alert.h>
#include <Application.h>

#include "Constants.h"
#include "QuickLaunchSettings.h"
#include "MainWindow.h"

class App : public BApplication {
public:
							App();
	virtual					~App();

	virtual void			ReadyToRun();
	void					AboutRequested();

	QuickLaunchSettings*	Settings() { return &fSettings; }
	MainWindow*				fMainWindow;

private:
	QuickLaunchSettings		fSettings;
};

#endif	// APP_H
