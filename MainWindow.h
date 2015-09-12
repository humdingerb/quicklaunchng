/*
 * Copyright 2010-2015. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Author:
 *	Humdinger, humdingerb@gmail.com
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Application.h>
#include <Button.h>
#include <ControlLook.h>
#include <GroupLayout.h>
#include <LayoutBuilder.h>
#include <ListView.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Message.h>
#include <ObjectList.h>
#include <PopUpMenu.h>
#include <Query.h>
#include <ScrollView.h>
#include <TextControl.h>
#include <Window.h>
#include <Volume.h>
#include <VolumeRoster.h>


class MainWindow : public BWindow
{
public:
									MainWindow(BRect frame);
//			void					MessageReceived(BMessage *msg);
			bool					QuitRequested();

			void					_BuildLayout();

private:
			BObjectList<BQuery>		fQueries;
			BObjectList<BVolume>	fVolumes;
			BVolumeRoster*			fVolumeRoster;

			BTextControl*			fSearchBox;
			BPopUpMenu*				fPopHistory;
};

#endif
