(define (palindrom-to-base? n base)
  (let ((lst '()))
    (do ((t n (quotient t base)))
	((= t 0))
      (set! lst (cons (modulo t base) lst)))
    (equal? lst (reverse lst))))

(define (palindrom n)
  (let ((lst '()))
    (do ((base 2 (+ 1 base)))
	((> base 16) lst)
      (if (palindrom-to-base? n base)
	  (set! lst (append lst (list base)))))))


(do ((in (read) (read)))
    ((= in 0))
  (let ((res (palindrom in)))
    (cond ((null? res)	(format #t "Number ~a is not a palindrom~%" in))
	  (else
	   (format #t "Number ~a is palindrom in basis" in)
	   (for-each (lambda (x) (format #t " ~a" x)) res)
	   (newline)))))

	    
