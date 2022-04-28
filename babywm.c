#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>

#include "eventnames.h"

static Display *display;


int
main(int argc, char *argv[])
{
    int screen;
    Window root;
    XEvent event;

    printf("opening display\n");
    if ((display = XOpenDisplay(NULL)) == NULL) {
        printf("error opening display\n");
        exit(1);
    }

    screen = DefaultScreen(display);
    root = RootWindow(display, screen);

    XSelectInput(display, root, SubstructureRedirectMask);

    while (1) {
        XNextEvent(display, &event);
        switch (event.type) {
            case MapRequest:
                fprintf(stderr, "Event: %s Window: %d\n", event_names[event.type], event.xmap.window);
                XSelectInput(display, event.xmap.window, EnterWindowMask|LeaveWindowMask);
                XMapWindow(display, event.xmap.window);
                break;
            case ConfigureRequest:
                fprintf(stderr, "Event: %s Window: %d\n", event_names[event.type], event.xconfigure.window);
                break;
            case EnterNotify:
                fprintf(stderr, "Event: %s Window: %d\n", event_names[event.type], event.xcrossing.window);
                break;
            default:
                break;
        }
    }

    return 0;
}
