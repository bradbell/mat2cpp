c     standarad compliant wrapper to pass a char argument from c to fortran
c     (except assume fortran compiler supports >= 8 character identifiers)
      subroutine c2dpotrf(c_uplo, n, a, lda, info)
      integer c_uplo, info, lda, n
      double precision a(lda, *)
      call dpotrf(char(c_uplo), n, a, lda, info)
      return
      end
