/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",
   "This narrow passageway snakes from east to west as it travels further "
   "into the catacombs.  To the northwest lies a large, open chamber, "
   "while to the south, the passageway continues and seems to bend back "
   "to the north at some point."
   );
   set_smell("default", "The air smells of rotting flesh.");
   set_listen("default", "You hear cackling to the east somewhere.");
   set_search("default", "You find a hidden exit to the east!");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac129",
                "south": PATH+"catac131",
                "east": PATH+"catac145",
                ]) );
   set_invis_exits( ({"east"}) );
}
