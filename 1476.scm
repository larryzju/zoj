(define (weird-clock initial times)
  (let ((flag   (make-vector 60 #f)))
    (do ((new initial (modulo (+ new (* times new)) 60))
	 (i   0       (+ i 1)))
	((or (= new 0) (vector-ref flag new))
	 (if (= new 0)
	     i
	     'Impossible))
      (vector-set! flag new #t))))



(do ((s (read) (read))
     (d (read) (read)))
    ((and (= s 0) (= d 0)))
  (format #t "~a~%" (weird-clock s d)))
