build:
	cmake -S . -B ./cmake-build-debug

test: build
	./cmake-build-debug/tests/learn-cpp-tests