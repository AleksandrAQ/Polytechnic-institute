program exercise_1 
   use Environment
   
   implicit none
   character(*), parameter    :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                    :: In = 0, Out = 0
   real(R_)                   :: x = 0, y = 0
   character(:), allocatable  :: fmt

   open (file=input_file, newunit=In)
      read (In, *) x
   close (In)

   open (file=output_file, encoding=E_, newunit=Out)
      fmt = "(a, T7, '=', f6.2)"
      write (Out, fmt) "x", x
   close (Out)
    
!code
    if (x==0) then
	y = 0
    else if (x<0) then
	y = 1+SQRT(1+x*x)
    else if (x>0) then
	y = 1-SQRT(1+x*x)
    end if

!code

   open (file=output_file, encoding=E_, newunit=Out, position="append")
      write (Out, fmt)
      write (Out, fmt) "y =", y
   close (Out)
end program exercise_1
