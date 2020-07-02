# INSTALL QT5

sudo apt-get install build-essential

sudo apt-get install qt5-default

# SETUP ENVIRONMENT VARIABLES

echo "export PYTHON3_LIB_LOCATION=python3.8

export PYTHON3_INC_LOCATION=/usr/include/python3.8/

export ANTLR_LIB_LOCATION=ANTLR4runtime/run/usr/local/lib/libantlr4-runtime.so.4.8

export ANTLR_INC_LOCATION=ANTLR4runtime/run/usr/local/include/antlr4-runtime/

export QTERMWIDGET_LIB_LOCATION=qtermwidget/run/usr/local/lib/libqtermwidget5.so

export QTERMWIDGET_INC_LOCATION=qtermwidget/run/usr/local/include/qtermwidget5/" >> ~/.bashrc

. ~/.bashrc

# FETCH SUBMODULES 

git submodule update --init --recursive

# SETUP ANTLR

sudo apt update

sudo apt install uuid-dev

cd ANTLR4runtime

rm -rf build && rm -rf run

mkdir build && mkdir run && cd build

cmake ..

DESTDIR=../run make install

# # SETUP LXQT-BUILD-TOOLS

sudo apt-get install libglib2.0-dev

cd ../../lxqt-build-tools

rm -rf build && rm -rf run

mkdir build && mkdir run && cd build

cmake ..

DESTDIR=../run make install

# SETUP QTERMWIDGET

sudo apt-get install qttools5-dev

cd ../../qtermwidget 

sudo rm -rf build && sudo rm -rf run

mkdir build && mkdir run && cd build

cmake .. -DCMAKE_PREFIX_PATH=$PWD/../../lxqt-build-tools/run/usr/local/share/cmake/lxqt-build-tools

sudo DESTDIR=../run make install

# SETUP EXPRESSPYTHON 

cd ../../

rm -rf build && rm -rf run

mkdir build && mkdir run && cd build 

cmake ..

cmake --build .

cpack
