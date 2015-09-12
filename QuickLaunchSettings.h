/*
 * Copyright 2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#ifndef QUICKLAUNCHSETTINGS_H
#define QUICKLAUNCHSETTINGS_H

#include <Locker.h>
#include <Rect.h>


class QuickLaunchSettings {
public:
					QuickLaunchSettings();
					~QuickLaunchSettings();

		bool		Lock();
		void		Unlock();

		BRect		GetWindowPosition() { return fPosition; }

		void		SetWindowPosition(BRect where);
private:
		BRect		fPosition;
		bool		dirtySettings;;

		BLocker		fLock;
};

#endif	/* QUICKLAUNCHSETTINGS_H */
