#!/bin/bash
echo "Start shell script : <<< "

# rela tool-chains
sudo apt install git
sudo apt install gcc
sudo apt install g++
sudo apt install cmake
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install openssl
sudo apt install libssl-dev
sudo apt install zlib1g-dev
# to avoid drogon encounter NO DATABASE FOUND ,we install a kind of db 
sudo apt-get install libsqlite3-dev

# compile from source code
cd /home/ubuntu/code/c/web
git clone https://github.com/an-tao/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. 
make && sudo make install

echo ": End shell script . >>> "