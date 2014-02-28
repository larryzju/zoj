(define (modify-confusing string)
  (let ((new-string
	 (string-map
	  (lambda (c)
	    (cond ((char=? c #\1) #\@)
		  ((char=? c #\0) #\%)
		  ((char=? c #\l) #\L)
		  ((char=? c #\O) #\o)
		  (else c)))
	  string)))
    new-string))

(define (solve n)
  (let ((match 0)
	(res '()))
    (do ((i 0 (+ i 1)))
	((>= i n))

      (let* ((username (read))
	     (password (symbol->string (read)))
	     (new-password (modify-confusing password)))
	(cond ((string=? password new-password))
	      (else
	       (set! match (+ 1 match))
	       (set! 
		res 
		(append res (list (format #f "~a ~a" username new-password))))))))

    (if (= match 0)
	(format #t "No account is modified.~%")
	(begin
	  (format #t "~a~%" match)
	  (do ((j 0 (+ 1 j))
	       (lst res (cdr lst)))
	      ((>= j match))
	    (format #t "~a~%" (car lst)))))))


(do ((cnt (read) (read)))
    ((= cnt 0))
  (solve cnt))

