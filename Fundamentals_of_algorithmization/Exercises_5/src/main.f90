program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer                 :: In = 0, Out = 0, N = 0, M = 0, i = 0
   integer                 :: S = 0
   integer, allocatable    :: Z(:)
   logical, allocatable    :: Pos(:)

   open (file=input_file, newunit=In)
      read (In, *) N
      allocate (Z(N))
      read (In, *) Z
   close (In)

    do i = 1, N
	 S = mod(Z(i),2) ! написать сечение и каждому элементу присвоить ноль
         If (S == 0) then
            Z(i)= 0
         end if
    end do

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "(i0)") N
      write (Out, "("//N//"(i0, 1x))") Z
   close (Out)

end program exercise_5
