EIGEN_INC = /nfs_home/nikhilh/eigen-3.3.9/
ifeq ($(EIGEN), 1)
EIGEN_INC = ./
endif
EIGEN_FLAGS = -std=gnu++11 -O3 -march=native

BLAS_FLAGS = -std=gnu++11 -O3 -march=native -lblas
BLAS_INC   = /usr/include/
BLAS_A     = /usr/lib/libblas/libblas.a

Entry:

bin/Eigen_test: src/Eigen_test.cpp
	mkdir -p bin/
	g++ -I$(EIGEN_INC) $(EIGEN_FLAGS) $^ -o $@
	bin/Eigen_test

bin/blas_test: src/blas_test.cpp
	mkdir -p bin/
	g++ $(BLAS_FLAGS) -I$(BLAS_INC) $^ -o $@ $(BLAS_A) 
	bin/blas_test

.PHONY: eigen clean test

test: bin/Eigen_test bin/blas_test

clean:
	rm -rf bin/
	rm -rf build/

eigen:
	wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
	tar -xf eigen-3.4.0.tar.gz
	cp -r eigen-3.4.0/Eigen/  ./
	rm eigen-3.4.0.tar.gz
	rm -rf eigen-3.4.0/