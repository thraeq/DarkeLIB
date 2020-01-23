//      Wizard:  Khojem
//      wood 3
//      wood3.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nDark woods");
    set("long", "You are closely surrounded by dense wooded growth.  "+
      "The tall, towering trees above block all light to you.  "+
      "There are no signs of a trail or path to guide you through "+
      "this maze of dense wooded growth.  Even if there were a "+
      "trail it would prove hard to follow in this darkness.\n   0\n   | \n0--@--0\n   | \n   0\n"
    );
    add_exit("wood1","north");
    add_exit("wood2","east");
    add_exit("wood5","west");
    add_exit("wood1","south");
    set_items(([
     ({ "tree","trees", "woods", "growth" }) :
        "The trees are large, healthy trees filled with foliage."+
        "They grow densely all around you.",
     ({ "leaf","leaves" }) :
        "The leaves form a tight, close lattice over your head and don't "
        "allow in any light from above.",
     ({ "trail","path" }) :
        "There is no trail or path to follow!  You are lost."
    ]));
    set_smell("default", "The dank, moist smell of decaying wood is strong "+
      "here.  The smell of... maybe rotting corpses is in the still air."
    );
    set_listen("default", "The silence around you is deafening.  "+
      "Occasionally, you hear the sound of battle from a ways off.");
}
