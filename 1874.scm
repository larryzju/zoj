(define (count-carry x y)
  (let ((a (max x y))
	(b (min x y)))
    (do ((cnt 0)
	 (carry 0)
	 (a (max x y) (quotient a 10))
	 (b (min x y) (quotient b 10)))
	((= a 0) cnt)
      (set! carry 
	    (quotient 
	     (+ (modulo a 10) (modulo b 10) carry)
	     10))
      (if (> carry 0)
	  (set! cnt (+ 1 cnt))))))

(do ((x (read) (read))
     (y (read) (read)))
    ((and (= x 0) (= y 0)))
  
  (let ((c (count-carry x y)))
    (cond ((= c 0) (format #t "No carry operation.~%"))
	  ((= c 1) (format #t "~a carry operation.~%" c))
	  (else (format #t "~a carry operations.~%" c)))))
