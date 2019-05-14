#!/usr/bin/env bash
touch $1.cpp

echo "/*************************************************************************"  > $1.cpp
echo "       File: $1.cpp" >> $1.cpp
echo "         By: navy" >> $1.cpp
echo "      Email: leiwei1990@gmail.com" >> $1.cpp
echo "Create Time: `(date '+%Y-%m-%d %H:%M:%S')`" >> $1.cpp

echo "" >> $1.cpp
echo "" >> $1.cpp
echo "" >> $1.cpp

echo "************************************************************************/" >> $1.cpp

echo "#include \"tools.h\"" >> $1.cpp
echo "" >> $1.cpp
echo "" >> $1.cpp
echo "" >> $1.cpp
echo "int main() {" >> $1.cpp
echo "" >> $1.cpp
echo "}" >> $1.cpp
