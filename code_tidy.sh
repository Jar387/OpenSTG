#!/usr/bin/sh
indent -linux -npro src/*.c
indent -linux -npro src/ecl/*.c
indent -linux -npro src/media/*.c
indent -linux -npro src/util/*.c

indent -linux -npro include/*.h
indent -linux -npro include/ecl/*.h
indent -linux -npro include/media/*.h
indent -linux -npro include/util/*.h

rm -f src/*~
rm -f src/ecl/*~
rm -f src/media/*~
rm -f src/util/*~

rm -f include/*~
rm -f include/ecl/*~
rm -f include/media/*~
rm -f include/util/*~
