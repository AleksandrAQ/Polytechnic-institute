module Globals
    implicit none
    REAL xx(21), yy(21)
    Real spl, rdd
end module Globals

program prog
   use Environment
   use Globals
   implicit none
   external SEVAL
   real SEVAL
   REAL FUN,A,B,RELERR,ABSERR,RES,ERREST,FLAG, analytics
   DATA A/-1.0/,B/1.0/,RELERR/1.E-06/,ABSERR/0.0/
   INTEGER i, iter, noFun
   REAL x, S
   REAL r(21), t(21), d(21), U
  
  
  
   DO iter = 0,20
      xx(iter+1) = -1 + iter * 0.1
      yy(iter+1) = 1/(1+25*xx(iter+1)**2.0)
   END DO
   write (*,*) 'y(x)=1/(1+25*x**2.0)'
   !аналитический метод( проинтегировали функцию и записали)
   analytics = (atan(5.0)*2)/5
   write (*,*) 'интеграл f(x):', analytics
   
   Res = 0.0
   CALL QUANC8(lagrange_interpolation,A,B,ABSERR,RELERR,RES,ERREST,noFun,FLAG)
   write (*,*) 'интеграл L(x):', RES
   !ну очевидно лагранж построен правильно, почему quanc8 выдает херню неизвестно
   !ниже строчкой проверяем и все ровно. Придется препода пинать, тут я бессилен
   write (*,*) 'проверка L(x):', lagrange_interpolation(1.0)

   CALL SPLINE(21,xx,yy,r,t,d)
   spl = 0.0
   ! rdd - это шаг между x(i-1) и x(i)
   rdd = 0.1
   do iter = 1,21
      spl =spl + yy(iter-1)*rdd+(r(iter)*rdd**2.0)/2.0+(t(iter)*rdd**3.0)/3.0+(d(iter)*rdd**4.0)/4.0
   end do
   write (*,*) 'интеграл S(x):', spl
   
   contains
   
   real function lagrange_interpolation(x) result(rt)

    use Globals
    implicit none
real x
integer :: j,k,iter
real p

rt = 0.0
do j=1,21
    p = 1.0
    do k=1,21
        if (k/=j) p = p * (x-xx(k)) / (xx(j)-xx(k))
    end do
    rt = rt + p*yy(j)
end do
return
end function lagrange_interpolation

end program prog
