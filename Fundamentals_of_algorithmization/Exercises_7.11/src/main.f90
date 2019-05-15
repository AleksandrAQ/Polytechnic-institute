program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer :: In=0, Out=0, lines = 0, columns = 0, S 
   integer :: K = 0, L = 0, ArrK(10), ArrL(10)
   integer, allocatable    :: Arr(:,:)

   open (file=input_file, newunit=In)
      read (In, *) K
      read (In, *) L
      read (In, *) lines, columns
      allocate (Arr(columns, lines))
      read (In, *) Arr
   close (In)

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "("//columns//"(i0, 1x))") Arr
   close (Out)

   ArrK = Arr(:,K)
   ArrL = Arr(:,L)
   S = DOT_PRODUCT(ArrK, ArrL)

   open (file = output_file, encoding=E_, newunit=Out, position="append")
      write (Out, "((i0, 1x))") S
   close (Out)

!contains
!   pure subroutine sort(Arr)
!   integer, intent(inout) :: Arr(:)
   
!   end subroutine sort
end program exercise_5
