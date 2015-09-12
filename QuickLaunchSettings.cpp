/*
 * Copyright 2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#include <Application.h>
#include <Directory.h>
#include <File.h>
#include <FindDirectory.h>
#include <Path.h>
#include <Font.h>
#include <Message.h>

#include <stdio.h>
#include <stdlib.h>

#include "Constants.h"
#include "QuickLaunchSettings.h"


QuickLaunchSettings::QuickLaunchSettings()
	:
	dirtySettings(false)
{
	fPosition.Set(-1, -1, -1, -1);
	BPath path;
	BMessage msg;

	if (find_directory(B_USER_SETTINGS_DIRECTORY, &path) == B_OK) {
		status_t ret = path.Append(kSettingsFolder);
		if (ret == B_OK) {
			path.Append(kSettingsFile);
			BFile file(path.Path(), B_READ_ONLY);

			if ((file.InitCheck() == B_OK) && (msg.Unflatten(&file) == B_OK)) {
				if (msg.FindRect("windowlocation", &fPosition) != B_OK)
					fPosition.Set(-1, -1, -1, -1);
			}
		}
	}
}


QuickLaunchSettings::~QuickLaunchSettings()
{
	if (!dirtySettings)
		return;

	BPath path;
	BMessage msg;

	if (find_directory(B_USER_SETTINGS_DIRECTORY, &path) < B_OK)
		return;
	status_t ret = path.Append(kSettingsFolder);

	if (ret == B_OK)
		ret = create_directory(path.Path(), 0777);

	if (ret == B_OK)
		path.Append(kSettingsFile);

	if (ret == B_OK) {
		BFile file(path.Path(), B_WRITE_ONLY | B_CREATE_FILE);
		ret = file.InitCheck();

		if (ret == B_OK) {
			msg.AddRect("windowlocation", fPosition);
			msg.Flatten(&file);
		}
	}
}


bool
QuickLaunchSettings::Lock()
{
	return fLock.Lock();
}


void
QuickLaunchSettings::Unlock()
{
	fLock.Unlock();
}


void
QuickLaunchSettings::SetWindowPosition(BRect where)
{
	if (fPosition == where)
		return;
	fPosition = where;
	dirtySettings = true;
}
