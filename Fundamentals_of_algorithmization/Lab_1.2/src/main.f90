program reference_lab_1_1
   use Environment

   implicit none
   integer, parameter               :: STUD_AMOUNT = 5, SURNAME_LEN = 15, INITIALS_LEN = 5
   character(:), allocatable        :: input_file, output_file
   integer                          :: tmpDate = 0, Date(STUD_AMOUNT) = 0
   character(kind=CH_)  :: Surnames(STUD_AMOUNT, SURNAME_LEN)  = "", &
                           Initials(STUD_AMOUNT, INITIALS_LEN) = ""

   input_file = "../data/class.txt"
   output_file = "output.txt"

    call Read_class_list(input_file, Surnames, Initials, Date)
    call Output_class_list(output_file, Surnames, Initials, Date, "Исходный список:")
    
contains
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! чтение из файла !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine Read_class_list(Input_File, Surnames, Initials, Date)
    character(*)         Input_File
    character(kind=CH_)  Surnames(:, :), Initials(:, :)
    integer              Date(:)
    intent (in)          Input_File
    intent (out)         Surnames, Initials, Date
    integer In, IO, i
    character(:), allocatable  :: format

   ! Чтение списка класса: фамилии, инициалы, год.
   open (file=Input_file, encoding=E_, newunit=In)
      format = '(' // SURNAME_LEN // 'a1, 1x, ' // INITIALS_LEN // 'a1, 1x, i4)'
      read (In, format, iostat=IO) (Surnames(i, :), Initials(i, :), Date(i), i = 1, STUD_AMOUNT)
      call Handle_IO_status(IO, "reading class list")
   close (In)
end subroutine Read_class_list
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец чтения  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! вывод в фаил исходного списка !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine Output_class_list(Output_File, Surnames, Initials, Date, str)
    character(*)         Output_File, str
    character(kind=CH_)  Surnames(:,:), Initials(:,:)
    integer              Date(:)
    intent (in)          Output_File, Surnames, Initials, Date, str
    integer Out, IO, i
    character(:), allocatable  :: format
   ! Вывод списка класса.
   open (file=Output_file, encoding=E_, newunit=Out)
      write (out, '(a)') str
      format = '(' // SURNAME_LEN // 'a1, 1x, ' // INITIALS_LEN // 'a1, 1x, i4)'
      write (Out, format, iostat=IO) (Surnames(i,:), Initials(i,:), Date(i), i = 1, STUD_AMOUNT)
     call Handle_IO_status(IO, "writing ")
   close (Out)
end subroutine Output_class_list
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец вывода !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Вывод первого по алфавиту!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine first(Output_File, Surnames, Initials, Date, str)
!    tmpSurname = Surnames(1)
!    do i = STUD_AMOUNT-1, 1 , -1
!	if(Surnames(i)<tmpSurname)then
!	    tmpSurname = Surnames(i)
!	    id = i 
!	end if
!    end do

!   open (file=output_file, encoding=E_, newunit=Out, position="append")
!      write (out, '(a)') "Первый по алфавиту по алфавиту:"
!      write (Out, format, iostat=IO) Surnames(id), Initials(id), Date(id)
!   close (Out)
end subroutine first
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец первого по алфавиту !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Самый молодой            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!    tmpDate = Date(1)
!    do i = STUD_AMOUNT-1, 1 , -1
!	if(Date(i)>tmpDate)then
!	    tmpDate = Date(i)
!	    id = i
!	end if
!    end do

!  open (file=output_file, encoding=E_, newunit=Out, position="append")
!      write (out, '(a)') "Самый молодой:"
!      write (Out, format, iostat=IO) Surnames(id), Initials(id), Date(id)
!   close (Out)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец Молодого            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end program reference_lab_1_1
