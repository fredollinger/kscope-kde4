UI=uic-qt4
UI_HEADERS=autocompletionlayout4.h \
calltreelayout4.h \
cscopemsglayout.h \
fileviewlayout.h \
greplayout.h \
newprojectlayout4.h \
openprojectlayout4.h \
symbollayout4.h \
vcsCommitLayout.h

all:
	mkdir -p build
	#cd build && make 2>err
	cd build && make 
setup:
	mkdir build
	cd build && cmake ..
err:
	vim build/err
clean:
	cd build && make clean
dist-clean:
	rm $(UI_HEADERS)

build/kscope:
	make all
install: build/kscope4
	cd build && su -c "make install"
	#cd build && sudo make install
test:
	su -c "make install"
	/usr/local/bin/kscope4 kscope4.cpp

vcsCommitLayout.h:
	$(UI) vcsCommitLayout.ui > vcsCommitLayout.h
		

# Sun Oct 16 18:44:17 PDT 2011
