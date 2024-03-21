INCLUDEDIR=
LIBDIR=

all:client_main server_main

client_main:client_main.cpp
	g++ -o client_main client_main.cpp -L/home/shanchao/wsl-code/mytest/tool -Ipublic
server_main:server_main.cpp
	g++ -o server_main server_main.cpp -L/home/shanchao/wsl-code/mytest/tool -Ipublic

clean:
	rm -f client_main server_main