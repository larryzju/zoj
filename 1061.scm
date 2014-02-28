(define (make-stack)

  (define stack '())

  (define (dispatch op . arg)
    (case op
      ((push)   (set! stack (cons (car arg) stack)))
      ((empty?) (null? stack))
      ((size)   (length stack))
      ((show)   (display stack) (newline))
      ((look)   (if (not (null? stack))
		    (car stack)))
      ((clear)  (set! stack '()))
      ((pop)    (if (not (null? stack))
		    (let ((head (car stack)))
		      (set! stack (cdr stack))
		      head)))))

  dispatch)



(define (make-browser)

  (let ((forward  (make-stack))
	(backward (make-stack))
	(current  "http://www.acm.org/"))

    (define (go-backward)
      (cond ((backward 'empty?)  'Ignored)
	    (else
	     (forward 'push current) 
	     (set! current (backward 'pop))
	     current)))

    (define (go-forward)
      (cond ((forward 'empty?) 'Ignored)
	    (else
	     (backward 'push current)
	     (set! current (forward 'pop))
	     current)))

    (define (visit url)
      (backward 'push current)
      (set! current url)
      (forward  'clear)
      current)

    (define (dispatch)
      (case (read)
	((BACK)    (go-backward))
	((FORWARD) (go-forward))
	((VISIT)   (visit (read)))
	((QUIT)    'quit)))

    dispatch))


(let ((test-case-cnt (read)))
  (do ((i 0 (+ i 1)))
      ((>= i test-case-cnt))

    (if (> i 0) (newline))

    (let ((browser (make-browser)))
      (do ((res (browser) (browser)))
	  ((eq? res 'quit))
	(format #t "~a~%" res)))))
    



	
