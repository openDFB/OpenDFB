./autogen.sh --enable-multi --disable-sawman   --enable-divine --enable-network --disable-network --disable-pnm --enable-freetype  --with-gfxdrivers=none   --with-inputdrivers=keyboard,linuxinput,lirc,ps2mouse,serialmouse,lirc   --prefix=/opt/opendfb  --with-tests  #--enable-debug;
make  -j;sudo make install
