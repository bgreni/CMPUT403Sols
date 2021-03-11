"
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/40789987/iterate-through-a-list-and-check-each-element-with-your-own-condition

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"

(defvar table (make-hash-table :test 'equal ))

(defun hash-word (W)
    (declare (optimize speed))
    (loop for i from 0 to (length W) do
        (let ((splice (subseq W 0 i)))
            (setf (gethash splice table) (1+ (gethash splice table 0)))
        )
    )
)


(let* ((N (read)) (f (read-line)))
    (format t "~a~%" 0)
    (hash-word f)
    (loop for x from 2 to N do
        (let ((S1 (read-line)))
            (if (gethash S1 table)
                (format t "~a~%" (gethash S1 table))
                (format t "~a~%" 0)
            )
            (hash-word S1)
        )
    )
)