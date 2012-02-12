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

.PHONY: newprojectlayout4.h KSGlobalConfig.h

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
dist-clean:
	rm $(UI_HEADERS)

build/kscope:
	make all
install: build/kscope4
	cd build && su -c "make install"
	#cd build && sudo make install
test:
	su -c "make install"
	#/usr/local/bin/kscope4 kscope4.cpp
	/usr/local/bin/kscope4 /home/follinge/projects/kscope-kde4/src/kscope4.cpp

vcsCommitLayout.h:
	$(UI) vcsCommitLayout.ui > vcsCommitLayout.h

newprojectlayout4.h:
	uic-qt4 ui/newprojectlayout4.ui > newprojectlayout4.h 


KSGlobalConfig.h:
	rm -f KSGlobalConfig.h
	kconfig_compiler KSGlobalConfig.kcfg KSGlobalConfig.kcfgc

# Sun Oct 16 18:44:17 PDT 2011
