program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer :: In=0, Out=0, lines = 0, columns = 0, A(100), i = 0, j = 0, cnt = 1
   integer, allocatable    :: Arr(:,:)

   open (file=input_file, newunit=In)
      read (In, *) lines, columns
      allocate (Arr(columns, lines))
      read (In, *) Arr
   close (In)

   !A = Arr(1,1:10)
   A = reshape(Arr(1:10,1:10),(/100/))
   
   !do i = 1, 10
	!do j = 1, 10
	!    A(cnt) = Arr(i,j)
	!    cnt = cnt + 1
	!end do
   !end do

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "((i0, 1x))") A
   close (Out)

!contains
!   pure subroutine sort(Arr)
!   integer, intent(inout) :: Arr(:)
   
!   end subroutine sort
end program exercise_5
