program exercise_5
   use Environment
   
   implicit none
   character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
   integer :: In=0, Out=0, Siz=0, Ins=0, RezArr(9), i=0, j=0, t=0
   integer, allocatable    :: Arr(:)

   open (file=input_file, newunit=In)
      read (In, *) Siz
      allocate (Arr(Siz))
      read (In, *) Arr
      read (In, *) Ins
   close (In)
   
   Arr(5) = Ins
   call sort(Arr)
   
   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "("//Siz//"(i0, 1x))") Arr
   close (Out)

contains
   pure subroutine sort(Arr)
   integer, intent(inout) :: Arr(:)
   integer :: i, j, Siz, t
   
   i = 0
   j = 0
   Siz = 10
   t = 0
   
   do i = Siz-1 ,1 ,-1
      do j = 1, i
         if (Arr(j).gt.Arr(j+1))then
            t = Arr(j)
            Arr(j) = Arr(j+1)
            Arr(j+1) = t
         end if
      end do
   end do

   end subroutine sort
end program exercise_5
