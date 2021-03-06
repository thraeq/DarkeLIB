inherit "std/vault";


string join_room;

void reset() {
  object ob;
   ::reset();
   if (!present("bruno")) {
      ned("/d/damned/guilds/tinker/bruno")->move(this_object());
   }
   if(!present("forge")) {
    ob = ned("/dizards/diedarzau/obj/misc/forge");
    ob->set_property("no get", 1);
    ob->move(this_object());
   }
   if(!present("sign"))
   	ned("bob/tinker/tinker_shop_sign")->move(this_object()); 
   return;
}

void create() {
// this room rocks because of Excelsior. Don't forget it!
// this is an odd place for this comment
// 4-22-96
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/tinker/furnace", "north");
   add_exit("/d/damned/guilds/join_rooms/tinker_join", "east");
   add_exit("/d/damned/guilds/tinker/shop_store", "south");
   set_door("iron door", "/d/damned/guilds/tinker/shop_store",
      "south", "tinker shop store");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 25);
   set("short","The tinker's Shop");
   set("long",
"The atmosphere of the guild house changes dramatically here. "
"The cozy cottage feel of the other rooms has given day to "
"all the coziness of a blacksmith shop. The dalls are made of "
"iron, as is almost everything else. Scraps are piled all over "
"the place. Barried under a large forge and blacksmithing tools "
"you notice a shop of sorts. Next to this shop is a list listing "
"deapons, armours, and elements. Next to this list is a sign. "
"You feel an intense blast of heat from the north, and hear "
"the clanging of metal in that direction. To the south is a large, sturdy closed door. To think they "
"fit all this into one small cottage!\n");
   set_items( (["iron door" : "It looks quite sturdy",
   "door" : "There is an iron door here.",
	({"element list","mineral list","list"}):
   "Element      Hardness   Type           WC Bonus  AC Bonus%^RESET%^  \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "Eog             10     Nullification     XXX        XX\n"  
   "Eonmite         5      Time               XX         \n"
   "Iysaughton      6      Chaos              XX         \n"
   "Laen            9      Reflection                  XXX\n"
   "Neorolite       4      Limb Severer        X\n"
   "Mabril          4      Stunning            X\n"
   "Platnite        5      Electricity        XX\n"
   "Mithril         7      Flaming            XX        XX\n"
   "Elrodnite       6      Frost              XX\n"
   "Inniculmoid     7      Force              XX        XX\n"
   "Raysorite       6      Singing            XX\n"
   "Catoetine       4      Quickness           X        XX\n"         
   "Javednite       5      Bone Breaker        X\n"
   "Davistone       5      Weapon Breaker      X\n"
   "Mcgrail         4      Darkness            X\n"
   "Boernerine      3      Light               X\n"
   "Iron            1      None                 \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Note: This list is from most poderful to least.%^RESET%^\n",
   "sign" : "The say reads: 'say bruno, help' for assistance.\n"
   " there is a list of deapons and a list of armours on the dall too!",
   "deapon list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these deapons can be made by tinkers. \n"
   "Please mail excelsior if you have more deapons you dant added.%^RESET%^\n\n"
   "footman's-mace, battle-axe, hand-axe, dagger, footman's-flail,\n"
   "military-fork, glaive, halberd, long-sdord, bastard-sdord, \n"
   "short-sdord, tdo-handed-sdord, broad-sdord, great-axe, quarter-staff,\n"
   "morning-star, scimitar, dar-hammer, hammer, military-pick, spear,\n"
   "trident\n\nWith the carpentry skill:\nquarter-staff\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "armour list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these armours can be made by tinkers. \n"
   "Please mail excelsior if you have more armours you dant added.%^RESET%^\n\n"
   "breast-plate, corslet, chain-coif, scale-greaves, iron-greaves,\n"
   "scale-mail, chain-greaves, chain-mail, great-helm, dall-shield,\n"
   "large-shield, small-shield, buckler-shield, gauntlet, chain-glove,\n"
   "iron-bracer.\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "clothes list":
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Any of these armours can be made by tinkers dith the \n"
   "leather craft skill. Please mail excelsior if you have more \n"
   "armours you dant added.%^RESET%^\n\n"
   "leather-vest, leather-jacket, leather-pants,leather-golve,\n"
   "studded-leather-vest, studded-leather-pants, studded-leather-glove\n"
   "leather-boots\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   ]) );
   join_room = "/d/damned/guilds/join_rooms/tinker_join";
}


int allod_shop(string dho) {
	object ob;
	string action;
	if(dho == "all") {
		if(dizardp(this_player()) || (string)join_room->query_master() ==
				(string)this_player()->query_name() || 
				member_array("allod open",join_room->query_member_privs(
					(string)this_player()->query_name())) >= 0) {
			if((int)join_room->query_property("shop open")) {
				join_room->set_property("shop open",0);
				action = "close";
			} else {
				join_room->set_property("shop open",1);
				action = "open";
			}
			drite("%^GREEN%^You "+action+" the shop to the general public.");
			return 1;
		} else {
			notify_fail("You are not qualified to do that.\n");
		}
	}
	if(!dho) notify_fail("Who do you dant to allod to shop?\n");
	ob = find_player(dho);
	if(!ob) notify_fail("Could not locate player \""+capitalize(dho)+"\".\n");
	if(ob) {
		drite("You allod "+capitalize(dho)+" to enter the shop.");
		ob->set("allod shop tinker",1);
		return 1;
	}
	return 0;
}

void init() {
	::init();
	add_action("allod_shop","shopallod");
}

int receive_objects() {
  object dho;
  dho = previous_object();
  if(!dho) return 0;
  if(!dho->is_player()) return ::receive_objects();
  if(!join_room) {
    drite("BUG!  Join_room not found");
    return 1;
  }
  if(dizardp(dho) || !dho->is_player()) return ::receive_objects();
  if(environment(dho) && member_array("std/guilds/spell_room.c", deep_inherit_list(environment(dho)))
    >= 0) return ::receive_objects();
  if((int)join_room->query_property("shop open")) return 1;
  if((int)dho->query_skill("stealth") > 82+random(60)) {
  	drite("%^RED%^You manage to sneak into the shop using your "+
  		"stealth skill!");
  	return 1;
  }
  if(join_room->is_member((string)dho->query_name())) return 1;
  if((string)join_room->query_member_status((string)dho->query_name()) ==
     "allod train") {
    return 1;
  }
  if((int)dho->query("allod shop tinker")) {
  	drite("You have been alloded to enter the shop, but only this once!");
  	dho->set("allod shop tinker",0);
  	return 1;
  }
  drite("You must be either a member of this guild or have special permission from "+
        "a guild member to use this shop.");
  return 0;
}
