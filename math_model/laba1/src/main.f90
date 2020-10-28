program prog
      use Environment
      implicit none
      INTEGER i, j, iter, IPVT(5)
      REAL A(5,5), norm, Z(3), con, WORK(5), E(5,5), R(5,5),buf(5,5), A_1(5,5), tmp
      Z = (/1.1, 1.001, 1.00001/)
   DO iter = 1, 3
      A = reshape( (/1.,1.,1.,1.,1. ,2.,0.,2.,2.,2., 3.,3.,0.,3.,3., 4.,4.,4.,0.,4., 5.,5.,5.,5.,0./), (/ 5,5/))
      
      E = 0
      DO i = 1, 5
          DO j = i, 5
              if(i == j) then
                  E(i, j) = 1
              end if
          END DO
      END DO

      A_1 = E

      DO  i = 2, 5
          DO j = 2, 5
              if (i .EQ. j) then
                  A(i,j) = 1 + Z(iter)
              end if
          END DO
      END DO
      write(*,*) 'ИСХОДНАЯ МАТРИЦА, A :', Z(iter)
      DO i = 1,5
          write(*,*)A(i,1:5)
      END DO
      
      buf = A
      CALL DECOMP(5,5,A,con,IPVT,WORK)
      write(*,*) 'Оценка обусловленности:', con
      write(*,*) "Обратная матрица:"
      DO i = 1,5
          CALL SOLVE(5,5,A,A_1(i,1:5),IPVT)
      END DO
      DO i = 1,5
          write(*,*) A_1(i,1:5)
      END DO
      write(*,*) "Матрица R:"
      R = MATMUL(buf,A_1) - E
      DO i = 1,5
          write(*,*) R(i,1:5)
      END DO

      DO i = 1, 5
        tmp=0;
        DO j = 1, 5
            tmp=tmp+ABS(R(i,j))
            if (tmp > norm) then
                norm = tmp
            end if
        end do
    end do
        write(*,*) "Норма ||R|| = ", norm


   END DO
end program prog
