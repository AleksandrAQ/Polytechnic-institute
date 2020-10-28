      SUBROUTINE MatrixR(N,A, R, norma)
            INTEGER NDIM,N,IPVT(N),I,J,K, norma
            REAL A(4,4),AT(4,4),B(4,4),WORK(4),con,condp1,R(4,4)
            REAL tmp
            NDIM = N;
            norma = 0.
            AT = A
            CALL DECOMP(NDIM,N,A,con,IPVT,WORK)
            condp1=con+1.0
            write(*,*) "Число обусловленности:", con
            IF(condp1.EQ.con) write(*,*) 'MATPИЦA KЛACCИФИЦИPУ'
            IF(condp1.EQ.con) STOP
            write(*,*) 'ОБРАТНАЯ МАТРИЦА'
            A = reshape( (/0.,1., 0.,0., 0.,0.,1., 0., 0.,0.,0.,1.,0.,0.,0.,0./), (/ 4,4/))
            DO I = 1,N
                  CALL SOLVE(NDIM,N,A,B(I,1:4),IPVT)
                  write(*,*)B(I,1:4)
            END DO
c            !write(*,*) 'ВЫЧИСЛЕНИЕ МАТРИЦЫ R'
c            do i=1,N
c                  do j=1,N
c                        R(i,j) = 0
c                  end do
c            end do
c            do i=1,N
c                  do j=1,N
c                        do k=1,N
c                              R(i,j) = R(i,j) + AT(k,i) * B(k,j)
c                        end do
c                        R(i,j) = R(i,j) - E(i,j)
c                  end do
c            end do
c            DO I = 1,N
c                  !write(*,*)R(I,1:N)
c            END DO
      
c            !write(*,*) "ВЫЧИСЛЕНИЕ НОРМЫ МАТРИЦЫ R";
c            DO i = 1, N 
c                  TEMP=0;
c                  DO J = 1, N
c                        TEMP=TEMP+ABS(R(I,J));
c                        if (TEMP>NORM) THEN
c                              NORM=TEMP;
c                        END IF
c                  END DO
c            END DO
            
            !write(*,*) '||R|| = ', NORM
      END
