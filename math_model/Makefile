FC=gfortran
FFLAGS=-Wall -std=f2008ts -fimplicit-none -Wno-maybe-uninitialized -Wno-unused-function -static-libgfortran -flto
FOPT=-O3 -ftree-vectorize -fopt-info-vec

all:
	$(FC) $(FFLAGS) -c src/environment.f90 -J obj/ -o obj/environment.o
	$(FC) $(FFLAGS) -c src/DECOMP.F -J obj/ -o obj/decomp.o
	$(FC) $(FFLAGS) -c src/SOLVE.F -J obj/ -o obj/solve.o
	$(FC) $(FFLAGS) -c src/MatrixR.F -J obj/ -o obj/MatrixR.o
	$(FC) $(FFLAGS) $(FOPT) -c src/main.f90 -I obj/ -o obj/main.o
	$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/environment.o obj/main.o obj/decomp.o obj/solve.o obj/MatrixR.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
