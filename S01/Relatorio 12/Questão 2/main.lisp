(defun fatorial(n)
  (if (= n 0)
      1
      (* n (fatorial (- n 1)))
  )
)
(defparameter x (read))
(print (fatorial x))