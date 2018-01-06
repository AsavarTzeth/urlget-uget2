/*
 *
 *   Copyright (C) 2005-2018 by C.H. Huang
 *   plushuang.tw@gmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  ---
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU Lesser General Public License in all respects
 *  for all of the code used other than OpenSSL.  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so.  If you
 *  do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

#ifndef UGTK_SETTING_DIALOG_H
#define UGTK_SETTING_DIALOG_H

#include <gtk/gtk.h>
#include <UgtkApp.h>
#include <UgtkSettingForm.h>
#include <UgtkScheduleForm.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UgtkSettingDialog        UgtkSettingDialog;

typedef enum
{
	UGTK_SETTING_PAGE_UI,
	UGTK_SETTING_PAGE_CLIPBOARD,
	UGTK_SETTING_PAGE_OTHERS,
} UgtkSettingDialogPage;

struct UgtkSettingDialog
{
	GtkDialog*     self;
	UgtkApp*       app;

	GtkTreeView*   tree_view;
	GtkListStore*  list_store;
	GtkNotebook*   notebook;

	struct UgtkUserInterfaceForm  ui;
	struct UgtkClipboardForm      clipboard;
	struct UgtkBandwidthForm      bandwidth;
	struct UgtkCompletionForm     completion;
	struct UgtkAutoSaveForm       auto_save;
	struct UgtkScheduleForm       scheduler;
	struct UgtkCommandlineForm    commandline;
	struct UgtkPluginForm         plugin;
	struct UgtkMediaWebsiteForm   media_website;
};

UgtkSettingDialog*  ugtk_setting_dialog_new ();
void                ugtk_setting_dialog_free (UgtkSettingDialog* sdialog);

void  ugtk_setting_dialog_run (UgtkSettingDialog* dialog, UgtkApp* app);
void  ugtk_setting_dialog_set (UgtkSettingDialog* dialog, UgtkSetting* setting);
void  ugtk_setting_dialog_get (UgtkSettingDialog* dialog, UgtkSetting* setting);

void  ugtk_setting_dialog_add (UgtkSettingDialog* sdialog,
                               const gchar* title,
                               GtkWidget*   page);

void  ugtk_setting_dialog_set_page (UgtkSettingDialog* sdialog, int nth);

#ifdef __cplusplus
}
#endif

#endif  // End of UGTK_SETTING_DIALOG_H
