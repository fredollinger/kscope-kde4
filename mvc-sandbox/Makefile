all: kmvcwindow.h build
	cd build && make 2>err

build:
	mkdir -p build
	cd build && cmake ..

kmvcwindow.h:
	uic kmvcwindow.ui > kmvcwindow.h

setup:
	mkdir build
	cd build && cmake ..
err:
	vim build/err
clean:
	rm -f kmvcwindow.h
	cd build && make clean
build/kscope:
	make all
install: build/kscope
	cd build && su -c "make install"
	#cd build && sudo make install
test:
	#make install
	#/usr/local/bin/kscope
	build/kmvc

dist-clean:
	rm -rvf build
	make clean
