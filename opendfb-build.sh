./autogen.sh --enable-multi --enable-sawman   --enable-divine  --disable-one --enable-network  --disable-fusionsound --disable-fusiondale --disable-video4linux  --disable-network --disable-pnm  --with-gfxdrivers=none   --with-inputdrivers=keyboard,linuxinput,lirc,ps2mouse,serialmouse,lirc   --prefix=/opt/opendfb  --with-tests  #--enable-debug;
make  -j3;sudo make install
