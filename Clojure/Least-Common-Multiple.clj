(ns Least-Common-Multiple)

;; Write a function which calculates the least common multiple. Your function should accept a variable number of positive integers or ratios.

(defn LCM [& arg]
  ((fn kpk [& data]
     (let [data-awal (nth data 0)
           data-baru (nth data 1)
           normal-data (flatten data-baru)
           x (vec normal-data)]
       (let [cek (for [i (range (dec (count x)))]
                   (if (= (x i) (x (inc i)))
                     true
                     false))
             terendah (apply min x)]
         (if (some #(= false %) cek)
           (kpk data-awal
                (for [i (range (count x))]
                  (if (= (x i) terendah)
                    (+ (x i) (nth data-awal i))
                    (x i))))
           (x 0)))))
   (vec arg) (vec arg)))

(comment
  (== (LCM 2 3) 6)
  (== (LCM 5 3 7) 105)
  (== (LCM 1/3 2/5) 2)
  (== (LCM 3/4 1/6) 3/2)
  (== (LCM 7 5/7 2 3/5) 210)
  )