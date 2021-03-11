"
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.cliki.net/Fibonacci
  http://cl-cookbook.sourceforge.net/hashes.html

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"

(defvar table (make-hash-table))
(defvar MODTHING 1000000000)

(defun fib (n)
  (if (gethash n table)
    (gethash n table)

    (if (< n 2) (setf (gethash n table) n)
    (if (oddp n) 
      (let ((k (/ (1+ n) 2)))
        (setf (gethash n table) (mod (+ (expt (fib k) 2) (expt (fib (1- k)) 2)) MODTHING)))
      (let* ((k (/ n 2)) (fk (fib k)))
        (setf (gethash n table) (mod (* (+ (* 2 (fib (1- k))) fk) fk) MODTHING)))))
  )
)


(let ((N (read)))
  (loop for x from 1 to N do
    (let ((a (read-from-string (concatenate 'string "(" (read-line) ")"))))
      (format t "~a ~a~%" (car a ) (fib (second a)))
    )
  )
)
