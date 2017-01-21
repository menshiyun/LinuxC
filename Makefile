obj = a.o b.o

.PHONY : all
all : test $(obj)

test : $(obj)
	cc -o test $(obj)

.PHONY : clean
clean:
	rm -rf test $(obj)

test_dir = t_d
.PHONY : install
install :
	mkdir $(test_dir)
	cp test $(test_dir)

.PHONY : uninstall
uninstall :
	rm -rf $(test_dir)

tcp_net :
	cc tcp_net_socket.c tcp_net_server.c -o tcp_net_server.out
	cc tcp_net_socket.c tcp_net_client.c -o tcp_net_client.out
