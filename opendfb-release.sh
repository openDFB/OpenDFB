make clean;
find -name *.libs | xargs rm -rf;
find -name *.lo | xargs rm -rf;
find -name *deps | xargs rm -rf;
find -name Makefile | xargs rm -rf;
rm autom4te.cache/ -rf;
rm stamp-h1;
