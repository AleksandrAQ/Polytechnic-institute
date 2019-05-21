program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer :: In=0, Out=0, lines = 0, columns = 0, A(100)
   integer, allocatable    :: Arr(:,:)

   open (file=input_file, newunit=In)
      read (In, *) lines, columns
      allocate (Arr(columns, lines))
      read (In, *) Arr
   close (In)

   !A=RESHAPE(Arr, A)
  
   !A = RESHAPE( Arr, [1,99] )
   
   A = Arr.shape

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "("//columns//"(i0, 1x))") A
   close (Out)

!contains
!   pure subroutine sort(Arr)
!   integer, intent(inout) :: Arr(:)
   
!   end subroutine sort
end program exercise_5
