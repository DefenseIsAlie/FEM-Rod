EIGEN = ./
EIGEN_FLAGS = -std=gnu++11 -O3 -march=native

Entry:

bin/test: src/main.cpp
	mkdir -p bin/
	g++ -I$(EIGEN) $(EIGEN_FLAGS) $^ -o $@

.PHONY: eigen clean

clean:
	rm -rf bin/
	rm -rf build/

eigen:
	wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
	tar -xf eigen-3.4.0.tar.gz
	cp -r eigen-3.4.0/Eigen/  ./
	rm eigen-3.4.0.tar.gz
	rm -rf eigen-3.4.0/