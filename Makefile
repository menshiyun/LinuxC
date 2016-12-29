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

