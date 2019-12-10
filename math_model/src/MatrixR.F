      SUBROUTINE MatrixR(N,A, B, norma)
            INTEGER NDIM,N,IPVT(N),i,j,K
            REAL A(4,4),buf(4,4),B(4,4),E(4,4),WORK(4),con,condp1,R(4,4)
            REAL tmp, norma
            NDIM = N;
            norma = 0.
            buf = A
            R = 0
            
            CALL DECOMP(NDIM,N,A,con,IPVT,WORK)
            condp1=con+1.0
            write(*,*) "Число обусловленности:", con
            if(condp1.EQ.con) stop
            
            
            write(*,*) 'обратная'
            DO i = 1,N
                  CALL SOLVE(NDIM,N,A,B(i,1:4),IPVT)
                  write(*,*)B(i,1:4)
            END DO
            
            write(*,*) 'матрица R'
            do i=1,N
                  do j=1,N
                        do k=1,N
                              R(i,j) = R(i,j) + buf(k,i) * B(k,j)
                        end do
                        if (I .EQ. J) then
                            R(i,j) = R(i,j) - 1.
                        end if
                  end do
            end do
            DO I = 1,N
                  write(*,*)R(I,1:N)
            END DO
            DO J = 1, N
		  tmp=0;
                  DO i = 1, N
                        tmp=tmp+ABS(R(i,j));
                  end do
                  if (tmp>norma) then
                     norma=tmp;
                   end if
            end do
            write(*,*) 'норма ||R|| = ', norma
      END
