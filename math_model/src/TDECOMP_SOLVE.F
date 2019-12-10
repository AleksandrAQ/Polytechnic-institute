C  œPO√PAMMA PEÿAET C»CTEM” »« TPEX À»HE…H€X
C  ”PABHEH»…, »CœOÀ‹«”ﬂ DECOMP » SOLVE
C
      REAL A(3,3),B(3),WORK(3),COND
      INTEGER NDIM/3/,N/3/,IPVT(3)
      DATA A/10.,-3., 5.,
     *       -7., 2.,-1.,
     *        0., 6., 5./
      DATA B/7.,4.,6./
      PRINT 101,((A(I,J),J=1,N),B(I),I=1,N)
C
      CALL DECOMP(NDIM,N,A,COND,IPVT,WORK)
C
      PRINT 102,COND
      CONDP1=COND+1.0
      IF(CONDP1.EQ.COND) PRINT 103
      IF(CONDP1.EQ.COND) STOP
C
      CALL SOLVE(NDIM,N,A,B,IPVT)
C
      PRINT 104,(B(I),I=1,N)
      STOP
  101 FORMAT(13X,'A',14X,'B',3(/5X,3F5.0,5X,F5.0))
  102 FORMAT(5X,'COND=',E12.5)
  103 FORMAT(5X,'MATP»÷A KÀACC»‘»÷»P”ETCﬂ KAK B€PO∆ƒEHHAﬂ')
  104 FORMAT(5X,'BEKTOP PEÿEH»ﬂ X',3(/12X,F10.7))
      END

C   B PE«”À‹TATE EE B€œOÀHEH»ﬂ ¡”ƒET œOÀ”◊EHO

C             A              B
C       10.  -7.   0.        7.
C       -3.   2.   6.        4.
C        5.  -1.   5.        6.
C     COND= 0.11207E+02
C     BEKTOP PEÿEH»ﬂ X
C             0.0
C            -1.0000000
C             1.0000000
