BUILD_DIR=./cmake-build-debug

.PHONY: build test

all: build test

clear:
	rm -rf ${BUILD_DIR}

build:
	cmake -S . -B "${BUILD_DIR}"
	cd "${BUILD_DIR}" && make all

test:
	"${BUILD_DIR}/tests/learn-cpp-tests"