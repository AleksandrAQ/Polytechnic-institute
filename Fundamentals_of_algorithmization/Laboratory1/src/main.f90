program exercise_1 
   use Environment
   
   implicit none
   character(*), parameter    :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                    :: In = 0, Out = 0
   real(R_)                   :: a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, denom = 0, x1 = 0, x2 = 0, delta = 0, delta_1, delta_2
   character(:), allocatable  :: fmt

   open (file=input_file, newunit=In)
      read (In, *) a, b, c ,d, e, f
   close (In)

   open (file=output_file, encoding=E_, newunit=Out)
      fmt = "(a, T7, '=', f6.2)"
      write (Out, fmt) "a", a
      write (Out, fmt) "b", b
      write (Out, fmt) "c", c
      write (Out, fmt) "d", d
      write (Out, fmt) "e", e
      write (Out, fmt) "f", f
   close (Out)

   denom = a * e - d * b
    x1 = (-b * f + e * c)/denom
    x2 = (a * f- c * d)/denom
    delta = a * e - b * d ! не должна быть равна нулю
    delta_1 = (c * e - f * b)/delta
    delta_2 = (a * f - c * d)/delta
   open (file=output_file, encoding=E_, newunit=Out, position="append")
      write (Out, fmt)
      write (Out, fmt) "x1 =", x1
      write (Out, fmt) "x2 =", x2
      write (Out, fmt) "!=0 delta =", delta
      write (Out, fmt) "delta_1 =", delta_1
      write (Out, fmt) "delta_2 =", delta_2
   close (Out)
end program exercise_1
