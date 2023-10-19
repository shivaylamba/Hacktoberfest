
; THE MORAL IS THIS - WITNESS THE POWER OF RECURSION AND AN ELEGANT FORMULATION OF PROCESSES
;                     ALSO, RECURSION COMBINED WITH PATTERN MATCHING HAS RATHER POWERFUL EFFECTS
; 
; ALSO - PATTERN MATCHING DEFINES A PROGRAMMING LANGUAGE AND IS A PROGRAMMING PARADIGM (ESPECIALLY RECURSIVE PATTERN MATCHING), THOUGH IT HAS LIMITATIONS

(defun simplifier ()
  "An REPL loop for simplification"
  (interactive-interpreter 'simplifier> #'simplify-input))

(defun simplify-input (expr)
  "Sort of an adaptor"
  (prefix->infix (simplify (infix->prefix expr))))

(defun simplify (expr)
  "To ensure that simplification is performed bottom up"
  (if (atom expr)
	expr
	(simplify-expr (mapcar #'simplify expr))))


#|
To simplify an expression
	1) Check if there is an appropriate rule for it. If there is then first substitute and then simplify again
	2) Check if it can be evaluated 
	3) Return it as is
|#

(defun simplify-expr (expr)
  (cond ;((simplify-by-fn expr))
	    ((rule-based-translator
		   expr
		   *simplification-rules*
		   :rule-if #'expr-lhs
		   :rule-then #'expr-rhs
		   :transform
		   		(lambda (bindings response)
				  (simplify (sublis bindings response)))))
		((evaluable expr)
		 (eval expr))
		(t
		 expr)))

(defun simplify-by-fn (expr)
  "If there is a simplififying function, use it, and simplify what you've got"
  (let* ((fn (simp-fn (expr-op expr)))
		 (result (if fn (funcall fn expr))))
	(if result
	  (simplify result)
	  nil)))


(defun evaluable (expr)
  (and (every #'numberp (expr-args expr))
	   (or (member (expr-op expr) '(+ - / *))
		   (and (eq (expr-op expr) '^)
				(integerp (second (expr-args expr)))))))


; HANDLING INTEGRATION (this cannot be done by pattern matching)

#|
We want to factorize an expression
Factorizing an expression involves reducing it to a list of factors
Each factor may be optionally exponented
We also want the constant parts of an expression to be fully separated out from the factors

Assume that the current exponent factor is n, and the constant so far is c
	(Base Case)
	1) Number x    (c <- c * x ^ n)

	(Recursive Cases)
	2) Product     (call factor on each term of product)
	3) Quotient    (call factor on each term of quotient, but the lower term will have exponent factor -n)
	4) Negation    (call factor on the negated term, with the value of constant set to -c)
	5) Exponentation to power y  (call factor on the exponented term, with exponent factor n * y)
	
	(Remaining Cases)
	;; None we have completed the factorization, there is no more to do, we only now need to collect the factors
	(check if the expression is already there in the factors, 
		   If it is, then modify the exponent
		   If it isn't, then add a new term
|#



(defun factorize (expr)
  "Return a list of the factors of expr, each of the form y ^ n"
  (let ((factors nil)
		(constant 1))
	(labels 
	  ((fac (x n)
		 (cond ((numberp x) 
				(setf constant (* constant (expt x n))))
			   ((if-op-expr x '*)
				(fac (expr-lhs x) n)
				(fac (expr-rhs x) n))
			   ((if-op-expr x '/)
				(fac (expr-lhs x) n)
				(fac (expr-rhs x) (- n)))
			   ((and (if-op-expr x '-) (= (length (expr-args x)) 1))
				(setf constant (- constant))
				(fac (expr-lhs x) n))
			   ((and (if-op-expr x '^) (numberp (expr-rhs x)))
				(fac (expr-lhs x) (* n (expr-rhs x))))
			   (t
				(let ((factor (find x factors :key #'expr-lhs :test #'equal)))
				  (if factor
					(incf (expr-rhs factor) n)
					(push `(^ ,x ,n) factors)))))))
	  (fac expr 1)
	  (case constant
		(0 '((^ 0 1)))
		(1 factors)
		(t (cons `(^ ,constant 1) factors))))))

(defun unfactorize (factors)
  "Convert a list of factors back into prefix form"
  (cond ((null factors) 1)
		((= (length factors) 1) (first factors))
		(t `(* ,(first factors) ,(unfactorize (rest factors))))))

#| 
To divide two lists of factors
	1) First copy the all the factors in the numerator, since we are going to modify them
	2) Iterate through the factors in the denominator
			a) If you find the same factor in the numerator, reduce the exponent
			b) If you do not find it, then add this term to the numerator
	3) Delete all the factors which have an exponent of zero
|#

(defun divide-factors (numer denom)
  "Divide two lists of factors"
  (let ((result (mapcar #'copy-list numer)))
	(dolist (d denom)
	  (let ((factor (find (expr-lhs d) result :key #'expr-lhs :test #'equal)))
		(if factor
		  (decf (expr-rhs factor) (expr-rhs d))
		  (push `(^ ,(expr-lhs d) ,(- (expr-rhs d))) result))))
	(delete 0 result :key #'expr-rhs)))


(defun if-op-expr (expr op)
  (and (expr-p expr) (eq op (expr-op expr))))

#|
The process of converting an expression from infix to prefix
	(Base Case)
	1) If the expression is atomic, return it as is

	(Edge Case - To prevent unnecessary nesting)
	2) If the entire expression is contiained in a list, free it from the parenthesis

	(Recursive Case)
	3) Try to apply one of the rules. If you get a matching pattern, then 
		recursively apply conversion to the parts and then substitute

	(Strange Case) !!1

	(Invalid Case)
	4) Fail and print the we encountered an invalid expression
|#


(defun infix->prefix (expr)
  "Use only for fully parenthesized infix expressions !"
  (cond ((atom expr) 
		 expr)
		((and (listp expr) (= (length expr) 1))
		 (infix->prefix (first expr)))
		((rule-based-translator
			expr
			*infix->prefix-rules*
			:rule-if #'rule-pattern
			:rule-then #'rule-response
			:transform
				(lambda (bindings response)
				  (sublis (mapcar (lambda (binding)
									(cons (binding-var binding)
										  (infix->prefix (binding-val binding))))
								  bindings)
						  response))))
		((symbolp (first expr))
		 (list (first expr) (infix->prefix (rest expr))))
		(t
		 (error expr))))


(defun prefix->infix (expr)
  (if (atom expr)
	expr
	(mapcar #'prefix->infix
			(if (binary-expr-p expr)
				(list (expr-lhs expr) (expr-op expr) (expr-rhs expr))
				expr))))




; The structure of an expression

(defstruct (expr (:type list) (:constructor mkexpr (lhs op rhs)))
  "An expression is a binary operator with arguments"
  op lhs rhs)

(defun expr-p (x) 
  "Any pair will be recognized as an expression" 
  (consp x))

(defun expr-args (exp) 
  "The arguments are all but the first element of an expression"
  (rest exp))

(defun binary-expr-p (expr)
  "The expression has 2 arguments ?"
  (and (expr-p expr) (= 2 (length (expr-args expr)))))
							 

; The structure of a rule

(defstruct (rule (:type list))
  "A rule is a pattern mapped to a response"
  pattern response)






; FROM HERE BELOW, THE PATTERN MATCHER AND RULE BASED TRANSLATOR ARE DEFINED

; A general interpreter

(defun interactive-interpreter (prompt transformer &optional (display #'princ-freshline))
  "An abstracted REPL"
  (loop
	(handler-case
	  (progn
		(fresh-line)

		(if (or (symbolp prompt) (stringp prompt))
		  (print prompt)
		  (funcall prompt))

		(funcall display (funcall transformer (read))))

	  (error (condition) ; We ignore the error and return to the top
			 (format t "~&:: ERROR: ~a ignored. Back to top level." condition)))))


(defun princ-freshline (x)
  (fresh-line)
  (princ x))

(defun prompt-generator (&key (num 0) (control-str " ~&[~a] "))
  "Returns a function which will generate a prompt when called"
  (lambda () (format t control-str (incf num))))





; A macro component

(defun pat-match-macro (symbol expansion)
  (setf (get symbol 'pat-match-macro) expansion))

(defun expand-macros (pattern)
  (cond ((and (symbolp pattern) (get pattern 'pat-match-macro)))
		((atom pattern) pattern)
		(t (cons (expand-macros (first pattern))
				 (expand-macros (rest pattern))))))

(pat-match-macro 'x+ '(?+ x))
(pat-match-macro 'y+ '(?+ y))


(defun not-numberp (x)
  (not (numberp x)))

(pat-match-macro 'n  '(?is n numberp))
(pat-match-macro 'm  '(?is m numberp))
(pat-match-macro 's  '(?is s not-numberp))

; The rule based translator


(defun rule-based-translator
  (input rules &key (matcher #'pat-match) (transform #'sublis) (rule-if #'first) (rule-then #'rest))
  "A generalized version of the eliza matcher"

  (some (lambda (rule) 
		  (let ((result (funcall matcher (funcall rule-if rule) input)))
			(if (eq result fail)
			  nil
			  (funcall transform result (funcall rule-then rule)))))
		rules))



; The pattern matcher itself

(defconstant no-bindings '((t . t))
	"A constant denoting no bindings")

(defconstant fail nil
	"A constant denoting failure (Must be an atom)")

(defun pat-match (pattern input &optional (bindings no-bindings))
  "Match pattern to input in the context of bindings"
	  (cond ((eq bindings fail) fail)
			((variable-p pattern) (match-variable pattern input bindings))
			((eql pattern input) bindings)
			((single-pattern-p pattern) (single-matcher pattern input bindings))
			((segment-pattern-p pattern) (segment-matcher pattern input bindings))
			((and (consp pattern) (consp input))
			 (pat-match (rest pattern) (rest input) (pat-match (first pattern)
															   (first input)
															   bindings)))
			(t fail)))

; The variable component

(defun variable-p (var)
  (and (symbolp var)
	   (member var '(x y z m n o p q r s t u v w))))

(defun match-variable (var value bindings)
  (let ((prev-value (lookup var bindings)))
	(cond ((null prev-value) (extend-bindings var value bindings))
		  ((equal value prev-value) bindings)
		  (t fail))))


; The single-pattern component (In a data driven style, through property lists)

(defun single-pattern-p (pattern)
  (and (consp pattern)
	   (symbolp (first pattern))
	   (single-matcher-fn (first pattern))))

(defun single-matcher (pattern input bindings)
  (funcall (single-matcher-fn (first pattern))
		   (rest pattern) input bindings))

(defun single-matcher-fn (symb)
  (get symb 'single-pattern))

(defun match-and (clauses input bindings)
  (cond ((eq bindings fail) fail)
		((null clauses) bindings)
		(t (match-and (rest clauses) input (pat-match (first clauses) input bindings)))))

(defun match-or (clauses input bindings)
  (cond ((eq bindings fail) fail)
		((null clauses) fail)
		(t (let ((b2 (pat-match (first clauses) input bindings)))
			 (if (eq b2 fail)
			   (match-or (rest clauses) input bindings)
			   b2)))))

(defun match-is (var-pred input bindings)
	(let ((var (first var-pred))
		  (pred (second var-pred)))
	  (let ((b2 (match-variable var input bindings)))
		(cond ((eq b2 fail) fail)
			  ((funcall pred input) b2)
			  (t fail)))))

(defun match-not (clauses input bindings)
  "Not is only used to make checks, not set variables"
  (let ((b2 (match-or clauses input bindings)))
	(if (eq b2 fail)
	  bindings
	  fail)))


(setf (get '?is 'single-pattern) #'match-is)
(setf (get '?and 'single-pattern) #'match-and)
(setf (get '?or 'single-pattern) #'match-or)
(setf (get '?not 'single-pattern) #'match-not)


; The segment matcher component (Also in a data driven style)

(defun segment-pattern-p (pattern)
  (and (consp pattern)
	   (consp (first pattern))
	   (symbolp (first (first pattern)))
	   (segment-matcher-fn (first (first pattern)))))

(defun segment-matcher (pattern input bindings)
  (funcall (segment-matcher-fn (first (first pattern)))
		   pattern input bindings))

(defun segment-matcher-fn (symb)
  (get symb 'segment-pattern))




(defun match-segment (pattern input bindings &optional (start 0))
  (let ((var (second (first pattern)))
		(rest-pat (rest pattern)))
	(if (null rest-pat)
	  (match-variable var input bindings)
	  (let ((pos (find-first-match (first rest-pat) input start)))
		(if (null pos)
		  fail
		  (let ((b2 (pat-match rest-pat (subseq input pos) (match-variable var
																		   (subseq input 0 pos)
																		   bindings))))
			(if (eq b2 fail)
			  (match-segment pattern input bindings (+ start 1))
			  b2)))))))

(defun find-first-match (pattern input start)
  (cond ((and (atom pattern) (not (variable-p pattern)))
		 (position pattern input :start start :test #'equal))
		((< start (length input))
		 start)
		(t fail)))

(defun match-segment+ (pattern input bindings)
  (match-segment pattern input bindings 1))

(defun match-segment? (pattern input bindings)
  (let ((var (second (first pattern)))
		(rest-pat (rest pattern)))
	(or (pat-match (cons var rest-pat) input bindings)
		(pat-match rest-pat input bindings))))

(defun match-if (pattern input bindings)
  (and (progv 
		 (mapcar #'car bindings)
		 (mapcar #'cdr bindings)
		 (eval (second (first pattern))))
	   (pat-match (rest pattern) input bindings)))


		 
(setf (get '?* 'segment-pattern) #'match-segment)
(setf (get '?+ 'segment-pattern) #'match-segment+)
(setf (get '?? 'segment-pattern) #'match-segment?)
(setf (get '?if 'segment-pattern) #'match-if)

 



; Abstraction layer for the bindings data structure (implemented as association lists)

(defun get-binding (var bindings)
  (assoc var bindings))

(defun binding-val (binding)
  (cdr binding))

(defun binding-var (binding)
  (car binding))

(defun lookup (var bindings)
  (binding-val (get-binding var bindings)))

(defun extend-bindings (var value bindings)
  (cons (cons var value)
		(if (equal bindings no-bindings)
		  nil
		  bindings)))




; The rules that we will use for simplification


(defparameter *infix->prefix-rules* (mapcar #'expand-macros
  '(((x+ = y+)        (= x y))
	((- x+)           (- x))
	((+ x+)           (+ x))
	((x+ + y+)        (+ x y))
	((x+ - y+)        (- x y))
	((d y+ / d x)     (d y x))
	((Int y+ d x)     (Int y x))
	((x+ * y+)        (* x y))
	((x+ / y+)        (/ x y))
	((x+ ^ y+)        (^ x y)))))


(defun simp-rule (rule)
  "Convert a rule to prefix form and expand macros"
  (let ((expr (infix->prefix rule)))
	(mkexpr (expand-macros (expr-lhs expr))
			(expr-op expr)
			(expr-rhs expr))))



(defparameter *simplification-rules* 
  (mapcar #'simp-rule '(
	(x + 0 = x)
	(0 + x = x)
	(x + x = 2 * x)
	(x - 0 = x)
	(0 - x = - x)
	(x - x = 0)
	(- - x = x)

	(x * 1 = x)
	(1 * x = x)
	(x * 0 = 0)
	(0 * x = 0)
	(x * x = x ^ 2)

	(x / 0 = undefined)
	(0 / x = 0)
	(x / x = 1)

	(0 ^ 0 = undefined)
	(x ^ 0 = 1)
	(0 ^ x = 0)
	(x ^ 1 = x)
	(1 ^ x = 1)
	(x ^ -1 = 1 / x)
	
	(x * (y / x) = y)
	((y / x) * x = y)
	((x * y) / x = y)
	((y * x) / x = y)
	
	(x + - x = 0)
	((- x) + x = 0)
	(x + y - x = y)
	)))

(defun ^ (x y) "Exponentation" (expt x y))

(setf *simplification-rules*
  (append (mapcar #'simp-rule '(
			(s * n = n * s)
			(n * (m * x) = (n * m) * x)
			(x * (n * y) = n * (x * y))
			((n * x) * y = n * (x * y))

			(n + s = s + n)
			((x + n) + m = x + (n + m))
			((x + n) + y = (x + y) + n)
			(x + (y + n) = (x + y) + n)))
		  *simplification-rules*))


(setf *simplification-rules*
  (append *simplification-rules*
		  (mapcar #'simp-rule '(
			 (log 1                     = 0)
			 (log 0                     = undefined)
			 (log e                     = 1)
			 (sin 0                     = 0)
			 (sin pi                    = 0)
			 (cos 0                     = 1)
			 (cos pi                    = -1)
			 (sin(pi / 2)               = 1)
			 (cos(pi / 2)               = 0)
			 (log(e ^ x)                = x)
			 (e ^ (log x)               = x)
			 ((x ^ y) * (x ^ z)         = x ^ (y + z))
			 ((x ^ y) / (x ^ z)         = x ^ (y - z))
			 (log x + log y             = log(x * y))
			 (log x - log y             = log(x / y))
			 ((sin x) ^ 2 + (cos x) ^ 2 = 1)
			 ))))


(setf *simplification-rules*
  (append *simplification-rules* (mapcar #'simp-rule '(
	 (d x / d x                  =  1)
	 (d (u + v) / d x            = (d u / d x) + (d v / d x))
	 (d (u - v) / d x            = (d u / d x) - (d v / d x))
	 (d (- u) / d x              = - (d u / d x))
	 (d (u * v) / d x            = u * (d v / d x) + v * (d u / d x))
	 (d (u / v) / d x            = (v * (d u / d x) - u * (d v / d x)) / (v ^ 2))
	 (d (u ^ n) / d x            = n * u ^ (n - 1) * (d u / d x))
	 (d (u ^ v) / d x            = v * u ^ (v - 1)  * (d u / d x)
		                           + u ^ v * (log u) * (d v / d x))
	 (d (log u) / d x            = (d u / d x) / u)
	 (d (sin u) / d x            = (cos u) * (d u / d x))
	 (d (cos u) / d x            = - (sin u) * (d u / d x))
	 (d (e ^ u) / d x            = (e ^ u) * (d u / d x))
	 (d u / d x                  = 0)
	 ))))
		                            
		                        
