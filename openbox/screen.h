#ifndef __screen_h
#define __screen_h

#include "geom.h"
#include "client.h"

struct Client;

#define DESKTOP_ALL (0xffffffff)

/*! The number of available desktops */
extern guint screen_num_desktops;
/*! The current desktop */
extern guint screen_desktop;
/*! The size of the screen */
extern Size  screen_physical_size;
/*! Are we in showing-desktop mode? */
extern gboolean screen_showing_desktop;

/*! Orientation of the desktops */
typedef enum {
    Orientation_Horz = 0,
    Orientation_Vert = 1
} Orientation;

typedef struct DesktopLayout {
    Orientation orientation;
    Corner start_corner;
    guint rows;
    guint columns;
} DesktopLayout;
extern DesktopLayout screen_desktop_layout;

/*! An array of gchar*'s which are desktop names in UTF-8 format */
extern char **screen_desktop_names;

/*! Take over the screen, set the basic hints on it claming it as ours */
gboolean screen_annex();

/*! Once the screen is ours, set up its initial state */
void screen_startup();
/*! Free resources */
void screen_shutdown();

/*! Figure out the new size of the screen and adjust stuff for it */
void screen_resize();

/*! Change the number of available desktops */
void screen_set_num_desktops(guint num);
/*! Change the current desktop */
void screen_set_desktop(guint num);

/*! Shows and focuses the desktop and hides all the client windows, or
  returns to the normal state, showing client windows. */
void screen_show_desktop(gboolean show);

/*! Updates the desktop layout from the root property if available */
void screen_update_layout();

/*! Get desktop names from the root window property */
void screen_update_desktop_names();

/*! Installs or uninstalls a colormap for a client. If client is NULL, then
  it handles the root colormap. */
void screen_install_colormap(struct Client *client, gboolean install);

void screen_update_struts();

Rect *screen_area(guint desktop);

Strut *screen_strut(guint desktop);

#endif
