inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/join_rooms/cleric_join", "east");
   add_exit("/d/damned/akkad/ak_bless1", "west");
   add_exit("/d/damned/guilds/cleric/cleric_shop.c", "south");
   set("short","Confessional");
   set("long", @TEXT
You have entered the sacred confessional.  A priest may be called
so that you may confess your sins.  You should feel free to honestly
express yourself and pray for your salvation.  Should you feel the
need, a donation box is available for your tithe and a storage locker
is provided for any material offerings you may have. Through a broad
arch-way to the east is the cloister of the Clerics Guild and to the
south a small church owned store.

You feel an unmistakable impression that should you leave any chest
or locker open, all items contained therein would be given unto our God.
TEXT
);
}

void reset() {
  object ob;
  if(!present("philip"))
    new("/d/damned/guilds/cleric/c_guard")->move(this_object());
  if(!present("box")) {
    ob = new("/d/damned/guilds/cleric/safe");
    ob->set_key("cleric donation box key");
    ob->set_lock("locked");
    ob->set_lock_level(32);
    ob->set_trap_func("/wizards/diewarzau/obj/misc/trap_func", "gate_trap");
    ob->set_trap_level(30);
    ob->move(this_object());
  }
  return;
}
