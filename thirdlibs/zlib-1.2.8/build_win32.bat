
echo off
nmake -f win32/Makefile.msc LOC="-DASMV -DASMINF" OBJA="inffas32.obj match686.obj"
del *.obj *.pdb *.manifest *.exp

