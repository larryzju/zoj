(define (read-input n)
  (let ((vec (make-vector n)))
    (do ((i 0 (+ i 1)))
        ((>= i n) (vector->list vec))
      (vector-set! vec i (read)))))

(define (stack-or-queue n)
  (let ((line1 (read-input n))
        (line2 (read-input n)))
    
    (cond ((equal? line1 line2)
           (if (equal? line1 (reverse line2))
               'both
               'queue))
          ((equal? line1 (reverse line2))
           'stack)
          (else 'neither))))


(let ((T (read)))
  (do ((i 0 (+ i 1)))
      ((>= i T))
    (format #t "~a~%" (stack-or-queue (read)))))

