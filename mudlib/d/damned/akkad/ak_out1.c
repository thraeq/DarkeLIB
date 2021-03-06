inherit "std/room";

void reset() {
object mon;
::reset();
if(!present("sentinal"))
new("/d/damned/akkad/obj/mon/sentinal")->move(this_object());
}

void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit("/d/damned/akkad/ak_wgate", "east");
     add_exit("/d/damned/virtual/room_5_9.world","plains");
     set("short","   \n    \np  @--0\n    \n   \nOutside the western gate of Akkad");
     set("long","You are standing just outside the western gate of Akkad."+
	 "The town looks very inviting to the weary traveler.  You hear " +
         "faint laughter coming from the cozy taverns inside the town.  "+
	 "As you look away from the town, you see the plains stretch " +
	 "endlessly before you.\n   \n    \np  @--0\n    \n   \n");

}
void init() {
  ::init();
  if((string)this_player()->query_true_name() == "guest") {
    add_action("block_exit", "plains");
  }
}

int block_exit(string str) {
  write("Guests are not allowed to exit the city.");
  return 1;
}
