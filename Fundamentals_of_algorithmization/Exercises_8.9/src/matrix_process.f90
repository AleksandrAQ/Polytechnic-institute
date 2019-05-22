module Matrix_process
   use Environment
   
   implicit none
contains
   pure subroutine Prod(B, D, result)
   real(R_), intent(inout)  :: B(:, :)
   real(R_), intent(inout)  :: D(:,:), result(:,:)

   result = matmul(Transpose(D), B)

   end subroutine Prod
end module Matrix_process