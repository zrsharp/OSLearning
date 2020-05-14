#!/bin/bash

gcc -c fred.c bill.c
ls *.o

echo '========== normal run =========='
gcc -c slmain.c
gcc -o slmain slmain.o bill.o
./slmain
echo '================================'

# static link
echo -e '\n========= static link ========='
ar crv libfoo.a bill.o fred.o
ranlib libfoo.a

gcc -o slmain slmain.o libfoo.a
./slmain
echo -e '================================'

# dynamic link
echo -e '\n========== dynamic link =========='
gcc -c fPIC bill.c fred.c
gcc -shared -o libfoo.so bill.o fred.o
cp slmain.c dlmain.c

gcc dlmain.c -o dlmain -L . -lfoo
./dlmain

echo -e '\n****** After copying libfoo.so to "/usr/lib/" ******'
sudo cp libfoo.so /usr/lib/
./dlmain
echo -e '=================================='

# dynamic load
echo -e '\n========== dynamic load =========='
gcc libtest.c -shared -fPIC -o libtest.so
gcc main.c -o main -ldl
./main
echo -e '=================================='

echo -e '\nClearing previous results......'
sudo rm /usr/lib/libfoo.so
rm *.o *.so *.a
find . -name \*main | xargs rm
