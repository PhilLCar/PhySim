#include <X11/Xlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

#define NIL (0)

// From: https://tronche.com/gui/x/xlib-tutorial/2nd-program-anatomy.html

void init_x() {
  
  Display *dpy = XOpenDisplay(NIL);
  assert(dpy);
  
  int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
  int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));
  
  // 1: Display, 2: Root (parent) Window, 3-4: X-Y Coordinates, 5-6: W-H Sizes, 7: Border, 8: Color
  Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 200, 100, 0, blackColor, blackColor);
  
  // Mask unwanted events
  XSelectInput(dpy, w, StructureNotifyMask);
  
  XMapWindow(dpy, w);
  
 GC gc = XCreateGC(dpy, w, 0, NIL);
 
 XSetForeground(dpy, gc, whiteColor);
 
 for(;;) {
   XEvent e;
   XNextEvent(dpy, &e);
   if (e.type == MapNotify)
     break;
 }
 
 XDrawLine(dpy, w, gc, 10, 60, 180, 20);
 
 XFlush(dpy);
 
 sleep(10);

 exit(0);
}

int main(void) {
  init_x();
  return 0;
}
