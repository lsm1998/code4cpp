# 安装conan依赖
SHELL = /bin/sh
CMAKE_DIR = ../cmake-build-debug
CONAN_DIR = $(shell pwd)

default_target: conan

conan:
	cd $(CMAKE_DIR) && conan install $(CONAN_DIR)/conanfile.txt
