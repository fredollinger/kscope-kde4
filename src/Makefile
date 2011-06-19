all:
	mkdir -p build
	cd build && make 2>err
setup:
	mkdir build
	cd build && cmake ..
err:
	vim build/err
clean:
	cd build && make clean
build/kscope:
	make all
install: build/kscope
	cd build && su -c "make install"
test:
	/usr/local/bin/kscope
