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
	rmdir bob* 
	rmdir joe* 
build/kscope:
	make all
install: build/kscope
	#cd build && su -c "make install"
	cd build && sudo make install
test:
	make install
	/usr/local/bin/kscope
