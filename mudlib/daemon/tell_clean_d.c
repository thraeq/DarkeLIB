// tell_log_clean_d.c
// Cleans 'tell hist' logs when run
// saves HD space wasted when logs get large
// Written by Thrace (April 30th 1999)

#include "/adm/include/std.h"
#include "/adm/include/security.h"
#include "/adm/include/move.h"
#include "/adm/include/daemons.h"

inherit DAEMON;

void clean_tells(){
    string file;
    string obj;
    object ob;
    int x, i;
    string *inv;
    
    inv = get_dir("/log/tells/");
       for (i=0;i<sizeof(inv);i++){
          file = "/log/tells/"+inv[i];
          rm(file);
    }
    return;
}

void clean_tell(object ob){
    string file, name;
    string *inv;
    
    name=ob->query_true_name();
    file = "/log/tells/"+name;
    rm(file);
    return;
}

