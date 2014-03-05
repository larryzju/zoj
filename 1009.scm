(use-modules (srfi srfi-1))

(define (get-reverse-mapping left right)
  (map cdr 
       (sort
	(map (lambda (x y) 
	       (cons y (- (char->integer y)
			  (char->integer x))))
	     (string->list left)
	     (string->list right))
	(lambda (x y) (char<? (car x) (car y))))))

(define (make-basic-string len)
  (let ((str (make-string len))
	(A-ascii (char->integer #\A)))
    (do ((i 0 (+ i 1)))
	((>= i len) str)
      (string-set! str i (integer->char (+ A-ascii i))))))

(define (generate-revese-proc len rotor1 rotor2 rotor3)
  (let* ((basic-str (make-basic-string len))
	 (reverse1 (get-reverse-mapping basic-str rotor1))
	 (reverse2 (get-reverse-mapping basic-str rotor2))
	 (reverse3 (get-reverse-mapping basic-str rotor3))
	 (A-ascii (char->integer #\A))
	 (a-ascii (char->integer #\a)))

    (lambda (output)
      (let ((output-in-index 
	     (map (lambda (c) 
		    (- (char->integer c) A-ascii))
		  (string->list output)))
	    (input '())
	    (step 0)
	    (step1 0)
	    (step2 0)
	    (step3 0))

	(for-each
	 (lambda (c) 
	   (set! input (cons 
			(fold (lambda (level step right)
				(modulo
				 (- right
				    (list-ref level (modulo (- right step) len)))
				 len))
			      c
			      (list reverse3 reverse2 reverse1)
			      (list step3 step2 step1))
			input))
	   (set! step (+ step 1))
	   (set! step1 (modulo step len))
	   (set! step2 (modulo (quotient step len) len))
	   (set! step3 (modulo (quotient step (* len len)) len)))
	 output-in-index)

	(list->string
	 (map (lambda (i) (integer->char (+ i a-ascii))) (reverse input)))))))

(let ((proc #f)
      (first #t))
  (do ((len (read) (read))
       (idx 1 (+ idx 1)))
      ((= len 0) (exit 0))
    (set! proc (generate-revese-proc len 
				     (symbol->string (read))
				     (symbol->string (read))
				     (symbol->string (read))))

    (cond ((not first) (newline))
	  (else (set! first #f)))

    (format #t "Enigma ~a:~%" idx)

    (let ((n (read)))
      (do ((i 0 (+ i 1)))
	  ((>= i n))
	(let ((str (symbol->string (read))))
	  (format #t "~a~%" (proc str)))))))
    
