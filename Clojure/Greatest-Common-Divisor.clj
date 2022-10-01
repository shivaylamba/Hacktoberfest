(ns Greatest-Common-Divisor)

;; Given two integers, write a function which returns the greatest common divisor.

(defn GCM [x y]
  (let [fpb (fn fpb [a b]
              (if (= b 0)
                a
                (fpb b (mod a b))))]
    (fpb x y)))

(comment
  (= (GCM 2 4) 2)
  (= (GCM 10 5) 5)
  (= (GCM 5 7) 1)
  (= (GCM 1023 858) 33)
  )