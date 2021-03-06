//Land Scanner Code
#include "/adm/include/std.h"
#include "/adm/include/daemons.h"

inherit DAEMON ;
int help();

mixed cmd_test(){
 int z,landtype,xline,yline,Bx,By,ypos,*exits,skill_level,loop;
 object room,*targets,*inv;
 string path,*desc;
 mixed grid;

  room = environment(this_player());
  path = file_name(room);
  grid = allocate(90);
  if(sscanf(path,"/d/damned/virtual/room_%d_%d.world",Bx,By)){                 
    yline = (By-4);
    if(yline < 0)
       yline = 80 + yline;
    targets = ({});    
     loop = 0;
//    while(yline <= (By+4)){
     while(loop <= 9){
         if(yline == 80)
            yline = 0;
         ypos = 0;
         xline = (Bx-4);
         grid[yline] = allocate(30);
         skill_level = (this_player()->query_skill("perception"));
         while(ypos <= 9){ 
           if(xline < 0)
            xline = 40 + xline;
           if(xline == 40)
            xline = 0;
// //          write("Testing loop "+loop+" "+xline);
// //             write("The value is "+yline +" "+ypos);
              if( (xline >=0 && xline <=40 )&&(yline >= 0 && yline <= 80)){
                room = find_object_or_load("/d/damned/virtual/room_"+
                       xline+"_"+yline+".world");
                inv = all_inventory(room);
                targets = filter_array(inv,"query_boat");
                landtype = (room->query_water());
                exits = room->query_exits();
                if(landtype == 1){
                  //Water Room
                  if(sizeof(targets) >= 1)
                    grid[yline][ypos] = "%^RED%^*";                   
                  else
                    grid[yline][ypos] = "%^BLUE%^#";
                }
                if(landtype == 0){
                   //Land Room
                  if(sizeof(targets) >= 1)
                     grid[yline][ypos] = "%^RED%^!";
   //               if(sizeof(exits) > 4)
   //                 grid[yline][ypos] = "%^RED%^A"; 
                  else {
                    desc = explode(room->query_short()," ");
   //                 write("Value is "+grid[yline][ypos]+" "+sizeof(desc));
                    while(grid[yline][ypos] == 0){
                     if(member_array("forest",desc) != -1)                       
                       grid[yline][ypos] = "%^BOLD%^%^GREEN%^F%^RESET%^";     
                     if(member_array("coast",desc) != -1)                       
                       grid[yline][ypos] = "%^B_WHITE%^%^BLUE%^C%^RESET%^";
                     if(member_array("tundra",desc) != -1)                       
                       grid[yline][ypos] = "%^WHITE%^T%^RESET%^";
                     if(member_array("plains",desc) != -1)                       
                       grid[yline][ypos] = "%^B_GREEN%^%^ORANGE%^P%^RESET%^";
                     if(member_array("hills",desc) != -1)                       
                       grid[yline][ypos] = "%^B_GREEN%^%^BOLD%^H%^RESET%^";
                     if(member_array("mountains",desc) != -1)                       
                       grid[yline][ypos] = "%^BOLD%^M%^RESET%^";
                     if(member_array("desert",desc) != -1)                       
                       grid[yline][ypos] = "%^B_WHITE%^%^ORANGE%^D%^RESET%^";
                     if(member_array("jungle",desc) != -1)                       
                      grid[yline][ypos] = "%^MAGENTA%^J%^RESET%^";
                     if(member_array("swamp",desc) != -1)                       
                      grid[yline][ypos] = "%^GREEN%^S%^RESET%^";
                     if(grid[yline][ypos] == 0)
                        grid[yline][ypos] = "?";
                   }
                  }
                }
                //Check to see if Player room
                if(yline == By && ypos == 4 )
                    grid[yline][ypos] = "%^ORANGE%^U";                  
              }
              ypos = ypos + 1;
              xline = xline + 1;
         }               
         yline = yline + 1;
         loop = loop + 1;
    }
    z = By - 4;
    write("\n");
    loop = 0;
   if(skill_level >= 90){
    while(loop < 9 ){
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      write("      "+grid[z][0]+" "+grid[z][1]+" "+grid[z][2]+" "+
            grid[z][3]+" "+grid[z][4]+" "+grid[z][5]+" "+grid[z][6]+
            " "+grid[z][7]+" "+grid[z][8]);
      z = z + 1;
      if(z == 80)
         z = 0;
      loop = loop + 1;
    }
   }
    z = By - 3;
   if(skill_level < 90 && skill_level > 70){ 
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      while(loop < 7 ){
        write("      "+grid[z][1]+" "+grid[z][2]+" "+
            grid[z][3]+" "+grid[z][4]+" "+grid[z][5]+" "+grid[z][6]+
            " "+grid[z][7]);
        z = z + 1;
        if(z == 80)
         z = 0;
        loop = loop + 1;
      }
   }
   z = By - 2;
   if(skill_level < 70){ 
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      while(loop < 5 ){
        write("    "+grid[z][2]+" "+grid[z][3]+" "+grid[z][4]+
            " "+grid[z][5]+" "+grid[z][6]);
        z = z + 1;
        if(z == 80)
         z = 0;
        loop = loop + 1;
      }
   }
    write("\n %^RED%^* %^WHITE%^= Water Target "
          ": %^RED%^! %^WHITE%^= Land Target\n"
          " %^RED%^A %^WHITE%^= Special\n"
          " %^BLUE%^# %^WHITE%^= Water        "
          ": %^GREEN%^L %^WHITE%^= Land\n"
          " %^ORANGE%^U %^WHITE%^= Your current Position\n");
  }
  else
    write("You are not on the World Map.");
  return 1;
}
int query_boat(object ob){
    if(ob->query_property("boat") == 1)
       return 1;
    else
       return 0;
}
int help() {
	write ( @ENDHELP
Usage: observe

The observe command allows you to look at your current position on
the world map on a 2D map display. Each block on the map represents
one room length. 

ENDHELP
	);

	return 1 ;
}
