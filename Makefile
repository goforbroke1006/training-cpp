BUILD_DIR=./.build

.PHONY: build test

all: build test

clear:
	rm -rf ${BUILD_DIR}

.ONESHELL:
build:
	cmake -G Ninja -S . -B "${BUILD_DIR}"
	cmake --build "${BUILD_DIR}" --target all

.ONESHELL:
test:
	cd "${BUILD_DIR}"
	ctest --build-generator=Ninja --verbose .

setup:
	bash ./install-build-tools.sh
	bash ./install-gtest.sh
