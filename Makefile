
server: server.c
	gcc -Wall server.c server
list: genList.c
	gcc -Wall genList.c -o list

