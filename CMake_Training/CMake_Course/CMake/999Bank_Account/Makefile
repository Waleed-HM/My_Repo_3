prepare:
	rm -rf ./build/
	mkdir build

debug_build: prepare
	cmake -S . -B ./build/ -DDEBUG_BUILD=ON
	cmake --build ./build/

release_build: prepare
	cmake -S . -B ./build/ -DDEBUG_BUILD=OFF
	cmake --build ./build/

