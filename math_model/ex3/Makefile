FC=gfortran
FFLAGS=-Wall -std=f2008ts -fimplicit-none -Wno-maybe-uninitialized -Wno-unused-function -static-libgfortran -flto
FOPT=-O3 -ftree-vectorize -fopt-info-vec

all:
	$(FC) $(FFLAGS) -c src/environment.f90 -J obj/ -o obj/environment.o
	$(FC) $(FFLAGS) -c src/SPLINE.F -J obj/ -o obj/spline.o
	$(FC) $(FFLAGS) -c src/QUANC8.F -J obj/ -o obj/quanc8.o
	$(FC) $(FFLAGS) -c src/SEVAL.F -J obj/ -o obj/seval.o
	$(FC) $(FFLAGS) $(FOPT) -c src/main.f90 -I obj/ -o obj/main.o
	$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/environment.o ./obj/seval.o ./obj/quanc8.o ./obj/spline.o obj/main.o  
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
