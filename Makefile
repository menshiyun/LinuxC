obj = a.o b.o
test : $(obj)
	cc -o test $(obj)
a.o : a.c b.h
	cc -c a.c
b.o : b.c
	cc -c b.c
