//      From Maxwell's Underground mudlib
//        74th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("long", "You are on an unstable wooden and metal mine track "
"high above a deep chasm. You can see a thundering river far below you. "
"The track leads into a small dark tunnel to the east.");
    set("short", 
"You are on an unstable mine track, high above a chasm.");
    set_exits( ({ UNDER+"dm73"}),
      ({"northwest" })
    );
    set_items( ([
       "tunnel" : "The tunnel is just big enough for a mine cart to "
                  "roll through. It would be suicidal to venture into "
                  "because a passing cart would crush you.",
       "track"  : "The polished wood and steel track leads into a dark "
                  "tunnel to the east and stretches northwest across the "
                  "chasm.",
       "river"  : "The river is roaring far below you.",
       "chasm"  : "The steep stone walls lead straight into the icy waves.",
      ]) );
}



