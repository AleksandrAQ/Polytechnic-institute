! Copyright 2015 Fyodorov S. A

program reference_lab_1_1
   use Environment

   implicit none
   integer, parameter               :: STUD_AMOUNT = 5, SURNAME_LEN = 15, INITIALS_LEN = 5
   character(kind=CH_), parameter   :: MALE = Char(1052, CH_)

   character(:), allocatable  :: input_file, output_file, format

   character(SURNAME_LEN, kind=CH_)                :: tmpSurname = "", Surnames(STUD_AMOUNT) = ""
   character(INITIALS_LEN, kind=CH_)               :: tmpInitials = "", Initials(STUD_AMOUNT) = ""
   integer                                         :: tmpDate = 0, Date(STUD_AMOUNT) = 0

   integer :: In, Out, IO, i, j, id
   integer, parameter                              :: INDEXES(*) = [(i, i = 1, STUD_AMOUNT)]

   input_file = "../data/class.txt"
   output_file = "output.txt"
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! чтение из файла !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   ! Чтение списка класса: фамилии, инициалы, год.
   open (file=input_file, encoding=E_, newunit=In)
      format = '(2(a, 1x), i4)'
      read (In, format, iostat=IO) (Surnames(i), Initials(i), Date(i), i = 1, STUD_AMOUNT)
   close (In)

   Out = OUTPUT_UNIT
   open (Out, encoding=E_)
   select case(io)
      case(0)
      case(IOSTAT_END)
         write (Out, '(a)') "End of file has been reached while reading class list."
      case(1:)
         write (Out, '(a)') "Error while reading class list: ", io
      case default
         write (Out, '(a)') "Undetermined error has been reached while reading class list: ", io
   end select
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец чтения  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! вывод в фаил исходного списка !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   ! Вывод списка класса.
   open (file=output_file, encoding=E_, newunit=Out)
      write (out, '(a)') "Исходный список:"
      write (Out, format, iostat=IO) (Surnames(i), Initials(i), Date(i), i = 1, STUD_AMOUNT)
   close (Out)

   ! Обработка статуса записи.
   Out = OUTPUT_UNIT
   open (Out, encoding=E_)
   select case(io)
      case(0)
      case(IOSTAT_END)
         write (Out, '(a)') "End of file has been reached while writing class list."
      case(1:)
         write (Out, '(a)') "Error while writing class list: ", io
      case default
         write (Out, '(a)') "Undetermined error has been reached while writing class list: ", io
   end select
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец вывода !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Вывод первого по алфавиту!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tmpSurname = Surnames(1)
    do i = STUD_AMOUNT-1, 1 , -1
	if(Surnames(i)<tmpSurname)then
	    tmpSurname = Surnames(i)
	    id = i 
	end if
    end do

   open (file=output_file, encoding=E_, newunit=Out, position="append")
      write (out, '(a)') "Первый по алфавиту по алфавиту:"
      write (Out, format, iostat=IO) Surnames(id), Initials(id), Date(id)
   close (Out)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец первого по алфавиту !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Самый молодой            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tmpSurname = Surnames(1)
    do i = STUD_AMOUNT-1, 1 , -1
	if(Surnames(i)<tmpSurname)then
	    tmpSurname = Surnames(i)
	    id = i 
	end if
    end do

   open (file=output_file, encoding=E_, newunit=Out, position="append")
      write (out, '(a)') "Первый по алфавиту по алфавиту:"
      write (Out, format, iostat=IO) Surnames(id), Initials(id), Date(id)
   close (Out)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! конец Молодого            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

end program reference_lab_1_1
