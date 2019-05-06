program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0
   integer, allocatable    :: Z(:)

   open (file=input_file, newunit=In)
      read (In, *) N
      allocate (Z(N))
      read (In, *) Z
   close (In)

   Z(2:N:2)=0

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "("//N//"(i0, 1x))") Z
   close (Out)
end program exercise_5
