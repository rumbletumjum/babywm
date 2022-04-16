#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>


int
main(int argc, char *argv[])
{
    Display *display;
    int screen;
    Window root;

    printf("opening display\n");
    if ((display = XOpenDisplay(NULL)) == NULL) {
        printf("error opening display\n");
        exit(1);
    }

    screen = DefaultScreen(display);
    root = RootWindow(display, screen);

    return 0;
}
