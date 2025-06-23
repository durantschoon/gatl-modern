# cpp/Makefile

all:
	cmake -S cpp -B build -DCMAKE_CXX_STANDARD=23
	cmake --build build

test: all
	./build/gatl_tests

clean:
	rm -rf build
