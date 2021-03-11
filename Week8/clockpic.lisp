"
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/1878907/the-smallest-difference-between-2-angles

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"

(defun readl ()
    (read-from-string (concatenate 'string "(" (read-line) ")"))
)

(defun diff (a1 a2)
    (abs (mod (+ (- a1 a2) 180000) (- 360000 180000)))
)


(let* ((N (read)) (c1 (make-array N)) (c2 (make-array N)))

    (dotimes (i N)
        (setf (aref c1 i) (read))
    )
    (dotimes (i N)
        (setf (aref c2 i) (read))
    )


    (loop for i from 0 below (1- N) do
        (if (not 
            (= 
                (diff (aref c1 i) (aref c1 (1+ i)))
                (diff (aref c2 i) (aref c2 (1+ i)))
            ))
        (progn (format t "~a~%" "impossible") (exit))
        NIL
        )
    )
    (format t "~a~%" "possible")
)