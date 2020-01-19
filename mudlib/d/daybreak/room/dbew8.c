#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbew7", "east");
    add_exit(ROOMS+"dbew9","west");
//Basic mapping added by Tiny 1/19/2020 
    set("short","   \n    \n0--@--0\n    \n   \nMain Street");
    set("long","   \n    \n0--@--0\n    \n   \nMain Street runs east-west through Daybreak Ridge");
}
