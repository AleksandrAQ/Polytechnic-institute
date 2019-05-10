program exercise_6
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0
   real(R_)                :: cosh_x = 0, x = 0

   open (file=input_file, newunit=In)
      read (In, *) x
   close (In)
   
   cosh_x = CoshXImp(x)

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, '(4(a, T16, "= ", e13.6/))') 'x', x, "CosH(x)", cosh_x, "Fortran CosH(x)", Cosh(x), "Error", cosh_x - Cosh(x)
   close (Out)

contains
   real(R_) pure function CoshXImp(x) result(Suma)
      real(R_), intent(in) :: x
      integer     k
      real(R_) ak

      ak = 1
      Suma = ak
      k = 1

      do while(abs(ak)>0.000000000000001)
         ak = ak*x*x/(2*k*(2*k-1))
         Suma = Suma + ak
         k = k + 1
      end do   
   end function CoshXImp      
end program exercise_6
