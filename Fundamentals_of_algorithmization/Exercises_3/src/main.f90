program exercise_1 
   use Environment
   
   implicit none
   character(*), parameter    :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                    :: In = 0, Out = 0, Size = 0, i
   real(R_), allocatable      :: X(:), Y(:)
   real(R_)                   :: S = 0
   character(:), allocatable  :: fmt

   open (file=input_file, newunit=In)
      read (In, *) Size
      allocate (X(Size))
      read (In, *) X
      allocate (Y(Size))
      read (In, *) Y
   close (In)

   DO i = 1, 10
	write(*,*) X(i), Y(i)
   END DO

   S = dot_product(X, Y)
   
   
   open (file=output_file, encoding=E_, newunit=Out)
      fmt = "(a, f0.2)')"
      write (Out, fmt) "S = ", S
   close (Out)
end program exercise_1
