esatic : main.o adherents.o
	gcc -o esatic main.o adherents.o -lmysqlclient
	./esatic

main.o : main.c
	gcc -c main.c -I/usr/include/mysql

adherents.o : sources/adherents.c
	gcc -c sources/adherents.c -I/usr/include/mysql
