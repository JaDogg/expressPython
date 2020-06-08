cd ANTLR4runtime

mkdir -p build && mkdir -p run && cd build

cmake ..

DESTDIR=../run make install

cd ../run/usr/local/include

sudo cp -r antlr4-runtime /usr/local/include

cd ../lib

sudo cp * /usr/local/lib

sudo ldconfig