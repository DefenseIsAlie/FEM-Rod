EIGEN = ./
EIGEN_FLAGS = -std=gnu++11 -O3 -march=native

Entry:

bin/Eigen_test: src/Eigen_test.cpp
	mkdir -p bin/
	g++ -I$(EIGEN) $(EIGEN_FLAGS) $^ -o $@
	bin/Eigen_test

.PHONY: eigen clean test

test: bin/Eigen_test

clean:
	rm -rf bin/
	rm -rf build/

eigen:
	wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
	tar -xf eigen-3.4.0.tar.gz
	cp -r eigen-3.4.0/Eigen/  ./
	rm eigen-3.4.0.tar.gz
	rm -rf eigen-3.4.0/