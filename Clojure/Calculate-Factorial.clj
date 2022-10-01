(ns Calculate-Factorial)

;; Write a function which calculates factorials.

(defn calculate-factorial [x] (reduce * (for [i (range x)] (inc i))))

(comment
  (= (calculate-factorial 1) 1)
  (= (calculate-factorial 3) 6)
  (= (calculate-factorial 5) 120)
  (= (calculate-factorial 8) 40320)
  )