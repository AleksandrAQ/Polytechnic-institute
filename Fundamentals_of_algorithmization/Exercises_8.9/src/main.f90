program exercise_5
   use Environment
   use Matrix_IO
   use Matrix_process

   implicit none
   !character(*), parameter :: input_file = "../data/input.txt", output_file = "output.txt"
    character(*), parameter :: input_matrix1 = "../data/matrix1.txt", &
   input_matrix2 = "../data/matrix2.txt", output_file = "output.txt"

   real(R_), allocatable    :: D(:,:), B(:,:), result(:,:)
    allocate(result(5,5))

    D = ReadMatrix(input_matrix1)
    B = ReadMatrix(input_matrix2)
    call Prod(B, D, result)

    call OutputMatrix(output_file, D)
    call OutputMatrix(output_file, B)
    call OutputMatrix(output_file, result)
end program exercise_5
