(use-modules (srfi srfi-1))

(define (puts obj)
  (display obj)
  (newline))

(define (kagome-kagome n front friends)
  (let* ((idx1 (list-index (lambda (x) (eq? front x)) friends))
         (idx2 (remainder (+ idx1 (/ n 2)) n)))
    (list-ref friends idx2)))


(define (read-list n)
  (let ((res (make-vector n "")))
    (do ((i 0 (+ i 1)))
        ((>= i n) (vector->list res))
      (vector-set! res i (read)))))

(let ((count (read)))
  (do ((c 0 (+ c 1)))
      ((>= c count))

    (let* ((n (read))
           (front (read))
           (friends (read-list n)))
      (puts (kagome-kagome n front friends)))))
