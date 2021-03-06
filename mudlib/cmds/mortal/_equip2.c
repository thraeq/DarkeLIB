/*  /cmds/mortal/_equip.c
 *  Made for DarkeMUD
 *  Created by Geldron 030996
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */


inherit DAEMON;

int cmd_equip(string arg) {
    object *tmp;
    int i;
    string hand, race;

    if(arg) {
	write(syntax("equip"));
	return 1;
    }
    write("You begin power equipping...");
    hand = (string)this_player()->query_property("handedness");
    race = (string)this_player()->query_race();
    tmp = all_inventory(TP);
    for(i = 0; i < sizeof(tmp); i++) {
	if(tmp[i]->is_weapon()) {

	  if(race == "thranx"){
            if(strlen((string)tmp[i]->query_type()) > 10 &&
              ((string)tmp[i]->query_type())[0..9] == "two handed")
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in first hand "
                  "and second hand");
            else {
	      if(hand == "fourth hand") {
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in fourth hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in third hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 3 in second hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 4 in first hand");
	      }  else
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in third hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in fourth hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 3 in second hand");
   TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 4 in first hand");
            }
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "shield") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on first hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on second hand");
	  }
        if(tmp[i]->is_armour())
          if((string)tmp[i]->query_type() == "bracer") {
     TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on first arm");
     TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on second arm");
     TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 3 on third arm");
     TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 4 on fourth arm");
	  }
       if(tmp[i]->is_armour())
	 if((string)tmp[i]->query_type() == "glove") {
    TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on first hand");
    TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on second hand");
    TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 3 on third hand");
    TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 4 on fourth hand");
	 } 
             else
                TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
	 return 1;
	  }
         else

	    if(strlen((string)tmp[i]->query_type()) > 10 &&
	      ((string)tmp[i]->query_type())[0..9] == "two handed")
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand "
		  "and left hand");
	    else {     	      
     if(hand == "left hand") {
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in left hand");
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in right hand");
       }  else 
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand");
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in left hand");
	    }
	}
	if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "shield") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on left hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
	    }     
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "bracer") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "glove") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }  else
                TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
    }        
    write("Done Equiping.");
    return 1;
}
	

void help() {
    message("equip_help", syntax("equip") + "\n\n"
      "Equips all your armour and weapons in order.  It isn't "
      "very accurate as to getting things worn the best possible way.", TP);
}
