(define safe< <)
(define safe> >)

(define (square x)
  (* x x))

(define (solve a b R r)
  (let* ((A (max a b))
	 (B (min a b))
	 (L (+ R r)))
    (cond ((safe< B (* 2 (max R r))) #f)
	  (else
	   (safe> 
	    (+ (square (- A L))
	       (square (- B L)))
	    (square L))))))


(do ((a (read) (read)))
    ((eof-object? a))
  (if (solve a (read) (read) (read))
      (format #t "Yes~%")
      (format #t "No~%")))

