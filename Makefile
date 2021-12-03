all: *.c *.cpp *.h vendor/proj/*.cpp vendor/proj/*.h
	clang++ -std=c++11 -shared -o libwrapper.so vendor/proj/proj.cpp wrapper.cpp
	clang -o main main.c -lwrapper -L.
