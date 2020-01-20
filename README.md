# DarkeLIB
Forked from jpeckham and modified for bugfixes.  Currently in development.

# How to use
The following commands were run on linux mint 19.3 in a terminal window. For all of the sudo commands you will need to enter your password for each of them. Also I would recommend taking note of where you run this, as it will install in the location that you are currently at in a folder called DarkeLIB-master.

============Instructions==========

sudo apt-get install docker.io

sudo apt-get install docker-compose

sudo apt-get install libicu-dev

wget https://github.com/thraeq/DarkeLIB/archive/master.zip

unzip master.zip

cd DarkeLIB-master

chmod -R 777 *

sed -i 's/libz-dev/libz-dev libicu-dev/' Dockerfile

sudo docker-compose up

Log in as parnell password to be admin

