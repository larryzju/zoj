(use-modules (ice-9 format))


(define (what-day-is-it month day year)

  (define (leap-year? year)
    (if (<= year 1752)
	(and (= (remainder year 4) 0) (not (= year 0)))
	(or (= (remainder year 400) 0)
	    (and (= (remainder year 4) 0)
		 (not (= (remainder year 100) 0))))))

  (define (leap-year2? year)
    (or (= (remainder year 400) 0)
	(and (= (remainder year 4) 0)
	     (not (= (remainder year 100) 0)))))


  (define (month-day-count year month)
    (let ((days #(0 31 28 31 30 31 30 31 31 30 31 30 31)))
      (if (and (leap-year? year) (= month 2))
	  29
	  (vector-ref days month))))

  (define (month-day-count2 year month)
    (let ((days #(0 31 28 31 30 31 30 31 31 30 31 30 31)))
      (if (and (leap-year2? year) (= month 2))
	  29
	  (vector-ref days month))))


  (define (date-valid? month day year)
    (if (and (= year 1752) (= month 9))
	(not (and (>= day 3) (<= day 13)))
	(and (> month 0)  (<= month 12)
	     (> day 0)    (<= day (month-day-count2 year month)))))

  
  (define (england-calender-before-gregorian? month day year)
    (cond ((< year 1752) #t)
	  ((> year 1752) #f)
	  (else
	   (cond ((< month 9) #t)
		 ((> month 9) #f)
		 (else
		  (cond ((< day 2) #t)
			((> day 2) #f)
			(else #t)))))))



  (define (days month day year)
    (let ((cnt 0))

      (do ((y 0 (+ 1 y)))
	  ((>= y year))
	(set! cnt (+ cnt (if (leap-year? y) 366 365))))

      (do ((m 1 (+ 1 m)))
	  ((>= m month))
	(set! cnt (+ cnt (month-day-count year m))))

      (set! cnt (+ cnt (- day 1)))

      cnt))


  (define (weekday month day year)
    ;; use 2000,1,2 as the basic ( Sunday )
    (let* ((base (days 1 2 2000))
	   (ask  (days month day year)))
      (if (england-calender-before-gregorian? month day year)
	  (modulo (- ask base 3) 7)
	  (modulo (- ask base) 7))))


  (define (month-name month)
    (let ((table #(invalid
		   January   February March	April	
		   May	     June     July  	August
		   September October  November	December)))
      (vector-ref table month)))

  (define (weekday-name weekday)
    (let ((table #(Sunday Monday Tuesday Wednesday 
			   Thursday Friday Saturday)))
      (vector-ref table weekday)))



  (define (output month day year weekday)
    (if (eq? weekday 'invalid)
  	(format #t "~a/~a/~a is an invalid date.~%" month day year)
  	(format #t "~a ~a, ~a is a ~a~%" 
  		(month-name month) day year (weekday-name weekday))))

  (if (date-valid? month day year)
      (output month day year (weekday month day year))
      (output month day year 'invalid)))

      

(let ((debug #f))
  (if debug
      (begin
	(what-day-is-it 1 1 2000)
	(what-day-is-it 1 2 2000))
      (begin
	(do ((m (read) (read))
	     (d (read) (read))
	     (y (read) (read)))
	    ((and (= m 0) (= d 0) (= y 0)) 0)
	  (what-day-is-it m d y)))))
