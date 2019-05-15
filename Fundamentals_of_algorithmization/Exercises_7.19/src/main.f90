program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer :: In=0, Out=0, lines = 0, columns = 0, i = 0, j = 0,k=0
   integer :: S(10), t = 0, z = 0
   integer, allocatable    :: Arr(:,:)

   open (file=input_file, newunit=In)
      read (In, *) lines, columns
      allocate (Arr(columns, lines))
      read (In, *) Arr
   close (In)

   do concurrent (z=1:lines)
      do i = lines-1, 1 , -1
         do j = 1, i
            if(Arr(j,z).lt.Arr(j+1,z))then
               t = Arr(j,z)
               Arr(j,z) = Arr(j+1,z)
               Arr(j+1,z) = t
            end if
         end do
      end do
   end do
   
   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "("//columns//"(i0, 1x))") Arr
   close (Out)

!contains
!   pure subroutine sort(Arr)
!   integer, intent(inout) :: Arr(:)
   
!   end subroutine sort
end program exercise_5
