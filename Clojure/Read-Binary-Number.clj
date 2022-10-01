(ns Read-Binary-Number)

;; Convert a binary number, provided in the form of a string, to its numerical value.

(defn read-binary [x]
  (let [y (map #(- (int %) 48) (seq x))]
    (let [pangkat (fn [n]
                    (cond (= n 0) 1
                          (= n 1) 2
                          :else (reduce * (for [ii (range n)] 2))))]
      (let [dua-dipangkat (reverse (for [i (range (count y))]
                                     (pangkat i)))]
        (reduce + (map #(* %1 %2) y dua-dipangkat))))))

(comment
  (= 0     (read-binary "0"))
  (= 7     (read-binary "111"))
  (= 8     (read-binary "1000"))
  (= 9     (read-binary "1001"))
  (= 255   (read-binary "11111111"))
  (= 1365  (read-binary "10101010101"))
  (= 65535 (read-binary "1111111111111111"))
  )